#include <bits/stdc++.h>
#define fl ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define lin signed main()
using namespace std;
class ttinchung {
    private:
        string maNV, tenNV;
        int namsinh;
        string diachi;
        double hesoluong, luongtoida;
    public:
        ttinchung(string ma = "", string ten = "", int ns = 0, string dc = "", double hsl = 0, double ltd = 0) : maNV(ma), tenNV(ten), namsinh(ns), diachi(dc), hesoluong(hsl), luongtoida(ltd) {}
        virtual ~ttinchung() = default;
        virtual void inp() {
            cout << "Nhap ma nhan vien: ";
            cin >> maNV;
            cout << "Nhap ten nhan vien: ";
            cin >> tenNV;
            cout << "Nhap nam sinh: ";
            cin >> namsinh;
            cout << "Nhap dia chi: ";
            cin >> diachi;
            cout << "Nhap he so luong (>0): ";
            cin >> hesoluong;
            cout << "Nhap luong toi da: ";
            cin >> luongtoida;
        }
        virtual void out() const {
            cout << "Ma nhan vien: " << maNV << '\n';
            cout << "Ten nhan vien: " << tenNV << '\n';
            cout << "Nam sinh: " << namsinh << '\n';
            cout << "Dia chi: " << diachi << '\n';
            cout << "He so luong: " << hesoluong << '\n';
            cout << "Luong toi da: " << luongtoida << '\n';
        }
        double tinhluong() const {
            return hesoluong * luongtoida;
        }
        bool tangluong(double delta) {
            double hsmoi = hesoluong + delta;
            double luongmoi = hsmoi * luongtoida;
            if (luongmoi > luongtoida) cout << "Khong the tang luong! Luong moi vuot luong toi da (" << fixed << setprecision(0) << luongtoida << ").\n";
            hesoluong = hsmoi;
            return luongmoi <= luongtoida;
        }
};

class congtacvien : public ttinchung {
    private:
        int thoihanhopdong;
        double phucap;
    public:
        congtacvien(string ma = "", string ten = "", int ns = 0, string dc = "", double hsl = 0, double ltd = 0, int thhd = 0, double pc = 0) : ttinchung(ma, ten, ns, dc, hsl, ltd), thoihanhopdong(thhd), phucap(pc) {}
        void inp() override {
            ttinchung::inp();
            cout << "Nhap thoi han hop dong (thang): ";
            cin >> thoihanhopdong;
            cout << "Nhap phu cap: ";
            cin >> phucap;
        }
        void out() const override {
            ttinchung::out();
            cout << "Thoi han hop dong: " << thoihanhopdong << " thang\n";
            cout << "Phu cap: " << phucap << '\n';
        }
};

class nhanviencthuc : public ttinchung {
    private:
        string vitri;
    public:
        nhanviencthuc(string ma = "", string ten = "", int ns = 0, string dc = "", double hsl = 0, double ltd = 0, string vt = "") : ttinchung(ma, ten, ns, dc, hsl, ltd), vitri(vt) {}
        void inp() override {
            ttinchung::inp();
            cout << "Nhap vi tri: ";
            cin >> vitri;
        }
        void out() const override {
            ttinchung::out();
            cout << "Vi tri: " << vitri << '\n';
        }
};

class truongphong : public ttinchung {
    private:
        string ngayqly;
        double phucapqly;
    public:
        truongphong(string ma = "", string ten = "", int ns = 0, string dc = "", double hsl = 0, double ltd = 0, string nql = "", double pcql = 0) : ttinchung(ma, ten, ns, dc, hsl, ltd), ngayqly(nql), phucapqly(pcql) {}
        void inp() override {
            ttinchung::inp();
            cout << "Nhap ngay quan ly (dd/mm/yyyy): ";
            cin >> ngayqly;
            cout << "Nhap phu cap quan ly: ";
            cin >> phucapqly;
        }
        void out() const override {
            ttinchung::out();
            cout << "Ngay quan ly: " << ngayqly << '\n';
            cout << "Phu cap quan ly: " << phucapqly << '\n';
        }
};
lin {
    fl;
    int n;
    cout << "Nhap so luong can bo: ";
    cin >> n;
    vector<ttinchung*> ds;
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin can bo thu " << i + 1 << ":\n";
        int loai;
        cout << "Chon loai can bo (1 - Cong tac vien, 2 - Nhan vien chinh thuc, 3 - Truong phong): ";
        cin >> loai;
        ttinchung* cb = nullptr;
        if (loai == 1) cb = new congtacvien();
        else if (loai == 2) cb = new nhanviencthuc();
        else if (loai == 3) cb = new truongphong();
        else {
            cout << "Loai can bo khong hop le. Bo qua.\n";
            continue;
        }
        cb -> inp();
        ds.push_back(cb);
    }
    cout << "\n=== THONG TIN CAN BO ===\n";
    for (auto cb : ds) {
        cb -> out();
        cout << "Luong: " << cb -> tinhluong() << '\n';
        cout << "Tang luong 0.5 he so luong...\n";
        cb -> tangluong(0.5);
        cout << "Luong sau khi tang: " << cb -> tinhluong() << "\n\n";
    }
    for (auto cb : ds) delete cb;
    ds.clear();
}