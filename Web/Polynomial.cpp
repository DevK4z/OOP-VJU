#include <bits/stdc++.h>
using namespace std;
class Polynomial {
    private:
        vector<int> v;
    public:
        Polynomial(const vector<int>& v = {}) : v(v) {}
        void inp() {
            int n;
            cin >> n;
            v.resize(n);
            for (auto &x : v) cin >> x;
        }
        string str() const {
            string res;
            int n = static_cast<int>(v.size());
            for (int i = 0; i < n; i++) {
                int coeff = v[i];
                if (coeff == 0) continue;
                int deg = n - 1 - i;
                int abs_coeff = abs(coeff);
                string term;
                if (deg == 0) {
                    term = to_string(abs_coeff);
                } else {
                    if (abs_coeff != 1) term += to_string(abs_coeff);
                    term += "x";
                    if (deg > 1) term += "^" + to_string(deg);
                }
                if (res.empty()) {
                    if (coeff < 0) res += "-";
                    res += term;
                } else {
                    res += (coeff < 0 ? " - " : " + ");
                    res += term;
                }
            }
            return res.empty() ? "0" : res;
        }
        Polynomial operator + (const Polynomial& p) const {
            size_t n = max(v.size(), p.v.size());
            vector<int> res(n, 0);
            size_t off = n - v.size();
            for (size_t i = 0; i < v.size(); i++) res[i + off] += v[i];
            size_t off_p = n - p.v.size();
            for (size_t i = 0; i < p.v.size(); i++) res[i + off_p] += p.v[i];
            return Polynomial(res);
        }
        int operator () (int x) const {
            long long res = 0;
            for (int coeff : v) {
                res = res * x + coeff;
            }
            return static_cast<int>(res);
        }
        void out() const {
            cout << str() << '\n';
        }
        friend ostream& operator << (ostream& os, const Polynomial& p) {
            return os << p.str();
        }
};
