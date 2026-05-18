#include <bits/stdc++.h>
using namespace std;
class Vector2D {
    private:
        int x, y;
    public:
        Vector2D(int v1 = 0, int v2 = 0): x(v1), y(v2) {}
        void inp() {
            cin >> x >> y;
        }
        string str() const {
            return "(" + to_string(x) + ", " + to_string(y) + ")";
        }
        bool operator == (const Vector2D& v) const {
            return x == v.x && y == v.y;
        }
        Vector2D operator + (const Vector2D& v) const {
            return Vector2D(x + v.x, y + v.y);
        }
        Vector2D operator - (const Vector2D& v) const {
            return Vector2D(x - v.x, y - v.y);
        }
        Vector2D operator - () const {
            return Vector2D(-x, -y);
        }
        void out() const {
            cout << str() << '\n';
        }
        friend ostream& operator << (ostream& os, const Vector2D& v) {
            return os << v.str();
        }
};
// int main() {
//     Vector2D v1, v2;
//     v1.inp();
//     v2.inp();
//     cout << (v1 + v2) << '\n';
//     cout << (v1 - v2) << '\n';
//     cout << (-v1) << '\n';
//     cout << (v1 == v2 ? "True" : "False") << '\n';
// }