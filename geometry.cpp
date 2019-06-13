#include "geometry1.h"
#include <cstddef>
#include <cmath>


/************** POINT ARRAY *************************/

PointArray::PointArray() {
    size = 0;
    points = new Point[0];
}

PointArray::PointArray(const Point ptsToCopy[], const int toCopySize) {
    size = toCopySize;
    points = new Point[toCopySize];
    for (int i = 0; i < size; ++i)
        points[i] = ptsToCopy[i];
}

PointArray::~PointArray() {
    delete[] points;
}

void PointArray::resize(int newSize) {
    Point *newArr = new Point[newSize];
    int minSize = (newSize > size ? size : newSize);
    for (int i = 0; i < minSize; ++i)
        newArr[i] = points[i];
    delete[] points;
    size = newSize;
    points = newArr;
}


void PointArray::push_back(const Point &p) {
    resize(size + 1);
    points[size - 1] = p;
}


void PointArray::clear() {
    resize(0);
}

Point* PointArray::get(const int pos) {
    return pos >= 0 && pos < size ? points + pos : NULL;
}

const Point* PointArray::get(const int pos) const
{
    return pos >= 0 && pos < size ? points + pos : NULL;
}


/************** POLYGON *************************/

int Polygon::numPolygons = 0;


/*****************TRIANGLE*************************/
Point consPoints[4];


Point *updateConstructorPoints(const Point &p1, const Point &p2, const Point &p3, const Point &p4 = Point(0, 0)) {

    consPoints[0] = p1;
    consPoints[1] = p2;
    consPoints[2] = p3;
    consPoints[3] = p4;

    return consPoints;

}

Triangle::Triangle(const Point &a, const Point &b, const Point &c)
        : Polygon(updateConstructorPoints(a, b, c), 3) {}

double Triangle::area() const {

    int x2x1 = pArr.get(1)->getX() - pArr.get(0)->getX(),
            y2y1 = pArr.get(1)->getY() - pArr.get(0)->getY(),
            x3x2 = pArr.get(2)->getX() - pArr.get(1)->getX(),
            y3y2 = pArr.get(2)->getY() - pArr.get(1)->getY(),
            x3x1 = pArr.get(2)->getX() - pArr.get(0)->getX(),
            y3y1 = pArr.get(2)->getY() - pArr.get(0)->getY();

    double a = std::sqrt(x2x1 * x2x1 + y2y1 * y2y1),
            b = std::sqrt(x3x2 * x3x2 + y3y2 * y3y2),
            c = std::sqrt(x3x1 * x3x1 + y3y1 * y3y1);

    double s = (a + b + c) / 2;

    return std::sqrt(s * (s - a) * (s - b) * (s - c));
};



