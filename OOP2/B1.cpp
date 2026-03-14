#include <bits/stdc++.h>
#define fl ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define lin signed main()
using namespace std;
lin {
    fl;
    int sec = 42 * 60 + 42;
    cout << sec;
    double miles = 10 / 1.61;
    cout << fixed << setprecision(2) << miles;
    double secpm = sec / miles;
    int mn_pace = (int)secpm / 60, mn_sec = (int)secpm % 60;
    double hours = sec / 3600.0;
    double avg_mph = miles / hours;
    cout << mn_pace << " " << mn_sec << '\n';
    cout << avg_mph;
}