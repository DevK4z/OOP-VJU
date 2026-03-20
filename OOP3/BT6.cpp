#include <bits/stdc++.h>
#define fl ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define lin signed main()
using namespace std;
class nhanvien {
    private :
        string ten;
        double luongcoban, hesoluong;
    public :
        static constexpr double LUONG_MAX = 500000000.0;
        nhanvien(string ten = "", double lcb = 0, double hsl = 0) : ten(ten), luongcoban(lcb), hesoluong(hsl) {}
        string getTen() { return ten; }
        double getLuongCoBan() { return luongcoban; }
        double getHeSoLuong() { return hesoluong; }
        void setTen(string t) { ten = t; }
        void setLuongCoBan(double lcb) { luongcoban = lcb; }
        void setHeSoLuong(double hsl) { hesoluong = hsl; }
        double tinhluong() {
            return luongcoban * hesoluong;
        }
        void inTTin() {
            cout << "Ten: " << ten << "\nLuong co ban: " << luongcoban << "\nHe so luong: " << hesoluong << "\nLuong: " << tinhluong() << "\n";
        }
        bool tangluong(double delta) {
            if (delta <= 0) {
            cout << "Delta phai > 0!\n";
            return false;
        }
        double luongHienTai = tinhluong();
        double luongMoi = luongHienTai + delta;
        if (luongMoi > LUONG_MAX) {
            cout << "Khong the tang luong! Luong moi vuot LUONG_MAX (" << fixed << setprecision(0) << LUONG_MAX << ").\n";
            return false;
        }
        // Giữ nguyên heSoLuong, điều chỉnh luongCoBan theo lương mới
        luongcoban = luongMoi / hesoluong;
        cout << "Tang luong thanh cong. Luong moi: " << fixed << setprecision(0) << tinhluong() << "\n";
        return true;
        }
};
lin {
    fl;
    nhanvien nv("KT", 1000000, 2.5);
    nv.inTTin();
    cout << "\n=== TANG LUONG ===\n";
    nv.tangluong(2000000); // Tang 2 trieu
    cout << "\n=== THONG TIN SAU KHI TANG LUONG ===\n";
    nv.inTTin();
}