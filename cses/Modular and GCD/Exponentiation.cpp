#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll M = 1e9 + 7;

//Approach 1: Recursive function to compute (a^b) % m using binary exponentiation
ll powmod1(ll a, ll b, ll m) {
    if (a == 0 && b == 0) return 1;     // Convention: 0^0 = 1
    if (b == 0) return 1;
    
    ll res = powmod1(a, b / 2, m);
    
    if(b % 2 == 0) return (res * res) % m;
    else return ((res * res) % m * a) % m;
}

//Approach 2: Iterative version of binary exponentiation: computes (a^b) % m
ll powmod2(ll a, ll b, ll m) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) res = (res * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    while (n--) {
        ll a, b;
        cin >> a >> b;
        cout << powmod1(a, b, M) << "\n";  // You can replace with powmod2 if desired
    }

    return 0;
}
