#include <bits/stdc++.h>
#define fl ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define lin signed main()
using namespace std;
class point {
    private :
        int x, y;
    public :
        point(int x, int y) : x(x), y(y) {}
        void input() {
            cout << "Nhap x va y: ";
            cin >> x >> y;
        }
        void output() {
            cout << "Toa do: (" << x << ", " << y << ")\n";
        }
        point doixungquagocO() {
            return point(-x, -y);
        }
        double khoangcachdenO() {
            return sqrt(1.0 * x * x + 1.0 * y * y);
        }
        static double khoangcach2diem(point a, point b) {
            return sqrt(1.0 * (a.x - b.x) * (a.x - b.x) + 1.0 * (a.y - b.y) * (a.y - b.y));
        }
};
lin {
    fl;
    point p1(3, 4);
    p1.output();
    point p2 = p1.doixungquagocO();
    cout << "Doi xung qua O -> ";
    p2.output();
    cout << "Khoang cach den O: " << p1.khoangcachdenO() << "\n";
    point p3(6, 8);
    cout << "Khoang cach tu p1 den p3: " << point::khoangcach2diem(p1, p3) << "\n";
}