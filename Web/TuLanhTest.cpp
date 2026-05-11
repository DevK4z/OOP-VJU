#include <bits/stdc++.h>
using namespace std;
class TuLanh {
    private:
        string nhanhieu, maso, nuocsx;
        bool tkdien;
        int dungtich, gia;
    public:
        TuLanh() : nhanhieu("x"), maso("x"), nuocsx("x"), tkdien(false), dungtich(0), gia(0) {}
        TuLanh(string nh, string ms, string nsx, bool tkd, int dt, int g): nhanhieu(nh), maso(ms), nuocsx(nsx), tkdien(tkd), dungtich(dt), gia(g) {}
        void nhapThongTin() {
            string line;
            getline(cin >> ws, line);
            auto trim = [](string &s) {
                size_t l = s.find_first_not_of(" \t\r\n");
                size_t r = s.find_last_not_of(" \t\r\n");
                if (l == string::npos) {
                    s.clear();
                    return;
                }
                s = s.substr(l, r - l + 1);
            };
            stringstream ss(line);
            vector<string> fields;
            string field;
            while (getline(ss, field, '|')) {
                trim(field);
                fields.push_back(field);
            }
            if (fields.size() != 6) return;
            nhanhieu = fields[0];
            maso = fields[1];
            nuocsx = fields[2];
            string tk = fields[3];
            for (char &c : tk) c = tolower(static_cast<unsigned char>(c));
            tkdien = (tk == "1" || tk == "true" || tk == "yes" || tk == "co");
            dungtich = stoi(fields[4]);
            gia = stoi(fields[5]);
        }
        void print() {
            cout << "Nhãn hiệu: " << nhanhieu << '\n'
                << "Mã số: " << maso << '\n'
                << "Nước SX: " << nuocsx << '\n'
                << "T/K điện: " << (tkdien ? "Có" : "Không") << '\n'
                << "Dung tích: " << dungtich << "L\n"
                << "Giá: " << gia << "VNĐ\n";
        }
        string layNhanHieu() {return nhanhieu;}
        int layGia() {return gia;}
        int soNguoiSD() {
            if (dungtich <= 100) return 1;
            else if (dungtich <= 200) return 2;
            else return 3;
        }
        bool cungNhanHieu(TuLanh t) {
            return nhanhieu == t.nhanhieu;
        }
        bool nhHon(TuLanh t) {
            if (dungtich < t.dungtich) return true;
            else return false;
        }
};

class TuLanhTest { 
    public: 
        void testCase() {
            string SEP = "= = = = = = = =";
            TuLanh t1;
            TuLanh t2;
            cout << SEP << '\n';
            t1.nhapThongTin();
            t2.nhapThongTin();
            t1.print();
            cout << SEP << '\n';
            t2.print();
            cout << SEP << '\n';
        }
};

// int main() {
//     TuLanhTest test;
//     test.testCase();
// }