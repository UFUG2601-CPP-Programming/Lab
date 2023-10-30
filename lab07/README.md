# Lab 07 - Using Class to Solve Problems

## Our Goal in Lab 07

1. Learn to use the concept of class to solve problems.

## Abstraction Class - A way to think

### 0. Problem: Intersection of Two Rectangles with Edges Paralleled to Coordinate Axis

![Intersection of Two Rectangles](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Screenshot-16.png)

```
Sample Input:
(x1, y1), (x2, y2) -> Rectangle 1
(x3, y3), (x4, y4) -> Rectangle 2
```

### 1. Define a Class of Point

```cpp
class Point{
public:
    double x, y;
    // Build a point from its coordinate
    Point(){};
    Point(double x, double y) : x(x), y(y){};
    // Some computations for points
    double distance_to(const Point &p);
};
```

### 2. Define a Class of Line

```cpp
// After that, lines can be constructed from the points
class Line{
public:
    // We also know that two points determine a line
    Point p1, p2;
    Line(){};
    Line(Point p1, Point p2) : start(p1), end(p2){};
    // Some basic values and operations for lines
    double length();
    Point intersect_with(const Line &l);
};
```
(Optional) Thinking Time: What happens if no intersection point between 2 points? How to define an empty Point?

### 3. Define a Class of Rectangle

```cpp
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
    Rectangle overlap_with(Rectangle const & r);
};
```

## Task 1: Complete the Problem On OJ

1. Use learned knowledge about classes and structs to finish problem 009 on OJ.
2. Submit it to the contest during the lab session.

```cpp
#include <iostream>
#include <optional>
#include <math.h>
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

};
// After that, lines can be constructed from the points
class Line{
public:
    // We also know that two points determine a line
    Point start, end;
    Line(){};
    Line(Point start, Point end) : start(start), end(end){};
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
        // TODO
    };
    double area(){
        //TODO
    };

    // and some functions too
    Rectangle intersect_with(Rectangle const &r){
        //TODO
    }
};

// TODO: Implement all the functions and test them
int main(){
    double a_x, a_y, b_x, b_y;
    double c_x, c_y, d_x, d_y;
    cin >> a_x >> a_y >> b_x >> b_y;
    cin >> c_x >> c_y >> d_x >> d_y;
    Rectangle r1(Point(a_x, a_y), Point(b_x, b_y));
    Rectangle r2(Point(c_x, c_y), Point(d_x, d_y));
    Rectangle overlap_r;
    overlap_r = r1.intersect_with(r2);
    cout<<overlap_r.area()<<endl;
    
    return 0;
}
```


## Thinking Time

- How to define an empty variable by using a C++ library? (Introduce optional\<T\>)

## Additional Contents
### The usage of `optional<T>`
`optional<T>` is a class introduced since the C++ standard of **C++17**. If you want to use this class, please make sure that your compiler is set to this standard.

The class can be used to represent a value that may or may not be present. 

```cpp
optional<Point> intersect_with(const Line& l) {
  // Calculate the intersection point of two line
  double x1 = p1.x; 
  double y1 = p1.y;
  double x2 = p2.x;
  double y2 = p2.y;
  
  double x3 = l.p1.x;
  double y3 = l.p1.y;
  double x4 = l.p2.x; 
  double y4 = l.p2.y;
  
  double d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
  if (d == 0) {
    // If there is no intersection point, two lines are parallel
    return std::nullopt; 
  }

  double xi = ((x3 - x4) * (x1 * y2 - y1 * x2) - (x1 - x2) * (x3 * y4 - y3 * x4)) / d;
  double yi = ((y3 - y4) * (x1 * y2 - y1 * x2) - (y1 - y2) * (x3 * y4 - y3 * x4)) / d;

  // return the intersection point
  return Point{xi, yi};
}
```