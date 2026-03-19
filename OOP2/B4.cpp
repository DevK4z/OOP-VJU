#include <bits/stdc++.h>
#define fl ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define lin signed main()
using namespace std;
lin {
    fl;
    time_t now = time(0); // Lấy thời điểm hiện tại
    tm *ltm = localtime(&now); // Chuyển đổi sang giờ địa
    // In ra giờ hiện tại
    cout << "Time: "<< ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << '\n';
    // Số giây từ epoch (UTC), rồi đổi ra số ngày
    long long seconds_since_epoch = now; // time(0) trả về số giây từ epoch
    long long days_since_epoch = seconds_since_epoch / 86400; // 1 ngày = 86400 giây
    cout << "Days since epoch: " << days_since_epoch << '\n';
}