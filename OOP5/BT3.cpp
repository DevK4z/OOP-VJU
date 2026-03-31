#include <bits/stdc++.h>
#define fl ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define lin signed main() 
#define pb push_back
using namespace std;
class canbo {
    private:
        string hoten;
        int tuoi;
        string gioitinh, diachi;
    public:
        canbo(string ht = "", int t = 0, string gt = "", string dc = "") : hoten(ht), tuoi(t), gioitinh(gt), diachi(dc) {}
        virtual ~canbo() = default;
        virtual void inp() {
            cout << "Nhap ho ten: ";
            cin >> hoten;
            cout << "Nhap tuoi: ";
            cin >> tuoi;
            cout << "Nhap gioi tinh (Nam / Nu / Khac): ";
            cin >> gioitinh;
            cout << "Nhap dia chi: ";
            cin >> diachi;
        }
        virtual void out() const {
            cout << "Ho ten: " << hoten << '\n';
            cout << "Tuoi: " << tuoi << '\n';
            cout << "Gioi tinh: " << gioitinh << '\n';
            cout << "Dia chi: " << diachi << '\n';
        }
        string getTen() const {
            return hoten;
        }
};

class congnhan : public canbo {
    private:
        int bac;
    public:
        congnhan(string ht = "", int t = 0, string gt = "", string dc = "", int b = 0) : canbo(ht, t, gt, dc), bac(b) {}
        void inp() override {
            canbo::inp();
            cout << "Nhap bac: ";
            cin >> bac;
        }
        void out() const override {
            canbo::out();
            cout << "Bac: " << bac << '\n';
        }
};

class kysu : public canbo {
    private:
        string nganh;
    public:
        kysu(string ht = "", int t = 0, string gt = "", string dc = "", string ndt = "") : canbo(ht, t, gt, dc), nganh(ndt) {}
        void inp() override {
            canbo::inp();
            cout << "Nhap nganh dao tao: ";
            cin >> nganh;
        }
        void out() const override {
            canbo::out();
            cout << "Nganh dao tao: " << nganh << '\n';
        }
};

class nhanvien : public canbo {
    private:
        string congviec;
    public:
        nhanvien(string ht = "", int t = 0, string gt = "", string dc = "", string cv = "") : canbo(ht, t, gt, dc), congviec(cv) {}
        void inp() override {
            canbo::inp();
            cout << "Nhap cong viec: ";
            cin >> congviec;
        }
        void out() const override {
            canbo::out();
            cout << "Cong viec: " << congviec << '\n';
        }
};

class QLCB {
    private:
        vector<canbo*> ds;
    public:
        void themcb(canbo* cb) {
            ds.pb(cb);
        }
        void timcb(string ten) const {
            for (auto cb : ds) {
                if (cb -> getTen() == ten) {
                    cb -> out();
                    return;
                }
            }
            cout << "Khong tim thay can bo co ten " << ten << '\n';
        }
        void hiencb() const {
            for (auto cb : ds) cb -> out(); 
        }
        void thoat() {
            for (auto cb : ds) delete cb;
            ds.clear();
        }
        ~QLCB() {
            for (auto cb : ds) delete cb;
        }
};

void menu() {
    cout << "1. Them can bo\n";
    cout << "2. Tim kiem can bo theo ten\n";
    cout << "3. Hien thi thong tin ve danh sach can bo\n";
    cout << "4. Thoat\n";
}

lin {
    fl;
    int n;
    cout << "Nhap so luong can bo: ";
    cin >> n;
    QLCB qlcb;
    for (int i = 0; i < n; i++) {
        int loai;
        cout << "Nhap loai can bo (1: cong nhan, 2: ky su, 3: nhan vien): ";
        cin >> loai;
        canbo* cb;
        if (loai == 1) cb = new congnhan();
        else if (loai == 2) cb = new kysu();
        else cb = new nhanvien();
        cb -> inp();
        qlcb.themcb(cb);
    }
    int chon;
    do {
        menu();
        cout << "Nhap lua chon: ";
        cin >> chon;
        if (chon == 1) {
            int loai;
            cout << "Nhap loai can bo (1: cong nhan, 2: ky su, 3: nhan vien): ";
            cin >> loai;
            canbo* cb;
            if (loai == 1) cb = new congnhan();
            else if (loai == 2) cb = new kysu();
            else cb = new nhanvien();
            cb -> inp();
            qlcb.themcb(cb);
        } else if (chon == 2) {
            string ten;
            cout << "Nhap ten can bo can tim: ";
            cin >> ten;
            qlcb.timcb(ten);
        } else if (chon == 3) {
            qlcb.hiencb();
        } else if (chon == 4) {
            qlcb.thoat();
        } else cout << "Lua chon khong hop le. Vui long chon lai.\n";
    } while (chon != 4);
}