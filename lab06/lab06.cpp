#include <iostream>

using namespace std;

// In this code, we try to define classes for the basic concepts in geometry
// Let's start with the basic 2D spaces and try to complete the program

// The most basic concept in a 2D space is, of course, points.
class Point{
public:
    double x, y;
    // Build a point from its coordinate
    Point(){};
    Point(double x, double y) : x(x), y(y){};
    // Some computations for points
    double distance_to(const Point &p);
};

// After that, lines can be constructed from the points
class Line{
public:
    // We also know that two points determine a line
    Point start, end;
    Line(){};
    Line(Point start, Point end) : start(start), end(end){};
    // Some basic values and operations for lines
    double length();
    bool intersect_with(const Line &l);
};

// There are operations for two lines as well
Point intersection(const Line& l1, const Line& l2){
    Point intersect_point;

    // TODO: Calculate the intersection point
    return intersect_point;
}

// We also have shapes in 2D space, e.g. rectangles
class Rectangle{
public:
    // Two points are enough to define a rectangle
    Point a, b;
    // However, we need to give it 4 lines as the boundary
    Line h1, h2, w1, w2;
    Rectangle(){};
    Rectangle(Point a, Point b) : a(a), b(b){
        // Here we need to construct lines from the points
        // TODO: Complete the rest of the line definitions
        h1 = Line(Point(a.x, a.y), Point(a.x, b.y));
        h2 = Line(/* Fill Your Code Here */);
        w1 = Line(/* Fill Your Code Here */);
        w2 = Line(/* Fill Your Code Here */);
    };

    // For rectangles, we have more values
    double area();
    double perimeter();
    // and some functions too
    bool overlap_with(Rectangle const & r);
};

// Finally, we can get another rectangle from the overlapped area 
Rectangle overlap(const Rectangle & r1, const Rectangle & r2){
    // TODO: Complete this function
}


// TODO: Implement all the functions and test them

int main(){

    double a_x, a_y, b_x, b_y;
    double c_x, c_y, d_x, d_y;

    cin >> a_x >> a_y >> b_x >> b_y;
    cin >> c_x >> c_y >> d_x >> d_y;

    Rectangle r1(Point(a_x, a_y), Point(b_x, b_y));
    Rectangle r2(Point(c_x, c_y), Point(d_x, d_y));

    Rectangle overlap_r;

    overlap_r = overlap(r1, r2);

    cout << overlap_r.a.x << " " << overlap_r.a.y << endl;
    cout << overlap_r.b.x << " " << overlap_r.b.y << endl;

    return 0;
}