#include <bits/stdc++.h>
#define fl ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define lin signed main()
using namespace std;
class Point {
private:
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    void inp() {
        cout << "Nhap x va y: ";
        cin >> x >> y;
    }
    void out() const {
        cout << "Toa do: (" << x << ", " << y << ")";
    }
    int getX() const { return x; }
    int getY() const { return y; }
};
class LineSegment {
private:
    Point d1, d2;
public:
    // d1(8,5), d2(1,0)
    LineSegment() : d1(8, 5), d2(1, 0) {}
    // LineSegment(Point d1, Point d2)
    LineSegment(Point d1, Point d2) : d1(d1), d2(d2) {}
    // LineSegment(int x1, int y1, int x2, int y2)
    LineSegment(int x1, int y1, int x2, int y2) : d1(x1, y1), d2(x2, y2) {}
    // LineSegment(LineSegment S)
    LineSegment(const LineSegment& S) : d1(S.d1.getX(), S.d1.getY()), d2(S.d2.getX(), S.d2.getY()) {}
    void inp() {
        cout << "Nhap toa do cho diem d1:" << '\n';
        d1.inp();
        cout << "Nhap toa do cho diem d2:" << '\n';
        d2.inp();
    }
    void out() {
        cout << "Doan thang: d1";
        d1.out();
        cout << " - d2";
        d2.out();
        cout << '\n';
    }
};
lin {
    fl;
    LineSegment seg1;
    cout << "Mac dinh: ";
    seg1.out();
    Point a(2, 3), b(5, 7);
    LineSegment seg2(a, b);
    cout << "2 Point: ";
    seg2.out();
    LineSegment seg3(1, 1, 4, 4);
    cout << "4 int: ";
    seg3.out();
    LineSegment seg4(seg3);
    cout << "Sao chep: ";
    seg4.out();
}