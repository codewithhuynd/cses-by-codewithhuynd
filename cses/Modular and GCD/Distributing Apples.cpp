#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll M = 1e9 + 7;                      // Modulo value (a large prime)
ll limit = 2 * 1e6;                  // Limit for precomputing factorials

vector<ll> fact(limit + 1), inv_fact(limit + 1); // fact[i] = i!, inv_fact[i] = (i!)^(-1) mod M

// Approach 1: Recursive function to compute (a^b) % m using binary exponentiation
ll powmod(ll a, ll b, ll m) {
    if (a == 0 && b == 0) return 1;     // Convention: 0^0 = 1
    if (b == 0) return 1;

    ll res = powmod(a, b / 2, m);

    if (b % 2 == 0) return (res * res) % m;
    else return ((res * res) % m * a) % m;
}

// Function to compute C(a, b) = a! / (b! * (a - b)!) mod M
ll C(ll a, ll b) {
    if (b > a || b < 0) return 0;
    return ((fact[a] * inv_fact[b]) % M * inv_fact[a - b]) % M;
}

int main() {
    cin.tie(0)->sync_with_stdio(0); // Fast input-output

    // Precompute factorials modulo M
    fact[0] = 1;
    for (int i = 1; i <= limit; i++) {
        fact[i] = (i * fact[i - 1]) % M;
    }

    // Compute inverse factorials using Fermat's Little Theorem
    inv_fact[limit] = powmod(fact[limit], M - 2, M);
    for (int i = limit - 1; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % M;
    }

    // Read input and compute the result
    ll a, b;
    cin >> a >> b;

    // Output the number of multisets (combinations with repetition):
    // C(a + b - 1, b)
    cout << C(a + b - 1, b);

    return 0;
}
