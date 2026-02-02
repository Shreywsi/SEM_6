#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(long long int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    long long int limit = sqrt(n);
    for (long long int i = 5; i <= limit; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
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
