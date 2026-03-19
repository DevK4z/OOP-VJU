#include <bits/stdc++.h>
#define fl ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define lin signed main()
using namespace std;
class sieunhan { 
    private :
        string ten, vukhi, mausac;
        int sucmanh;
    public :
        sieunhan(string ten, string vukhi, string mausac, int sucmanh) : ten(ten), vukhi(vukhi), mausac(mausac), sucmanh(sucmanh) {}
        void output() const {
            cout << "Ten: " << ten << " | Vu khi: " << vukhi << " | Mau sac: " << mausac << " | Suc manh: " << sucmanh << "\n";
        }
};
lin {
    fl;
    vector <sieunhan> ds;
    string ten, vukhi, mausac;
    int sm;
    cout << "=== NHAP THONG TIN SIEU NHAN ===\n";
    while (true) {
        cout << "Nhap ten (hoac 'exit' de thoat): ";
        getline(cin, ten);
        if (ten.empty()) {
            cout << "Ten khong duoc de trong. Vui long nhap lai.\n";
            continue;
        }
        // neu ten bang so nguyen, thong bao loi va yeu cau nhap lai
        if (all_of(ten.begin(), ten.end(), ::isdigit)) {
            cout << "Ten khong duoc chua so. Vui long nhap lai.\n";
            continue;
        }
        if (ten == "exit") break;
        cout << "Nhap vu khi: ";
        getline(cin, vukhi);
        cout << "Nhap mau sac: ";
        getline(cin, mausac);
        cout << "Nhap suc manh (1-10): ";
        cin >> sm;
        cin.ignore(); // Xoa bo nho dem sau khi nhap so
        ds.emplace_back(ten, vukhi, mausac, sm);
    }
    cout << "\n=== DANH SACH SIEU NHAN ===\n";
    for (const auto& sn : ds) sn.output();
}