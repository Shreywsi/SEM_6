#include <bits/stdc++.h>
using namespace std;

char mat[5][5];
int pos[26][2];

void buildMatrix(string key)
{
    vector<char> matrix;
    int used[26] = {0};

    // KEY
    for (char c : key)
    {
        c = toupper(c);
        if (c == 'J') c = 'I';

        if (!used[c - 'A'])
        {
            matrix.push_back(c);
            used[c - 'A'] = 1;
        }
    }

    // ALPHABET
    for (char c = 'A'; c <= 'Z'; c++)
    {
        if (c == 'J') continue;

        if (!used[c - 'A'])
        {
            matrix.push_back(c);
            used[c - 'A'] = 1;
        }
    }

    // fill matrix
    int idx = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            mat[i][j] = matrix[idx++];

    // position map
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            pos[mat[i][j] - 'A'][0] = i,
            pos[mat[i][j] - 'A'][1] = j;
}

// 🔐 ENCRYPT (PRINTS DIRECTLY)
void enc(string s)
{
    cout << "Cipher Text: ";

    for (int i = 0; i < s.size(); i += 2)
    {
        char a = s[i], b = s[i + 1];

        if (a == 'J') a = 'I';
        if (b == 'J') b = 'I';

        int r1 = pos[a - 'A'][0], c1 = pos[a - 'A'][1];
        int r2 = pos[b - 'A'][0], c2 = pos[b - 'A'][1];

        if (r1 == r2)
        {
            cout << mat[r1][(c1 + 1) % 5];
            cout << mat[r2][(c2 + 1) % 5];
        }
        else if (c1 == c2)
        {
            cout << mat[(r1 + 1) % 5][c1];
            cout << mat[(r2 + 1) % 5][c2];
        }
        else
        {
            cout << mat[r1][c2];
            cout << mat[r2][c1];
        }
    }

    cout << endl;
}

// 🔓 DECRYPT (PRINTS DIRECTLY)
void dec(string s)
{
    cout << "Plain Text: ";

    for (int i = 0; i < s.size(); i += 2)
    {
        char a = s[i], b = s[i + 1];

        int r1 = pos[a - 'A'][0], c1 = pos[a - 'A'][1];
        int r2 = pos[b - 'A'][0], c2 = pos[b - 'A'][1];

        if (r1 == r2)
        {
            cout << mat[r1][(c1 + 4) % 5];
            cout << mat[r2][(c2 + 4) % 5];
        }
        else if (c1 == c2)
        {
            cout << mat[(r1 + 4) % 5][c1];
            cout << mat[(r2 + 4) % 5][c2];
        }
        else
        {
            cout << mat[r1][c2];
            cout << mat[r2][c1];
        }
    }

    cout << endl;
}
