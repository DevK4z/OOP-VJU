#include <bits/stdc++.h>
#define fl ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define lin signed main()
using namespace std;
class nhanvien {
    private :
        string ten;
        double luongcoban, hesoluong;
    public :
        static constexpr double LUONG_MAX = 500000000.0; // constexpr cho phép sử dụng trong biểu thức hằng số
        nhanvien(string ten = "", double lcb = 0, double hsl = 0) : ten(ten), luongcoban(lcb), hesoluong(hsl) {}
        // Getter
        string getTen() { return ten; } 
        double getLuongCoBan() { return luongcoban; }
        double getHeSoLuong() { return hesoluong; }
        // Setter
        void setTen(string t) { ten = t; }
        void setLuongCoBan(double lcb) { luongcoban = lcb; }
        void setHeSoLuong(double hsl) { hesoluong = hsl; }
        double tinhluong() {
            return luongcoban * hesoluong;
        }
        bool tangluong (double delta) {
            double hsmoi = hesoluong + delta;
            double luongmoi = luongcoban * hsmoi;
            if (luongmoi > LUONG_MAX) cout << "Khong the tang luong! Luong moi vuot LUONG_MAX (" << fixed << setprecision(0) << LUONG_MAX << ").\n";
            hesoluong = hsmoi;
            return luongmoi <= LUONG_MAX;
        }
        void inTTin() {
            cout << "Ten: " << ten << "\nLuong co ban: " << luongcoban << "\nHe so luong: " << hesoluong << "\nLuong: " << tinhluong() << "\n";
        }
};
lin { 
    fl;
    nhanvien nv("KT", 1000000, 2.5);
    nv.inTTin();
    cout << "\n=== TANG LUONG ===\n";
    nv.tangluong(2.0); // Tang 2 he so luong
    cout << "\n=== THONG TIN SAU KHI TANG LUONG ===\n";
    nv.inTTin();
}