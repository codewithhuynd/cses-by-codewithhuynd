#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll M = 1e9 + 7;                  // Modulo constant
ll limit = 1e6;                  // Upper limit for factorials

vector<ll> fact(limit + 1), inv_fact(limit + 1); // Precomputed factorials and inverse factorials

// Approach 1: Recursive binary exponentiation to compute (a^b) % m
ll powmod(ll a, ll b, ll m) {
    if (a == 0 && b == 0) return 1; // Define 0^0 as 1
    if (b == 0) return 1;

    ll res = powmod(a, b / 2, m);
    
    if (b % 2 == 0) return (res * res) % m;
    else return ((res * res) % m * a) % m;
}

int main() {
    cin.tie(0)->sync_with_stdio(0); // Fast I/O

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

    // Read the input string
    string input;
    cin >> input;

    vector<ll> cnt(26, 0);      // Count occurrences of each character (a-z)
    int n = input.size();

    for (char x : input) {
        cnt[x - 'a']++;
    }

    // Compute the number of distinct permutations:
    // result = n! / (freq['a']! * freq['b']! * ... * freq['z']!) % M
    ll res = fact[n];
    for (ll x : cnt) {
        res = (res * inv_fact[x]) % M;
    }

    cout << res;
}
