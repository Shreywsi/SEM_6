#include <iostream>
using namespace std;
char m[5][5];
void findPos(char c, int &row, int &col, char m[5][5])
{
    if(c == 'J') c = 'I';
    for(row = 0; row < 5; row++)
        for(col = 0; col < 5; col++)
            if(m[row][col] == c)
                return;
}
int main()
{
    string pt="";
    string k="";
    cout<<"enter the plain text in caps";
    cin>> pt;
    cout<<"enter the keyword";
    cin>>k;
    for (int i = 0; i < k.size(); i++)
        k[i] = toupper(k[i]);
    int l=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
           if (l < k.size())
                m[i][j] = k[l++];   
            else
                m[i][j] = 'X';  
        }
    }
    //formation of matrix
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(m[i][j] != 'X')
                continue;
            else
            {
                for(char l='A'; l<='Z'; l++)
                {
                    bool found = false;
                    for(int x=0; x<k.size(); x++)
                    {
                        if(k[x] == l)
                        {
                            found = true;
                            break;
                        }
                    }
                    if(!found && l!='J')
                    {
                        m[i][j] = l;
                        k += l;  
                        break;    
                    }
                }
            }
        }
    }
// prepare plaintext
    string p = "";
    for(int i = 0; i < pt.size(); i++)
    {
        char c = toupper(pt[i]);
        if(c == 'J') c = 'I';
        p += c;
    }

// make pairs
string newpt = "";
for(int i = 0; i < p.size(); i += 2)
{
    char a = p[i];
    char b;

    if(i+1 < p.size())
        b = p[i+1];
    else
        b = 'X';  // if last char is single, add X

    if(a == b)      // same letters in a pair
    {
        newpt += a;
        newpt += 'X';
        i--;        // stay on b for next pair
    }
    else
    {
        newpt += a;
        newpt += b;
    }
}
//encryption
string ciphertext = "";
for(int i = 0; i < newpt.size(); i += 2)
{
    char a = newpt[i];
    char b = newpt[i+1];

    int r1, c1, r2, c2;
    findPos(a, r1, c1, m);
    findPos(b, r2, c2, m);

    if(r1 == r2)
        ciphertext += m[r1][(c1 + 1) % 5], ciphertext += m[r2][(c2 + 1) % 5];
    else if(c1 == c2)
        ciphertext += m[(r1 + 1) % 5][c1], ciphertext += m[(r2 + 1) % 5][c2];
    else
        ciphertext += m[r1][c2], ciphertext += m[r2][c1];
}

cout << "\nEncrypted text: " << ciphertext << endl;
cout << endl;

//decryption
cout << "\nDecrypted text: ";
for(int i = 0; i < ciphertext.size(); i += 2)
{
    char a = ciphertext[i];
    char b = ciphertext[i+1];

    int r1, c1, r2, c2;
    findPos(a, r1, c1, m);
    findPos(b, r2, c2, m);

    if(r1 == r2) // same row → shift left
    {
        cout << m[r1][(c1 + 4) % 5] << m[r2][(c2 + 4) % 5];
        
    }
    else if(c1 == c2) // same column → shift up
    {
        cout << m[(r1 + 4) % 5][c1] << m[(r2 + 4) % 5][c2];
    }
    else // rectangle → swap columns
    {
        cout << m[r1][c2] << m[r2][c1];
    }
}
cout << endl;
    return 0;

}