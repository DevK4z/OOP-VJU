#include <bits/stdc++.h>
#define fl ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define lin signed main()
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
using namespace std;
class giakhonghople : public invalid_argument {
    public :
        giakhonghople(double gia) : invalid_argument("Gia " + to_string(gia) + " khong hop le (>= 0)") {}
};

class mahangtrunglap : public logic_error {
    public:
        mahangtrunglap(const string& ma) : logic_error("Ma hang bi trung lap: " + ma) {}
};

class hanghoa {
    private:
        string mahang, tenhang, nhasx;
        double gia;
    public:
        hanghoa(string ma = "", string ten = "", string nsx = "", double g = 0.0) : mahang(ma), tenhang(ten), nhasx(nsx), gia(g) {
            if (g < 0) throw giakhonghople(g); // 
        }
        virtual ~hanghoa() = default;
        string getma() const { return mahang; }
        string getten() const { return tenhang; }
        string getnsx() const { return nhasx; }
        double getgia() const { return gia; }
        void setgia(double g) {
            if (g < 0) throw giakhonghople(g);
            gia = g;
        }
        virtual string loaihang() const = 0;
        virtual string inTT() const {
            return "[" + loaihang() + "] Ma: " + mahang + " | " + tenhang + " | NSX: " + nhasx + " | Gia: " + to_string((long long)gia) + "d";
        }
        bool operator < (const hanghoa& o) const {
            return gia < o.gia;
        }
        bool operator == (const hanghoa& o) const {
            return mahang == o.mahang;
        }
        friend ostream& operator << (ostream& os, const hanghoa& h) {
            return os << h.inTT();
        }
};

class hangdienmay : public hanghoa {
    private:
        int tgianbh;
        double congsuat, dienap;
    public:
        hangdienmay(string ma = "", string ten = "", string nsx = "", double g = 0.0, int tg = 0, double cs = 0.0, double dien = 0.0) 
            : hanghoa(ma, ten, nsx, g), tgianbh(tg), congsuat(cs), dienap(dien) {}
        string loaihang() const override { return "Dien may"; }
        string inTT() const override {
            return hanghoa::inTT() + " | Thoi gian bao hanh: " + to_string(tgianbh) + " thang | Cong suat: " + to_string(congsuat) + " W | Dien ap: " + to_string(dienap) + " V";
        }
};

class hangsanhsu : public hanghoa {
    private:
        string chatlieu;
    public:
        hangsanhsu(string ma = "", string ten = "", string nsx = "", double g = 0.0, string cl = "") 
            : hanghoa(ma, ten, nsx, g), chatlieu(cl) {}
        string loaihang() const override { return "Sanh su"; }
        string inTT() const override {
            return hanghoa::inTT() + " | Chat lieu: " + chatlieu;  
        }
};

class hangthucpham : public hanghoa {
    private:
        string ngaysx, ngayhh;
    public:
        hangthucpham(string ma = "", string ten = "", string nsx = "", double g = 0.0, string sx = "", string hh = "") 
            : hanghoa(ma, ten, nsx, g), ngaysx(sx), ngayhh(hh) {}
        string loaihang() const override { return "Thuc pham"; }
        string inTT() const override {
            return hanghoa::inTT() + " | Ngay san xuat: " + ngaysx + " | Han su dung: " + ngayhh;
        }
};

lin {
    fl;
    vector<hanghoa*> ds;
    hangdienmay dm("DM01", "Tu lanh", "LG", 12000000, 24, 1500, 220);
    hangsanhsu ss("SS01", "Binh hoa", "Minh Long", 350000, "Su cao cap");
    hangthucpham tp("TP01", "Sua tuoi", "Vinamilk", 32000, "2025-01-01", "2025-07-01");
    ds.push_back(&dm);
    ds.push_back(&ss);
    ds.push_back(&tp);
    for (const auto& h : ds) {
        cout << *h << '\n';
    }
    sort(all(ds), [](const hanghoa* a, const hanghoa* b) { // lambda để so sánh giá của hai đối tượng hanghoa thông qua con trỏ
        return a->getgia() < b->getgia();
    });
    cout << "\nDanh sach sau khi sap xep theo gia tang dan:\n";
    for (const auto &h : ds) cout << *h << '\n';
    // gia khong hop le (tham khao AI)
    cout << "\nThu nghiem gia khong hop le:\n";
    try {
        hangdienmay dm2("DM02", "May giat", "Samsung", -5000000, 12, 1000, 220);
    } catch (const giakhonghople& e) {
        cout << e.what() << '\n';  
    }
    // ma hang trung lap (tham khao AI)
    cout << "\nThu nghiem ma hang trung lap:\n";
    try {
        vector<hanghoa*> kho;
        hangdienmay dm3("DM01", "Tu lanh", "LG", 12000000, 24, 1500, 220);
        hangsanhsu ss2("SS01", "Binh hoa", "Minh Long", 350000, "Su cao cap");
        kho.push_back(&dm3);
        kho.push_back(&ss2);
        for (const auto& h : kho) {
            for (const auto& h2 : kho) {
                if (h != h2 && *h == *h2) { // so sánh mã hàng thông qua operator==
                    throw mahangtrunglap(h->getma());
                }
            }
        }
    } catch (const mahangtrunglap& e) {
        cout << e.what() << '\n';  
    }
}