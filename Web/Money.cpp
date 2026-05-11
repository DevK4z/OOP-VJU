#include <bits/stdc++.h>
using namespace std;
class Money {
    private:
        int amount;
        string currency;
    public:
        Money(int a = 0, string cur = "VND"): amount(a), currency(cur) {}
        void inp() {
            cin >> amount >> currency;
        }
        string str() const {
            return to_string(amount) + " " + currency;
        }
        bool operator == (const Money& m) const {
            return amount == m.amount && currency == m.currency;
        }
        void out() const {
            cout << str() << '\n';
        }
        friend ostream& operator << (ostream& os, const Money& m) {
            return os << m.str();
        }
};

// int main() {
//     Money m1, m2;
//     m1.inp();
//     m2.inp();
//     m1.out();
//     m2.out();
//     cout << (m1 == m2 ? "True" : "False");
// }