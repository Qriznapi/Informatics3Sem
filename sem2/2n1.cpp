#include <iostream>
#include "point.hpp"

using std::cout;
using std::endl;

class Circle {
private:
    Point center;
    float radius;

public:
    Circle(const Point& c, float r) {
        center = c;
        radius = r;
    }

    Circle() {
        center = (Point(0, 0));
        radius = 1;
    }

    Circle(const Circle& circle) {
        center = circle.center, radius = circle.radius;
    }

    void setRadius(float r) {
        radius = r;
        if (r < 0)
            radius = 0;
    }
    void setCenter(Point c) {
        this->center = c;
    }

    float getRadius() const {
        return radius;
    }

    Point getCenter() const {
        return center;
    }

    float area() const {
        return 3.14 * radius * radius;
    }

    float distance(const Point& p) const {
        float distToCenter = center.distance(p);
        return std::max(0.0f, distToCenter - radius);
    }

    bool isColliding(const Circle& c) const {
        float R = center.distance(c.center);
        return R <= (radius + c.radius);
    }

    void move(const Point& p) {
        center = center + p;
    }
};

int main()
{
	Point p = {7, -1};
	Point q = {-4, 2};
	cout << "p = " << p << endl;
	cout << "q = " << q << endl;
	cout << "p + q = " << p + q << endl;


	Circle a({4, 1}, 3);
	Circle b;

	cout << "Circle a: center: " << a.getCenter() << " radius: " << a.getRadius() << endl;
	cout << "Circle b: center: " << b.getCenter() << " radius: " << b.getRadius() << endl;

	cout << "Area of a = " << a.area() << endl;
	cout << "Distance from point p to circle a = " << a.distance(p) << endl;


	cout << "Collisions:" << endl;
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;


	cout << "Moving b by {1, 1}:" << endl;
	b.move({1, 1});
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;

}
