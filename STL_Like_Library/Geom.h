#include <stdio.h>

class Point2d
{
public:
	Point2d();
	Point2d(double x, double y);
	void printSelf() { std::cout << "I am Point2d" << std::endl; }

private:
	double mX;
	double mY;
};

Point2d::Point2d(double x, double y)
	:mX(x), mY(y)
{
}

class Line2d
{
public:
	Line2d(Point2d pt1, Point2d pt2);
	void printSelf() { std::cout << "I am Line2d" << std::endl; }

private:
	Point2d mPt1;
	Point2d mPt2;
};

Line2d::Line2d(Point2d pt1, Point2d pt2)
	:mPt1(pt1), mPt2(pt2)
{
}
