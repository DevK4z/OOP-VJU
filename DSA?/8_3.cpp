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
void solve1() {
    int n, k; cin >> n >> k;
    vl a(n);
    for (auto &x : a) cin >> x;
    vl dp(k + 1, inf), t(k + 1, - 1);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = a[i]; j <= k; j++) {
            if (dp[j - a[i]] != inf && dp[j - a[i]] + 1 < dp[j]) {
                dp[j] = dp[j - a[i]] + 1;
                t[j] = i;
            }
        }
    }
    if (dp[k] == inf) {
        cout << "-1\n";
        return;
    }
    cout << dp[k] << '\n';
    // int cur = k;
    // vl cnt(n, 0);
    // while (cur > 0) {
    //     int idx = t[cur];
    //     cnt[idx]++;
    //     cur -= a[idx];
    // }
    // for (int i = 0; i < n; i++) cout << cnt[i] << (i == n - 1 ? "\n" : " ");
}
// void solve2() {
//     int n, k; cin >> n >> k;
//     vl a(n);
//     for (auto &x : a) cin >> x;
//     vector<ll> dp(k + 1, inf), t(k + 1, -1);
//     dp[0] = 0;
//     priority_queue<pii, vector<pii>, greater<pii>> pq;
//     pq.emplace(0, 0);
//     while (!pq.empty()) {
//         auto [cnt, sum] = pq.top();
//         pq.pop();
//         if (sum > k || cnt > dp[sum]) continue;
//         for (int i = 0; i < n; i++) {
//             int ns = s + a[i];
//             if (ns <= k && cnt + 1 < dp[ns]) {
//                 dp[ns] = cnt + 1;
//                 t[ns] = i;
//                 pq.emplace(dp[ns], ns);
//             }
//         }
//     }
//     if (dp[k] == inf) {
//         cout << "-1\n";
//         return;
//     }
//     cout << dp[k] << '\n';
//     int cur = k;
//     vl cnt(n, 0);
//     while (cur > 0) {
//         int idx = t[cur];
//         cnt[idx]++;
//         cur -= a[idx];
//     }
//     for (int i = 0; i < n; i++) cout << cnt[i] << (i == n - 1 ? "\n" : " ");
// }
lin {
    fl;
    solve1();
    //solve2();
}