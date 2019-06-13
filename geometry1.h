/***********************POINT ******************/

class Point {
    int x, y;

public:
    Point(int u = 0, int v = 0) : x(u), y(v) {}

    int getX() const { return x; }

    int getY() const { return y; }

    void setX(const int new_x) { x = new_x; }

    void setY(const int new_y) { y = new_y; }
};

/********************POINTARRAY***************/
class PointArray {
    int size;
    Point *points;

    void resize(int size);

public:
    PointArray();

    PointArray(const Point pts[], const int size);

    PointArray(const PointArray &pv);

    ~PointArray();

    void push_back(const Point &p);

    int getSize() const { return size; }

    void clear();

    Point *get(const int pos);

    const Point *get(const int pos) const;
};

/****************POLYGON*************/
class Polygon {
protected:
    PointArray pArr;
    static int numPolygons;

public:
    Polygon(const Point points[], const int size) : pArr(points, size) { ++numPolygons; }

    virtual double area() const = 0;

    const PointArray *getPoints() const { return &pArr; }
};

/****************TRIANGLE************/

class Triangle : public Polygon {
public:
    Triangle(const Point &a, const Point &b, const Point &c);

    virtual double area() const;
};























