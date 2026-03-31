#include <bits/stdc++.h>
#define fl ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define lin signed main()
using namespace std;
class HangHoa {
    private:
        string maHang, tenHang, nhaSX;
        double gia;
    public:
        HangHoa(string ma = "", string ten = "", string nsx = "", double g = 0.0) : maHang(ma), tenHang(ten), nhaSX(nsx), gia(g) {}
        virtual ~HangHoa() = default; // virtual destructor để đảm bảo rằng khi xóa một đối tượng của lớp con thông qua con trỏ của lớp cha, hàm hủy của lớp con sẽ được gọi đúng cách
        virtual void inp() {
            cout << "Nhap ma hang: ";
            cin >> maHang;
            cout << "Nhap ten hang: ";
            cin >> tenHang; 
            cout << "Nhap nha san xuat: ";
            cin >> nhaSX;
            cout << "Nhap gia: ";
            cin >> gia; 
        }
        virtual void out() const {
            cout << "Ma hang: " << maHang << '\n';
            cout << "Ten hang: " << tenHang << '\n';
            cout << "Nha san xuat: " << nhaSX << '\n';
            cout << "Gia: " << fixed << setprecision(2) << gia << '\n';
        }
};
class HangDienMay : public HangHoa { // kế thừa công khai từ HangHoa
    private:
        int tgianBH;
        double congsuat, dienap;
    public:
        HangDienMay(string ma = "", string ten = "", string nsx = "", double g = 0.0, int tg = 0, double cs = 0.0, double dien = 0.0) 
            : HangHoa(ma, ten, nsx, g), tgianBH(tg), congsuat(cs), dienap(dien) {}
        void inp() override { // override để đảm bảo rằng phương thức này sẽ ghi đè lên phương thức inp() của lớp cha
            HangHoa::inp();
            cout << "Nhap thoi gian bao hanh: ";
            cin >> tgianBH;
            cout << "Nhap cong suat: ";
            cin >> congsuat;
            cout << "Nhap dien ap: ";
            cin >> dienap;
        }
        void out() const override {
            HangHoa::out();
            cout << "Thoi gian bao hanh: " << tgianBH << " thang\n";
            cout << "Cong suat: " << congsuat << " W\n";
            cout << "Dien ap: " << dienap << " V\n";
        }
};
class HangSanhSu : public HangHoa {
    private:
        string chatlieu;
    public:
        HangSanhSu(string ma = "", string ten = "", string nsx = "", double g = 0.0, string cl = "") : HangHoa(ma, ten, nsx, g), chatlieu(cl) {}
        void inp() override { 
            HangHoa::inp();
            cout << "Nhap chat lieu: ";
            cin >> chatlieu;
        }
        void out() const override {
            HangHoa::out();
            cout << "Chat lieu: " << chatlieu << '\n';
        }
};
class HangThucPham : public HangHoa {
    private:
        string ngaySX, ngayHH;
    public:
        HangThucPham(string ma = "", string ten = "", string nsx = "", double g = 0.0, string date = "", string nhh = "") : HangHoa(ma, ten, nsx, g), ngaySX(date), ngayHH(nhh) {}
        void inp() override {
            HangHoa::inp();
            cout << "Nhap ngay san xuat (dd/mm/yyyy): ";
            cin >> ngaySX;
            cout << "Nhap ngay het han (dd/mm/yyyy): ";
            cin >> ngayHH;
        }
        void out() const override {
            HangHoa::out();
            cout << "Ngay san xuat: " << ngaySX << '\n';
            cout << "Ngay het han: " << ngayHH << '\n';
        }
};
lin {
    fl;
    HangDienMay dm;
    cout << "Nhap thong tin hang dien may:\n";
    dm.inp();
    cout << "\nThong tin hang dien may:\n";
    dm.out();
    
    HangSanhSu ss;
    cout << "\nNhap thong tin hang sanh su:\n";
    ss.inp();
    cout << "\nThong tin hang sanh su:\n";
    ss.out();
    
    HangThucPham tp;
    cout << "\nNhap thong tin hang thuc pham:\n";
    tp.inp();
    cout << "\nThong tin hang thuc pham:\n";
    tp.out();
}