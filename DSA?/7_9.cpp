#include <bits/stdc++.h>
#define fl ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define lin signed main()
#define fi first
#define se second
#define ld long double
#define pii pair<fint, fint>
#define pll pair<long long, long long>
#define vl vector<ll>
#define vvl vector<vl>
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)x.size())
#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef int_fast64_t fint;
const ll maxN = 30, lim = 1e7 + 7, mod = 1e9 + 7, N = 2e5 + 5, base = 131, inf = (1ULL << 62);
ll p[lim + 1];
void sieve() {
    fill (p, p + lim + 1, 1);
    p[0] = p[1] = 0;
    for (ll i = 2; i * i <= lim; i++) 
        if (p[i])
            for (ll j = i * i; j <= lim; j += i) p[j] = 0;
}
void solve() {
    sieve();
    ll n;
    cin >> n;
    cout << (p[n] ? "prime" : "not prime");
}
lin {
    fl;
    solve();
}