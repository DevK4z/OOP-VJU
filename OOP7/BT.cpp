#include <bits/stdc++.h>
#define fl ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define lin signed main()
#define pb push_back
#define sp shared_ptr
#define ms make_shared
#define fi first
#define se second
using namespace std;
class canbo {
    private:
        string hoten;
        int tuoi;
        string gioitinh, diachi, loai;
    public:
        canbo(string ht, int t, string gt, string dc, string l) : hoten(ht), tuoi(t), gioitinh(gt), diachi(dc), loai(l) {}
        virtual ~canbo() = default;
        string gethoten() const { return hoten; }
        string getloai() const { return loai; }
        virtual void inTT() const {
            cout << "Ho ten: " << hoten << '\n';
            cout << " | Tuoi: " << tuoi << '\n';
            cout << " | Gioi tinh: " << gioitinh << '\n';
            cout << " | Dia chi: " << diachi << '\n';
            cout << " | Loai: " << loai << '\n';
        }
        virtual string data() const = 0;
        string record() const {
            return hoten + "|" + to_string(tuoi) + "|" + gioitinh + "|" + diachi + "|" + loai + "|" + data();
        }
};

class congnhan : public canbo {
    private:
        int bac;
    public:
        congnhan(string ht, int t, string gt, string dc, int b) : canbo(ht, t, gt, dc, "Cong nhan"), bac(b) {}
        void inTT() const override {
            canbo::inTT();
            cout << " | Bac: " << bac << "/10\n";
        }
        string data() const override {
            return to_string(bac); // Trả về chuỗi đại diện cho dữ liệu riêng của công nhân (bậc)
        }
};

class kysu : public canbo {
    private:
        string nganh;
    public:
        kysu(string ht, int t, string gt, string dc, string n) : canbo(ht, t, gt, dc, "Ky su"), nganh(n) {}
        void inTT() const override {
            canbo::inTT();
            cout << " | Nganh dao tao: " << nganh << '\n';
        }
        string data() const override {
            return nganh;
        }
};

class nhanvien : public canbo {
    private:
        string congviec;
    public:
        nhanvien(string ht, int t, string gt, string dc, string cv) : canbo(ht, t, gt, dc, "Nhan vien"), congviec(cv) {}
        void inTT() const override {
            canbo::inTT();
            cout << " | Cong viec: " << congviec << '\n';
        }
        string data() const override {
            return congviec;
        }
};

class QLCB {
    private: 
        map <string, sp<canbo>> ds;
        vector <string> csv(const string& line, char delimiter = ',') {
            vector <string> tokens;
            string token;
            istringstream ts(line);
            while (getline(ts, token, delimiter)) tokens.pb(token);
            return tokens;
        }
    public: 
        void luujson(const string& name) {
            ofstream file(name);
            if (file.is_open()) {
                for (const auto& pair : ds) {
                    file << pair.second->record() << "\n";
                }
                file.close();
                cout << "Da luu xong file JSON.\n";
            } else {
                cout << "Loi: Khong the mo file de ghi.\n";
            }
        }
        
        void read_csv(const string& name) {
            ifstream file(name);
            if (!file.is_open()) {
                cout << "Loi: Khong tim thay file " << name << " (FileNotFoundError)\n";
                return;
            }
            string line; 
            while (getline(file, line)) {
                if (line.empty() || line[0] == '#') continue;
                vector <string> tokens = csv(line);
                try {
                    if (tokens.size() < 6) throw invalid_argument("Du lieu khong hop le: " + line);
                    string ht = tokens[0];
                    int t = stoi(tokens[1]);
                    string gt = tokens[2];
                    string dc = tokens[3];
                    string loai = tokens[4];
                    string tt_rieng = tokens[5];
                    sp<canbo> cb;
                    if (loai == "Cong nhan") {
                        int bac = stoi(tt_rieng);
                        cb = ms<congnhan>(ht, t, gt, dc, bac);
                    } else if (loai == "Ky su") {
                        cb = ms<kysu>(ht, t, gt, dc, tt_rieng);
                    } else if (loai == "Nhan vien") {
                        cb = ms<nhanvien>(ht, t, gt, dc, tt_rieng);
                    } else {
                        throw invalid_argument("Loai can bo khong hop le: " + loai);
                    }
                    if (cb) ds[ht] = cb;
                } catch (const invalid_argument& e) {
                    cout << "Loi khi doc du lieu: " << e.what() << "\n";
                } catch (const exception& e) {
                    cout << "Loi khong xac dinh: " << e.what() << "\n";
                }
            }
            file.close();
            cout << "Da doc xong file CSV.\n";
        }
        
        void themcb(sp<canbo> cb) {
            ds[cb->gethoten()] = cb;
            luujson("canbo.json");
        }

