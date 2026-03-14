#include <bits/stdc++.h>
#define fl ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define lin signed main()
using namespace std;
void solve1() {
    int r = 5;
    double pi = 3.14;
    cout << fixed << setprecision(2) << (4 * (pi * pow(r, 3))) / 3 << '\n';
}
void solve2() {
    double cover = 24.95;
    double disc_price = cover * 0.6;
    double ship = 3 + (59 * 0.75);
    cout << (disc_price * 60) + ship << '\n';
}
void solve3() {
    int st = (6 * 3600) + (52 * 60);
    int easy = (8 * 68) + 15, tempo = (7 * 68) + 12;
    int tong = 2 * easy + 3 * tempo;
    int end = st + tong;
    cout << end / 3600 << ":" << (end % 3600) / 60 << '\n';
}
lin {
    fl;
    solve1();
    solve2();
    solve3();
}