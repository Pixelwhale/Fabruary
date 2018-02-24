//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：昔作ったものをそのまま持ってきた
// 内容　：Vector2
//-------------------------------------------------------
#pragma once

namespace Math
{
	struct Vector2
	{
	public:
		Vector2();
		Vector2(float x);
		Vector2(float x, float y);
		Vector2(const Vector2& other);

		float    length() const;
		float    lenghtSqrt() const;
		Vector2& normalize();
		float    dot(const Vector2& v) const;
		Vector2  operator + () const;
		Vector2  operator - () const;

		Vector2&  operator += (const Vector2& v);
		Vector2&  operator -= (const Vector2& v);
		Vector2&  operator *= (float s);
		Vector2&  operator /= (float s);

		Vector2 Clamp(const Vector2& v, const Vector2& min, const Vector2& max);
		Vector2 Lerp(const Vector2& v1, const Vector2& v2, float rate);

		friend const Vector2 operator + (const Vector2& v1, const Vector2& v2)
		{
			return Vector2(v1.x + v2.x, v1.y + v2.y);
		}
		friend const Vector2 operator - (const Vector2& v1, const Vector2& v2)
		{
			return Vector2(v1.x - v2.x, v1.y - v2.y);
		}
		friend const Vector2 operator * (const Vector2& v, float s)
		{
			return Vector2(v.x * s, v.y * s);
		}
		friend const Vector2 operator * (float s, const Vector2& v)
		{
			return Vector2(v.x * s, v.y * s);
		}
		friend const Vector2 operator / (const Vector2& v, float s)
		{
			return Vector2(v.x / s, v.y / s);
		}

	public:
		float x;
		float y;
	};
}