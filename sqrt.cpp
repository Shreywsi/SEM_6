#include <iostream>
using namespace std;

long long int sqrtLL(long long int n) {
    long long int low = 0, high = n, ans = 0;

    while (low <= high) {
        long long int mid = low + (high - low) / 2;

        if (mid * mid <= n) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;   // integer square root
}

int main() {
    long long int n;
    cin >> n;

    cout << sqrtLL(n);
    return 0;
}
