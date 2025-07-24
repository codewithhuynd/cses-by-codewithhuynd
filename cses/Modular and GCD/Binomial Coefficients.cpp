#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll M = 1e9 + 7;            // Modulo value
const ll limit = 1e6;            // Maximum value for factorial precomputation

vector<ll> fact(limit + 1);     // fact[i] = i!
vector<ll> inv_fact(limit + 1); // inv_fact[i] = modular inverse of i!

// Approach 1: Recursive function to compute (a^b) % m using binary exponentiation
ll powmod(ll a, ll b, ll m) {
    if (a == 0 && b == 0) return 1; // Convention: 0^0 = 1
    if (b == 0) return 1;

    ll res = powmod(a, b / 2, m);

    if (b % 2 == 0) return (res * res) % m;
    else return ((res * res) % m * a) % m;
}

// Function to compute combination C(a, b) = a! / (b! * (a-b)!) % M
ll C(ll a, ll b) {
    if (b > a || b < 0) return 0;
    return ((fact[a] * inv_fact[b]) % M * inv_fact[a - b]) % M;
}

int main() {
    cin.tie(0)->sync_with_stdio(0); // Fast IO

    // Precompute factorials modulo M
    fact[0] = 1;
    for (int i = 1; i <= limit; i++) {
        fact[i] = (i * fact[i - 1]) % M;
    }

    // Compute inverse factorial using Fermat's Little Theorem:
    // inv_fact[n] = (fact[n])^(M-2) mod M
    inv_fact[limit] = powmod(fact[limit], M - 2, M);
    for (int i = limit - 1; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % M;
    }

    // Answer n queries
    int n;
    cin >> n;
    while (n--) {
        ll a, b;
        cin >> a >> b;
        cout << C(a, b) << "\n";
    }

    return 0;
}
