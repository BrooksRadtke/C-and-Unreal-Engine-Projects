#include <iostream>
#include <ostream>
#include <set>
#include <cmath>
#include <string>
using namespace std;

// Custom class representing 2D point
class Point2D
{
public:
	Point2D() = default;
	Point2D(double x, double y)
		: mX{ x }, mY{ y }{}
	double X() const { return mX; }
	double Y() const { return mY; }

	double Length() const
	{
		return std::hypot(mX, mY);
	}

	void SetXY(double x, double y)
	{
		mX = x;
		mY = y;
	}

private:
	double mX = 0.0;
	double mY = 0.0;
};

inline bool operator<(const Point2D& p1, const Point2D& p2)
{
	return p1.Length() < p2.Length();
}

std::ostream& operator<<(std::ostream& os, const std::set<Point2D>& points)
{
	os << "[";
	bool isFirst = true;
	for (const auto& p : points)
	{
		if (isFirst)
		{
			os << p;
			isFirst = false;
		}
		else
		{
			os << ", " << p;
		}
	}
}

int main()
{
	//using std::cout;

	std::set<Point2D> points{{ 20, 30 }, { 22, 33 }, { 2, 3 }};
	cout << " Initial set of points: \n";
	cout << " " << points << "\n\n";

	points.insert(Point2D{ 10, 20 });
	cout << " Inserting new point (10, 20): \n";
	cout << " " << points << "\n\n";
}