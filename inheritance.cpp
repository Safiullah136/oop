#include <iostream>
using namespace std;

class Point {
    public:
    int x, y;

    void print_point();
};

void Point::print_point() {
    cout << '(' << x << ", " << y << ')' << endl;
}

// x------------------------x

class Shape {
    public:
    int num_points;
    Point *points;

    Shape();
    void set_points(Point *p);
    void show_shape();
    float get_area();
    ~Shape();
};

Shape::Shape() {
    cout << "In Shape Constructor ... " << endl;
    points = NULL;
    num_points = 0;
}

void Shape::set_points(Point *p) {           // should move this to Shape 
    points = p;     // same as this->points = p;
}

void Shape::show_shape() {
    Point *temp = points;
    for(int i = 0; i < num_points; i++) {
        temp->print_point();
        temp++;
    }
}

float Shape::get_area() {
    return -1.0;
}

Shape::~Shape() {
    cout << "In Shape Destructor ... " << endl;
    for(int i = 0; i < num_points; i++) {
        delete points;
        points++;
    } 

    points = NULL;
}

// x--------------------------x

class Triangle : public Shape {
    public:

    Triangle();
    void print_shape();
    float get_area();
};

Triangle::Triangle() {
    cout << "In Triangle Constructor ... " << endl;
    num_points = 3;
}

float Triangle::get_area() {
    cout << "Computing the area of a triangle ... " << endl;
    int x0, y0, x1, y1, x2, y2;
    Point *t = points;

    x0 = t->x;   y0 = t->y; t++;
    x1 = t->x;   y1 = t->y; t++;
    x2 = t->x;   y2 = t->y; 

    return abs(x0 * (y1 - y2) + x1 * (y2 - y0) + x2 * (y0 - y1) / 2);
}

// x--------------------------x

void create_shape() {
    Triangle *t = new Triangle;

    Point p1, p2, p3;
    p1.x = p1.y = 0;
    p2.x = 1; p2.y = 4;
    p3.x = 4; p3.y = 2;

    Point *points_of_triangle;

    points_of_triangle = new Point[3];
    points_of_triangle[0] = p1;
    points_of_triangle[1] = p2;
    points_of_triangle[2] = p3;

    t->set_points(points_of_triangle);
    t->show_shape();

    cout << "Area of t : " << t->get_area() << endl;
}

int main() {
    create_shape();
    
    return 0;
}

