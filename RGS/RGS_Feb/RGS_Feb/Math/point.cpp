//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.8
// 内容　：Point
//-------------------------------------------------------
#include <Math\point.h>
#include <math.h>

using namespace Math;
using namespace std;

Point::Point()
	:x(0), y(0)
{
}

Point::Point(int x, int y)
	: x(x), y(y)
{
}

Point::Point(const Point& other)
	: x(other.x), y(other.y)
{
}

float Point::length() const
{
	return (float)sqrt(x * x + y * y);
}

int Point::lengthSqrt() const
{
	return x * x + y * y;
}


Point Point::operator+ () const
{
	return *this;
}

Point Point::operator- () const
{
	return Point(-x, -y);
}

Point& Point::operator+= (const Point& v)
{
	x += v.x;
	y += v.y;
	return *this;
}

Point& Point::operator-= (const Point& v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}

Point& Point::operator*= (float s)
{
	x = (int)(x * s);
	y = (int)(y * s);
	return *this;
}

Point& Point::operator/= (float s)
{
	x = (int)(x / s);
	y = (int)(x / s);
	return *this;
}

Point Point::Clamp(const Point& v, const Point& min, const Point& max)
{
	Point result(v);
	result.x = (result.x < min.x) ? min.x : result.x;
	result.x = (result.x > max.x) ? max.x : result.x;
	result.y = (result.y < min.y) ? min.y : result.y;
	result.y = (result.y > max.y) ? max.y : result.y;

	return result;
}