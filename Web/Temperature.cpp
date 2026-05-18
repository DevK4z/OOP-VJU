#include <bits/stdc++.h>
using namespace std;
class Temperature {
    private:
        double celsiusv;
    public:
        Temperature(double c = 0): celsiusv(c) {}
        double celsius() const {
            return celsiusv;
        }
        void set_celsius(double c) {
            if (c < -273.15) {
                throw invalid_argument("ERROR");
            }
            celsiusv = c;
        }
        double fahrenheit() const {
            return celsiusv * 9.0 / 5.0 + 32.0;
        }
        void set_fahrenheit(double f) {
            set_celsius((f - 32.0) * 5.0 / 9.0);
        }
        void inp() {
            cin >> celsiusv;
        }
        void out() const{
            cout << fixed << setprecision(2) << celsius() << '\n';
            cout << fixed << setprecision(2) << fahrenheit() << '\n';
        }
        friend ostream& operator << (ostream& os, const Temperature& t) {
            return os << fixed << setprecision(2) << t.celsius() << '\n' << fixed << setprecision(2) << t.fahrenheit() << '\n';
        }
};
// int main() {
//     Temperature t;
//     t.inp();
//     cout << t;
//     t.set_fahrenheit(100);
//     cout << t;
//     try {
//         t.set_celsius(-300);
//     } catch (const invalid_argument& e) {
//         cout << e.what() << '\n';
//     }
// }