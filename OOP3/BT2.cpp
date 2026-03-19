#include <bits/stdc++.h>
#define fl ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define lin signed main()
using namespace std;
class sieunhan { 
    private :
        string ten, vukhi, mausac;
    public :
        sieunhan(string ten, string vukhi, string mausac) : ten(ten), vukhi(vukhi), mausac(mausac) {}
        void output() {
            cout << "Ten: " << ten << " | Vu khi: " << vukhi << " | Mau sac: " << mausac << "\n";
        }
};
lin {
    fl;
    sieunhan sn1("Gao", "Sức mạnh siêu phàm", "Đỏ");
    sieunhan sn2("Điện quang", "Trí tuệ và kỹ năng chiến đấu", "Vàng");
    sn1.output();
    sn2.output();
}