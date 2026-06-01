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
ll getH(ll i, ll j, vl &h, vl &p) {
    return (h[j] - h[i - 1] * p[j - i + 1] % mod + mod) % mod;
}
bool check(ll i, ll j, vl &h, vl &hR, vl &p) {
    int n = sz(h) - 1;
    return getH(i, j, h, p) == getH(n - j + 1, n - i + 1, hR, p);
}
void solve() {
    string s;
    cin >> s;
    int n = sz(s);
    vl h(n + 1), hR(n + 1), p(n + 1);
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        h[i] = (h[i - 1] * base + s[i - 1]) % mod;
        hR[i] = (hR[i - 1] * base + s[n - i]) % mod;
        p[i] = (p[i - 1] * base) % mod;
    }
    int mx = 1, st = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (check(i, j, h, hR, p) && j - i + 1 > mx) {
                mx = j - i + 1;
                st = i - 1;
            }
        }
    }
    cout << s.substr(st, mx);
}
lin {
    fl;
    solve();
}