        void xoacb(const string& hoten) {
            if (ds.erase(hoten)) {
                cout << "Da xoa can bo: " << hoten << "\n";
                luujson("canbo.json");
            } else {
                cout << "Khong tim thay can bo de xoa.\n";
            }
        }

        void timcb(const string& hoten) const {
            auto it = ds.find(hoten);
            if (it != ds.end()) { // Nếu tìm thấy, gọi phương thức inTT() của đối tượng canbo được trỏ bởi it->second
                it-> se -> inTT(); // Gọi phương thức inTT() của đối tượng canbo được trỏ bởi it->second
            } else {
                cout << "Khong tim thay can bo.\n";
            }
        }

        void timloai(const string& loai) const {
            bool found = false;
            for (const auto& pair : ds) {
                if (pair.se->getloai() == loai) {
                    pair.se->inTT();
                    found = true;
                }
            }
            if (!found ) {
                cout << "Khong tim thay can bo loai " << loai << ".\n";
            }
        }

        void hiencb() const {
            if (ds.empty()) {
                cout << "Danh sach trong.\n";
                return;
            }
            for (const auto& pair : ds) pair.se->inTT();
        }

        void taitufilejson(const string& name) {
            ifstream file(name);
            if (!file.is_open()) {
                cout << "Khong tim thay file JSON (" << name << "). Bat dau voi danh sach trong.\n";
                return;
            }
            try {
                ds.clear();
                string line;
                while(getline(file, line)) {
                    if (line.empty()) continue;
                    vector <string> tokens = csv(line, '|');
                    if (tokens.size() < 6) {
                        cout << "Du lieu khong hop le: " << line << "\n";
                        continue;
                    }
                    string ht = tokens[0];
                    int t = stoi(tokens[1]);
                    string gt = tokens[2];
                    string dc = tokens[3];
                    string loai = tokens[4];
                    string tt_rieng = tokens[5];
                    sp<canbo> cb;
                    if (loai == "Cong nhan") {
                        int bac = stoi(tt_rieng);
                        cb = ms<congnhan> (ht, t, gt, dc, bac);
                    } else if (loai == "Ky su") {
                        cb = ms<kysu> (ht, t, gt, dc, tt_rieng);
                    } else if (loai == "Nhan vien") {
                        cb = ms<nhanvien> (ht, t, gt, dc, tt_rieng);
                    } else {
                        cout << "Loai can bo khong hop le: " << loai << "\n";
                        continue;
                    }
                    if (cb) ds[ht] = cb;
                }
                cout << "Da tai xong file JSON.\n";
            } catch (const exception& e) {
                cout << "Loi khi doc file JSON: " << e.what() << "\n";
            }
        }
};

lin {
    fl;
    QLCB qlcb;
    qlcb.taitufilejson("canbo.json");
    int chon;
    do {
        cout << "1. Doc du lieu tu file canbo.csv (Import)\n";
        cout << "2. Hien thi danh sach can bo hien tai\n";
        cout << "3. Them moi mot Cong Nhan\n";
        cout << "4. Xoa can bo theo Ho ten\n";
        cout << "5. Tim kiem theo Ho ten\n";
        cout << "6. Tim kiem theo Loai (CongNhan/KySu/NhanVien)\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "====================================\n";
        cout << "Nhap lua chon: ";
        if (!(cin >> chon)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Nhap sai dinh dang. Vui long nhap so.\n";
            chon = -1;
            continue;
        }
        cin.ignore(); // Xóa ký tự newline còn lại trong buffer
        switch (chon) {
            case 1: {
                qlcb.read_csv("canbo.csv");
                qlcb.luujson("canbo.json"); // Cập nhật lại bản JSON sau khi import CSV
                break;
            }
            case 2:
                qlcb.hiencb();
                break;
            case 3: {
                string ht, gt, dc;
                int t, bac;
                cout << "Nhap ho ten: "; getline(cin, ht);
                cout << "Nhap tuoi: "; cin >> t; cin.ignore();
                cout << "Nhap gioi tinh: "; getline(cin, gt);
                cout << "Nhap dia chi: "; getline(cin, dc);
                cout << "Nhap bac (1-10): "; cin >> bac; cin.ignore();
                
                qlcb.themcb(ms<congnhan>(ht, t, gt, dc, bac));
                cout << "Da them thanh cong!\n";
                break;
            }
            case 4: {
                string ht;
                cout << "Nhap ho ten can xoa: "; getline(cin, ht);
                qlcb.xoacb(ht);
                break;
            }
            case 5: {
                string ht;
                cout << "Nhap ho ten can tim: "; getline(cin, ht);
                qlcb.timcb(ht);
                break;
            }
            case 6: {
                string loai;
                cout << "Nhap loai (CongNhan/KySu/NhanVien): "; getline(cin, loai);
                qlcb.timloai(loai);
                break;
            }
            case 0: {
                cout << "Thoat chuong trinh.\n";
                break;
            }
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
    } while (chon != 0);
}