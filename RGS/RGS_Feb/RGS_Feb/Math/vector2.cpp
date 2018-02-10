//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：昔作ったものをそのまま持ってきた
// 内容　：Vector2
//-------------------------------------------------------
#include "vector2.h"
#include <math.h>

using namespace Math;
using namespace std;

Vector2::Vector2()
	:x(0), y(0)
{
}

Vector2::Vector2(float x, float y)
	: x(x), y(y)
{
}

Vector2::Vector2(const Vector2& other)
	: x(other.x), y(other.y)
{
}

float Vector2::length() const
{
	return (float)sqrt(x * x + y * y);
}

float Vector2::lenghtSqrt() const
{
	return x * x + y * y;
}

Vector2& Vector2::normalize()
{
	float len;
	if ((len = length()) != 0)
	{
		*this /= len;
	}
	return *this;
}

float Vector2::dot(const Vector2& v) const
{
	return x * v.x + y * v.y;
}

Vector2 Vector2::operator+ () const
{
	return *this;
}

Vector2 Vector2::operator- () const
{
	return Vector2(-x, -y);
}

Vector2& Vector2::operator+= (const Vector2& v)
{
	x += v.x;
	y += v.y;
	return *this;
}

Vector2& Vector2::operator-= (const Vector2& v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}

Vector2& Vector2::operator*= (float s)
{
	x *= s;
	y *= s;
	return *this;
}

Vector2& Vector2::operator/= (float s)
{
	x /= s;
	y /= s;
	return *this;
}

Vector2 Vector2::Clamp(const Vector2& v, const Vector2& min, const Vector2& max)
{
	Vector2 result(v);
	result.x = (result.x < min.x) ? min.x : result.x;
	result.x = (result.x > max.x) ? max.x : result.x;
	result.y = (result.y < min.y) ? min.y : result.y;
	result.y = (result.y > max.y) ? max.y : result.y;

	return result;
}