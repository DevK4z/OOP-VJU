#include <bits/stdc++.h>
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

class LineSegment {
    private:
        Point d1, d2;
    public:
        LineSegment() : d1(8, 5), d2(1, 0) {}
        LineSegment(Point d1, Point d2) : d1(d1), d2(d2) {}
        LineSegment(int x1, int y1, int x2, int y2) : d1(x1, y1), d2(x2, y2) {}
        LineSegment(const LineSegment& S) : d1(S.d1), d2(S.d2) {}
        void read() {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            d1 = Point(x1, y1);
            d2 = Point(x2, y2);
        }
        void print() const {
            cout << "[(" << d1.getX() << ", " << d1.getY() << "); (" << d2.getX() << ", " << d2.getY() << ")]" << '\n';
        }
        void move(int dx, int dy) {
            d1.move(dx, dy);
            d2.move(dx, dy);
        }
        double length() const {
            return d1.distance(d2);
        }
        int angle() const {
            double dx = d2.getX() - d1.getX();
            double dy = d2.getY() - d1.getY();
            int res = static_cast<int>(round(atan2(dy, dx) * 180.0 / acos(-1.0)));
            res %= 360;
            if (res < 0) res += 360;
            return res;
        }
};

class LineSegmentTest {
    public:
        void testCase() {
            LineSegment s;
            s.read();
            s.print();
            cout << fixed << setprecision(1) << s.length() << '\n';
            cout << s.angle() << '\n';
            LineSegment s2(s);
            s.move(1, 1);
            s.print();
            s2.print(); 
        }
};