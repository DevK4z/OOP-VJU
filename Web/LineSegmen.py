import math

class Point:
    def __init__(self, x=0, y=1):
        self.__x = x
        self.__y = y
        
    def read(self):
        self.__x, self.__y = map(int, input().split())
        
    def print(self):
        print(f"({self.__x}, {self.__y})")
        
    def move(self, dx, dy):
        self.__x += dx
        self.__y += dy
        
    def getX(self):
        return self.__x
        
    def getY(self):
        return self.__y
        
    def distance(self, p=None):
        if p is None:
            return math.sqrt(self.__x * self.__x + self.__y * self.__y)
        return math.sqrt((self.__x - p.__x) ** 2 + (self.__y - p.__y) ** 2)

class LineSegment:
    def __init__(self, *args):
        if len(args) == 0:
            self.__d1 = Point(8, 5)
            self.__d2 = Point(1, 0)
            
        elif len(args) == 1 and isinstance(args[0], LineSegment):
            p1 = args[0].__d1
            p2 = args[0].__d2
            self.__d1 = Point(p1.getX(), p1.getY())
            self.__d2 = Point(p2.getX(), p2.getY())
            
        elif len(args) == 2 and isinstance(args[0], Point) and isinstance(args[1], Point):
            self.__d1 = args[0]
            self.__d2 = args[1]
            
        elif len(args) == 4:
            self.__d1 = Point(args[0], args[1])
            self.__d2 = Point(args[2], args[3])
            
        else:
            raise ValueError("Tham số truyền vào không hợp lệ!")

    def read(self):
        # Đọc tọa độ của 2 đầu mút theo định dạng: x1 y1 x2 y2
        data = input().split()
        if len(data) >= 4:
            x1, y1, x2, y2 = map(int, data[:4])
            self.__d1 = Point(x1, y1)
            self.__d2 = Point(x2, y2)

    def print(self):
        # Hiển thị tọa độ hai đầu mút của đoạn thẳng theo mẫu: [(x1, y1); (x2, y2)]
        print(f"[({self.__d1.getX()}, {self.__d1.getY()}); ({self.__d2.getX()}, {self.__d2.getY()})]")

    def move(self, dx, dy):
        # Tịnh tiến đồng thời 2 đầu mút của đoạn thẳng
        self.__d1.move(dx, dy)
        self.__d2.move(dx, dy)

    def length(self):
        # Tính độ dài đoạn thẳng (khoảng cách giữa d1 và d2)
        return self.__d1.distance(self.__d2)

    def angle(self):
        # Tính góc của đoạn thẳng so với trục hoành (d1 là gốc, d2 là ngọn)
        dx = self.__d2.getX() - self.__d1.getX()
        dy = self.__d2.getY() - self.__d1.getY()
        
        # Tính góc bằng radian sau đó chuyển sang độ
        rad = math.atan2(dy, dx)
        deg = math.degrees(rad)
        
        # Làm tròn đến số nguyên gần nhất và đảm bảo nằm trong khoảng [0, 359]
        return int(round(deg)) % 360