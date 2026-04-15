#include <bits/stdc++.h>
#define fl ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define lin signed main()
#define pb push_back
using namespace std;
class tuoikhonghople : public invalid_argument {
    public :
        tuoikhonghople(int tuoi) : invalid_argument("Tuoi " + to_string(tuoi) + " khong hop le") {}
};

class backhonghople : public invalid_argument {
    public :
        backhonghople(int bac) : invalid_argument("Bac " + to_string(bac) + " khong hop le") {}
};

class canbo {
    private :
        string hoten;
        int tuoi;
        string gioitinh, diachi;
    public : 
        canbo(string ht = "", int t = 0, string gt = "", string dc = "") : hoten(ht), tuoi(18), gioitinh(gt), diachi(dc) {
            if (t < 18 || t > 65) throw tuoikhonghople(t);
        }
        virtual ~canbo() = default;
        string gethoten() const { return hoten; }
        string getgioitinh() const { return gioitinh; }
        string getdiachi() const { return diachi; }
        int gettuoi() const { return tuoi; }
        void sethoten(const string& ht) { hoten = ht; }
        void setgioitinh(const string& gt) { gioitinh = gt; }
        void setdiachi(const string& dc) { diachi = dc; }
        void settuoi(int t) {
            if (t < 18 || t > 65) throw tuoikhonghople(t);
            tuoi = t;
        }
        virtual string mota() const = 0;
        bool operator < (const canbo& o) const {
            return hoten < o.hoten;
        }
        virtual void ghifile(ostream& o) {
            o << hoten << ";" << tuoi << ";" << gioitinh << ";" << diachi << ";" << mota() << "\n";
        } 
        friend ostream& operator << (ostream& os, const canbo& cb) {
            return os << "Ho ten: " << cb.hoten << " | Tuoi: " << cb.tuoi << " | Gioi tinh: " << cb.gioitinh << " | Dia chi: " << cb.diachi << " | " << cb.mota();
        }
};

class congnhan : public canbo {
    private:
        int bac;
    public:
        congnhan(string ht = "", int t = 0, string gt = "", string dc = "", int b = 0) : canbo(ht, t, gt, dc), bac(1) {
            if (b < 1 || b > 10) throw backhonghople(b);
        }
        int getbac() const { return bac; }
        void setbac(int b) {
            if (b < 1 || b > 10) throw backhonghople(b);
            bac = b;
        }
        string mota() const override {
            return "Cong nhan bac " + to_string(bac);
        }
};

class kysu : public canbo {
    private:
        string nganh;
    public:
        kysu(string ht = "", int t = 0, string gt = "", string dc = "", string ndt = "") : canbo(ht, t, gt, dc), nganh(ndt) {}
        string mota() const override {
            return "Ky su nganh " + nganh;
        }
};

class nhanvien : public canbo {
    private:
        string congviec;
    public:
        nhanvien(string ht = "", int t = 0, string gt = "", string dc = "", string cv = "") : canbo(ht, t, gt, dc), congviec(cv) {}
        string mota() const override {
            return "Nhan vien cong viec " + congviec;
        }
};

class QLCB {
    private:
        vector<canbo*> ds;
    public:
        void themcb(canbo* cb) { ds.pb(cb); }
        void timcb(string ten) const {
            for (auto cb : ds) {
                if (cb -> gethoten() == ten) {
                    cout << *cb << '\n';
                    return;
                }
            }
        }
        void hiencb() const {
            for (auto &cb : ds) cout << *cb << '\n';
        }
        void thoat() {
            for (auto &cb : ds) delete cb;
            ds.clear();
        }
        void ghifiledanhsach(ostream& fout) {
            for (auto &cb : ds) cb -> ghifile(fout);
        }
        ~QLCB() {
            for (auto &cb : ds) delete cb;
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
    cout << "Nhap so luong can bo: " << '\n';
    cin >> n;
    QLCB qlcb;
    while (n--) {
        menu();
        int chon;
        cout << "Nhap lua chon: ";
        cin >> chon;
        if (chon == 1) {
            string ht, gt, dc, nganh, cv;
            int t, bac;
            cout << "Nhap ho ten: ";
            cin.ignore();
            getline(cin, ht);
            cout << "Nhap tuoi: ";
            cin >> t;
            cout << "Nhap gioi tinh: ";
            cin.ignore();
            getline(cin, gt);
            cout << "Nhap dia chi: ";
            getline(cin, dc);
            cout << "Chon loai can bo:\n";
            cout << "1. Cong nhan\n";
            cout << "2. Ky su\n";
            cout << "3. Nhan vien\n";
            int loai;
            cout << "Nhap lua chon: ";
            cin >> loai;
            if (loai == 1) {
                cout << "Nhap bac cong nhan: ";
                cin >> bac;
                qlcb.themcb(new congnhan(ht, t, gt, dc, bac));
            } else if (loai == 2) {
                cout << "Nhap nganh dao tao: ";
                cin.ignore();
                getline(cin, nganh);
                qlcb.themcb(new kysu(ht, t, gt, dc, nganh));
            } else if (loai == 3) {
                cout << "Nhap cong viec: ";
                cin.ignore();
                getline(cin, cv);
                qlcb.themcb(new nhanvien(ht, t, gt, dc, cv));
            } else {
                cout << "Lua chon khong hop le.\n";
            }
        } else if (chon == 2) {
            string ten;
            cout << "Nhap ten can bo can tim: ";
            cin.ignore();
            getline(cin, ten);
            qlcb.timcb(ten);
        } else if (chon == 3) {
            qlcb.hiencb();
        } else if (chon == 4) {
            qlcb.thoat();
            break;
        } else {
            cout << "Lua chon khong hop le.\n";
        }
    }
}