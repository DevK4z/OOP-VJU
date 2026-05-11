import math

from Point import Point


class LineSegment:
    def __init__(self, *args):
        if len(args) == 0:
            self.__d1 = Point(8, 5)
            self.__d2 = Point(1, 0)
        elif len(args) == 1 and isinstance(args[0], LineSegment):
            segment = args[0]
            self.__d1 = Point(segment.__d1.getX(), segment.__d1.getY())
            self.__d2 = Point(segment.__d2.getX(), segment.__d2.getY())
        elif len(args) == 2 and all(isinstance(arg, Point) for arg in args):
            self.__d1, self.__d2 = args
        elif len(args) == 4 and all(isinstance(arg, int) for arg in args):
            x1, y1, x2, y2 = args
            self.__d1 = Point(x1, y1)
            self.__d2 = Point(x2, y2)
        else:
            raise TypeError("Invalid arguments for LineSegment")

    def read(self):
        x1, y1, x2, y2 = map(int, input().split())
        self.__d1 = Point(x1, y1)
        self.__d2 = Point(x2, y2)

    def print(self):
        print(f"[({self.__d1.getX()}, {self.__d1.getY()}); ({self.__d2.getX()}, {self.__d2.getY()})]")

    def move(self, dx, dy):
        self.__d1.move(dx, dy)
        self.__d2.move(dx, dy)

    def length(self):
        return self.__d1.distance(self.__d2)

    def angle(self):
        dx = self.__d2.getX() - self.__d1.getX()
        dy = self.__d2.getY() - self.__d1.getY()
        return int(round(math.degrees(math.atan2(dy, dx))) % 360)
