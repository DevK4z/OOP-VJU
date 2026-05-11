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
            cout << "(" << x << ", " << y << ")";
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

class ColorPoint : public Point {
    private:
        string color;
    public:
        ColorPoint(): Point(), color("red") {}
        ColorPoint(int x, int y, string c): Point(x, y), color(c) {}
        void read() {
            Point::read();
            cin >> color;
        }
        void print() {
            Point::print();
            cout << ": " << color << '\n';
        }
};
