#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "";
    string key = "";

    cout << "enter the string: ";
    cin >> s;

    // uppercase
    for (int i = 0; i < s.size(); i++) {
        s[i] = toupper(s[i]);
    }

    // make even length
    if (s.size() % 2 != 0) {
        s += "X";
    }

    cout << "enter the keyword: ";
    cin >> key;

    vector<char> matrix;
    int used[26] = {0};

    // KEY
    for (char c : key) {
        c = toupper(c);
        if (c == 'J') c = 'I';

        if (!used[c - 'A']) {
            matrix.push_back(c);
            used[c - 'A'] = 1;
        }
    }

    // ALPHABET
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c == 'J') continue;

        if (!used[c - 'A']) {
            matrix.push_back(c);
            used[c - 'A'] = 1;
        }
    }

    // convert to 5x5 matrix
    char mat[5][5];
    int idx = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            mat[i][j] = matrix[idx++];
        }
    }

    // 🔥 BUILD POSITION MAP
    int pos[26][2];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            pos[mat[i][j] - 'A'][0] = i;
            pos[mat[i][j] - 'A'][1] = j;
        }
    }

    // 🔐 ENCRYPTION
    string cipher = "";

    for (int i = 0; i < s.size(); i += 2) {

        char a = s[i];
        char b = s[i + 1];

        if (a == 'J') a = 'I';
        if (b == 'J') b = 'I';

        int r1 = pos[a - 'A'][0], c1 = pos[a - 'A'][1];
        int r2 = pos[b - 'A'][0], c2 = pos[b - 'A'][1];

        // SAME ROW
        if (r1 == r2) {
            cipher += mat[r1][(c1 + 1) % 5];
            cipher += mat[r2][(c2 + 1) % 5];
        }

        // SAME COLUMN
        else if (c1 == c2) {
            cipher += mat[(r1 + 1) % 5][c1];
            cipher += mat[(r2 + 1) % 5][c2];
        }

        // RECTANGLE
        else {
            cipher += mat[r1][c2];
            cipher += mat[r2][c1];
        }
    }

    cout << "Cipher Text: " << cipher << endl;

    return 0;
}
