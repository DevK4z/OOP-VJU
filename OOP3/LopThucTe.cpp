#include <bits/stdc++.h>
#define fl ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define lin signed main()
using namespace std;
// ====================================================
// LỚP 1: CON CHÓ
// ====================================================
class ConCho {
    private :
        string ten, mausac, giong, camxuc;
    public :
        ConCho(string ten, string mausac, string giong, string camxuc)
            : ten(ten), mausac(mausac), giong(giong), camxuc(camxuc) {} // initialization list
        void sua() {
            cout << ten << " dang sua\n";
        }
        void vayduoi() {
            cout << ten << " dang vay duoi\n";
        }
        void an() {
            cout << ten << " dang an\n";
        }
        void chay() {
            cout << ten << " dang chay\n";
        }
};
// ====================================================
// LỚP 2: Ô TÔ
// ====================================================
class Oto {
    private :
        string hang, kthuoc, mau;
        double gia;
        int tocdo;
    public : 
        Oto(string hang, string kthuoc, string mau, double gia, int tocdo)
            : hang(hang), kthuoc(kthuoc), mau(mau), gia(gia), tocdo(tocdo) {}
        void tangtoc(int them) {
            tocdo += them;
            cout << hang << " dang tang toc, toc do hien tai: " << tocdo << " km/h\n";
        }
        void giamtoc(int bot) {
            tocdo -= bot;
            if (tocdo < 0) tocdo = 0; // Toc do khong duoc am
            cout << hang << " dang giam toc, toc do hien tai: " << tocdo << " km/h\n";
        }
        void dam() {
            cout << hang << " bi dam\n";
            tocdo = 0;
        }
};
// ====================================================
// LỚP 3: TÀI KHOẢN NGÂN HÀNG
// ====================================================
class TaiKhoan {
    private : 
        string tentk, stk, bank;
        double sodu;
    public :
        TaiKhoan(string tentk, string stk, string bank, double sodu) 
            : tentk(tentk), stk(stk), bank(bank), sodu(sodu) {}
        void rut(double tien) {
            if (tien > sodu) cout << "So du ko du de rut\n";
            else {
                sodu -= tien;
                cout << "Rut thanh cong " << tien << " VND, so du con lai: " << sodu << '\n';
            }
        }
        void gui(double tien) {
            sodu += tien;
            cout << "Gui thanh cong " << tien << " VND, so du con lai: " << sodu << '\n';
        }
        void kiemtra() {
            cout << "Tai khoan: " << tentk << ", So tai khoan: " << stk << ", Ngan hang: " << bank << ", So du: " << sodu << " VND\n";
        }
};
lin {
    fl;
    // Inp lop ConCho
    ConCho cho1("Lucky", "Vang", "Shiba", "Vui");
    cho1.sua();
    cho1.vayduoi();
    cho1.an();
    cho1.chay();
    cout << '\n';
    // Inp lop Oto
    Oto oto1("Toyota", "Sedan", "Do", 500000000, 0);
    oto1.tangtoc(60);
    oto1.tangtoc(40);
    oto1.giamtoc(30);
    oto1.dam();
    cout << '\n';
    // Inp lop TaiKhoan
    TaiKhoan tk1("Khanh Tran", "123456789", "Vietcombank", 10000000);
    tk1.kiemtra();
    tk1.rut(2000000);
    tk1.gui(5000000);
    tk1.kiemtra();
}