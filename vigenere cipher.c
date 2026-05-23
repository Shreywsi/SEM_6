#include <iostream>
using namespace std;

int main() {
    string k,s, es = "",ds="";
    cout << "Enter string: ";
    cin >> s;
    cout<<"enter keyword";
    cin>> k;
    while(k.size() < s.size())
    {
        k += k;
    }
    for(int i = 0; i < s.size(); i++)
    {
        char ch=(s[i]-'a'+k[i]-'a')%26+'a';
        es+=ch;
    }
    for(int i=0;i<s.size();i++)
    {
        char ch=((es[i]-'a')-(k[i]-'a')+26)%26+'a';
        ds+=ch;
    }

    cout << "Encrypted string: " << es<<endl;
    cout << "decrypted string: " << ds;

    return 0;
}
