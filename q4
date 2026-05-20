#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(long long n)
{
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    if(n%3==0) return false;

    long long limit = sqrt(n);

    for (long long i = 3; i <= limit; i += 2)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}



int main() {
    long long int n;
    cout << "Enter the number: ";
    cin >> n;

    if (isPrime(n))
        cout << n << " is prime";
    else
        cout << n << " is not prime";

    return 0;
}
