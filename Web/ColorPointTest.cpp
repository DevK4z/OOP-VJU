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
        void print() {
            cout << "(" << x << ", " << y << ")";
        }
        void move(int dx, int dy) {
            x += dx;
            y += dy;
        }
        int getX() {
            return x;
        }
        int getY() {
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
        ColorPoint(): Point(), color("xanh") {}
        ColorPoint(int x, int y, string c):  Point(x, y), color(c) {}
        void read() {
            Point::read();
            cin >> color;
        }
        void print() {
            Point::print();
            cout << ": " << color << '\n';
        }
};

class ColorPointTest {
    public:
        void testCase() {
            ColorPoint c1;
            ColorPoint c2;
            c1.print();
            c2.read();
            c2.print();
            ColorPoint c3(c2);
            c2.move(5, 5);
            c2.print();
            c3.print();
        }
};