#include <bits/stdc++.h>
#define fl ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define lin signed main()
using namespace std;
class Point {
    private:
        int x, y;
    public:
        Point() : x(0), y(1) {}
        Point(int x, int y): x(x), y(y) {}
        void read() {
            cin >> x >> y;
        }
        void print() const {
            cout << "(" << x << ", " << y << ")\n";
        }
        void move(int dx, int dy) {
            x += dx;
            y += dy;
        }
        int getX() const {
            return x;
        }
        int getY() const {
            return y;
        }
        double distance() const {
            return sqrt(x * x + y * y);
        }
        double distance(Point p) const {
            return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
        }
};