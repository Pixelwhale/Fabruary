//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.8
// 内容　：Point
//-------------------------------------------------------
#pragma once

namespace Math
{
	struct Point
	{
	public:
		Point();
		Point(int x, int y);
		Point(const Point& other);

		float length() const;
		int lengthSqrt() const;
		Point operator + () const;
		Point operator - () const;

		Point&  operator += (const Point& v);
		Point&  operator -= (const Point& v);
		Point&  operator *= (float s);
		Point&  operator /= (float s);

		Point Clamp(const Point& v, const Point& min, const Point& max);

		friend const Point operator + (const Point& v1, const Point& v2)
		{
			return Point(v1.x + v2.x, v1.y + v2.y);
		}
		friend const Point operator - (const Point& v1, const Point& v2)
		{
			return Point(v1.x - v2.x, v1.y - v2.y);
		}
		friend const Point operator * (const Point& v, float s)
		{
			return Point((int)(v.x * s), (int)(v.y * s));
		}
		friend const Point operator * (float s, const Point& v)
		{
			return Point((int)(v.x * s), (int)(v.y * s));
		}
		friend const Point operator / (const Point& v, float s)
		{
			return Point((int)(v.x / s), (int)(v.y / s));
		}

	public:
		int x;
		int y;
	};
}