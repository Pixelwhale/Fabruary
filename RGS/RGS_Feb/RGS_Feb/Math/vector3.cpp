//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：昔作ったものをそのまま持ってきた
// 内容　：Vector3
//-------------------------------------------------------
#include "vector3.h"
#include <math.h>

using namespace Math;
using namespace std;

Vector3::Vector3()
	:x(0), y(0), z(0)
{
}

Vector3::Vector3(float x, float y, float z)
	:x(x), y(y), z(z)
{
}

Vector3::Vector3(const Vector3& other)
	:x(other.x), y(other.y), z(other.z)
{
}

float Vector3::lengthSqrt() const
{
	return x * x + y * y + z * z;
}

float Vector3::length() const
{
	return (float)sqrt(x * x + y * y + z * z);
}

Vector3& Vector3::normalize()
{
	float len;
	if((len = length()) != 0)
	{
		*this /= len;
	}
	return *this;
}

float Vector3::dot(const Vector3& v) const
{
	return x * v.x + y * v.y + z * v.z;
}

Vector3 Vector3::cross(const Vector3& v) const
{
	return Vector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

Vector3 Vector3::operator+ () const
{
	return *this;
}

Vector3 Vector3::operator- () const
{
	return Vector3(-x, -y, -z);
}

Vector3& Vector3::operator+= (const Vector3& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

Vector3& Vector3::operator-= (const Vector3& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

Vector3& Vector3::operator*= (float s)
{
	x *= s;
	y *= s;
	z *= s;
	return *this;
}

Vector3& Vector3::operator/= (float s)
{
	x /= s;
	y /= s;
	z /= s;
	return *this;
}

Vector3 Vector3::Clamp(const Vector3& v, const Vector3& min, const Vector3& max) 
{
	Vector3 result(v);
	result.x = (result.x < min.x) ? min.x : result.x;
	result.x = (result.x > max.x) ? max.x : result.x;
	result.y = (result.y < min.y) ? min.y : result.y;
	result.y = (result.y > max.y) ? max.y : result.y;
	result.z = (result.z < min.z) ? min.z : result.z;
	result.z = (result.z > max.z) ? max.z : result.z;

	return result;
}