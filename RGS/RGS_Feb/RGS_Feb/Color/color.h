//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.10
// 内容　：Color
//-------------------------------------------------------
#pragma once
#include <Math\vector3.h>

struct Color
{
public:
	Color(Math::Vector3 vector);
	Color(Math::Vector3 vector, int a);
	Color(int r, int g, int b);
	Color(float r, float g, float b);
	Color(int r, int g, int b, int a);
	Color(float r, float g, float b, float a);
	Color(const Color&);
	~Color();

	///<summary>Lerp</summary>
	Color Lerp(Color color1, Color color2, float amount);
	///<summary>掛け算</summary>
	Color Multiply(Color color, float scale);

	///<summary>同じ色の場合はTrue</summary>
	bool Equals(Color other);

	///<summary>Red（0.0f～1.0f）</summary>
	float R();
	///<summary>Green（0.0f～1.0f）</summary>
	float G();
	///<summary>Blue（0.0f～1.0f）</summary>
	float B();
	///<summary>Alpha（0.0f～1.0f）</summary>
	float A();

	friend static Color operator *(Color value, float scale)
	{
		value.r = (int)(value.r * scale);
		value.g = (int)(value.g * scale);
		value.b = (int)(value.b * scale);
		value.a = (int)(value.a * scale);
		value.Clamp();
		return value;
	}

	friend static Color operator *(float scale, Color value)
	{
		value.r = (int)(value.r * scale);
		value.g = (int)(value.g * scale);
		value.b = (int)(value.b * scale);
		value.a = (int)(value.a * scale);
		value.Clamp();
		return value;
	}

	friend static bool operator ==(Color a, Color b)
	{
		return a.r == b.r && a.g == b.g && a.b == b.b && a.a == b.a;
	}

	friend static bool operator !=(Color a, Color b)
	{
		return !(a == b);
	}

private:
	void Clamp();		//（0～255）にする

public:
	int r;		//Red（0～255）
	int g;		//Green（0～255）
	int b;		//Blue（0～255）
	int a;		//Alpha（0～255）
};