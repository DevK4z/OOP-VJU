#include <bits/stdc++.h>
#define fl ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define lin signed main()
#define fi first
#define se second
#define ld long double
#define pii pair<fint, fint>
#define pll pair<long long, long long>
#define vl vector<ll>
#define vvl vector<vl>
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)x.size())
#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef int_fast64_t fint;
const ll maxN = 30, lim = 1e7 + 7, mod = 1e9 + 7, N = 2e5 + 5, base = 131, inf = (1ULL << 62);
class Animal {
    private:
        string name;
    public:
        Animal(string n = ""): name(n) {}
        void inp() {
            getline(cin, name);
        }
        virtual string make_sound() const {
            return "generic sound";
        }
        string describe() const {
            return "Tôi là " + name + ", tiếng kêu: " + make_sound();
        }
        void out() const {
            cout << describe() << '\n';
        }
        friend ostream& operator << (ostream& os, const Animal& a) {
            return os << a.describe();
        }
};
class Dog : public Animal {
    public:
        Dog(string n = ""): Animal(n) {}
        string make_sound() const override {
            return "Gâu!";
        }
};
class Cat : public Animal {
    public:
        Cat(string n = ""): Animal(n) {}
        string make_sound() const override {
            return "Meo!";
        }
};
// void solve() {
//     string type, name;
//     cin >> type >> name;
//     if (type == "dog") {
//         Dog d(name);
//         cout << d << '\n';
//     } else if (type == "cat") {
//         Cat c(name);
//         cout << c << '\n';
//     } else {
//         Animal a(name);
//         cout << a << '\n';
//     }
// }
// lin {
//     fl;
//     fint t; cin >> t;
//     while (t--) {
//         solve();
//     }
// }

// /*
//     inp:
//     2
//     dog Lucky
//     cat Mio
//     outp:
//     Tôi là Lucky, tiếng kêu: Gâu!
//     Tôi là Mio, tiếng kêu: Meo!
// */