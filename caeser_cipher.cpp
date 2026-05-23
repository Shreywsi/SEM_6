#include <iostream>
using namespace std;

int main() {

    string s, es = "",ds="";

    cout << "Enter string: ";
    cin >> s;

    for(int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        ch = ((ch - 'a' + 3) % 26) + 'a';

        es += ch;
    }
    for(int i=0;i<s.size();i++)
    {
        char ch=es[i];
        ch=((ch-'a'-3+26)%26)+'a';
        ds+=ch;
    }

    cout << "Encrypted string: " << es<<endl;
    cout << "decrypted string: " << ds;

    return 0;
}
