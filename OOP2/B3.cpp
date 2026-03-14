#include <bits/stdc++.h>
#define fl ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define lin signed main()
using namespace std;
void ngang(int n) {
    for (int i = 0; i < n; i++) cout << "+ - - - - ";
    cout << "+\n";
}
void doc(int n) {
    for(int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) cout << "|         ";
    cout << "|\n";
    }
}
void luoi(int n, int m) {
    for (int i = 0; i < n; i++) ngang(m), doc(m);
    ngang(m);
}
lin {
    fl;
    cout << "2x2\n";
    luoi(2,2);
    cout << "4x4\n";
    luoi(4,4);
}