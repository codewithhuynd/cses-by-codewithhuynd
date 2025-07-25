#include <bits/stdc++.h>
using namespace std;

long long M = 1e9 + 7;

int main() {
    long long n;
    cin >> n;

    long long d = 1;
    long long res = 0;

    // Iterate through each group of divisors
    while (d <= n) {
        long long k = n / d;
        long long l = (n / (k + 1)) + 1;
        long long r = n / k;

        // Number of elements in the range [l, r]
        long long a = r - l + 1;

        // Sum of the arithmetic sequence l + (l+1) + ... + r
        long long b = (r % M + l % M) % M;
        long long c = (a % M * b % M) % M;
        c = (c * ((M + 1) / 2)) % M; // divide by 2 modulo M

        // Add to the result: k * sum(l..r)
        long long sum = (k % M * c % M) % M;
        res = (res % M + sum % M) % M;

        d = r + 1;
    }

    cout << res;
    return 0;
}
