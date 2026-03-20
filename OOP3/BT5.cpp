#include <bits/stdc++.h>
#define fl ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define lin signed main()
using namespace std;
class point {
    public :
        double x, y;
        point(double x = 0, double y = 0) : x(x), y(y) {}
};
// Hình chữ nhật được định nghĩa bởi tâm, chiều rộng và chiều cao
class rectangle {
    public :
        point center;
        double width, height;
        rectangle(double x = 0, double y = 0, double w = 0, double h = 0) : center(x, y), width(w), height(h) {}
        vector <point> corners() const {
            double half_w = width / 2.0;
            double half_h = height / 2.0;
            return {
                point(center.x - half_w, center.y - half_h), // Goc tren trai
                point(center.x + half_w, center.y - half_h), // Goc tren ph ai
                point(center.x + half_w, center.y + half_h), // Goc duoi phai
                point(center.x - half_w, center.y + half_h)  // Goc duoi trai
            };
        }
};
// Hình tròn được định nghĩa bởi tâm và bán kính
class circle {
    public :
        point center;
        double radius;
        circle(point center, double radius) : center(center), radius(radius) {}
};
// Hàm tính khoảng cách bình phương giữa 2 điểm (tránh sqrt để tăng hiệu suất)
double dist2(const point& a, const point& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
// Kiểm tra điểm có nằm trong hoặc trên vòng tròn không
bool point_in_circle(const point& p, const circle& c) {
    return dist2(p, c.center) <= c.radius * c.radius;
}
// Kiểm tra hình chữ nhật có nằm hoàn toàn trong vòng tròn không
bool rect_in_circle(const rectangle& r, const circle& c) {
    for (const auto& corner : r.corners()) {
        if (!point_in_circle(corner, c)) return false;
    }
    return true;
}
// Kiểm tra hình chữ nhật có giao với vòng tròn không
bool rec_circle_overlap(const rectangle& r, const circle& c) {
    double half_w = r.width / 2.0;
    double half_h = r.height / 2.0;
    double closest_x = max(r.center.x - half_w, min(c.center.x, r.center.x + half_w));
    double closest_y = max(r.center.y - half_h, min(c.center.y, r.center.y + half_h));
    return dist2(point(closest_x, closest_y), c.center) <= c.radius * c.radius;
}
lin { 
    fl;
    circle c(point(150, 150), 75); // Vòng tròn tâm (150, 150) bán kính 75
    point p1(150, 100), p2(230, 100); // p1 trong, p2 ngoài
    cout << "Diem p1 " << (point_in_circle(p1, c) ? "T" : "F") << '\n';
    cout << "Diem p2 " << (point_in_circle(p2, c) ? "T" : "F") << '\n';
    rectangle r1(140, 90, 10, 10), r2(100, 50, 300, 200); // r1 nhỏ nằm trong, r2 lớn giao với vòng tròn
    cout << "rect_in_circle(r1): " << (rect_in_circle(r1, c) ? "T" : "F") << '\n';
    cout << "rect_circle_overlap(r2): " << (rec_circle_overlap(r2, c) ? "T" : "F") << '\n';
}