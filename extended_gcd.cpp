#include <iostream>
using namespace std;
int extendedGCD(int a, int b, int &s, int &t)
{
    if (b == 0)
    {
        s = 1;
        t = 0;
        return a;
    }

    int s1, t1;
    int gcd = extendedGCD(b, a % b, s1, t1);
    s = t1;
    t = s1 - (a / b) * t1;

    return gcd;
}

int main()
{
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    int s, t;
    int gcd = extendedGCD(a, b, s, t);

    cout << "GCD = " << gcd << endl;
    cout << "s = " << s << endl;
    cout << "t = " << t << endl;
    return 0;
}
