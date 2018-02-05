//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.10
// 内容　：Color
//-------------------------------------------------------
#include <Color\color.h>

Color::Color(Math::Vector3 vector)
{
	r = (int)vector.x;
	g = (int)vector.y;
	b = (int)vector.z;
	a = 255;

	Clamp();
}

Color::Color(Math::Vector3 vector, int a)
{
	r = (int)vector.x;
	g = (int)vector.y;
	b = (int)vector.z;
	a = a;

	Clamp();
}

Color::Color(int r, int g, int b)
	:r(r), g(g), b(b), a(255)
{
	Clamp();
}

Color::Color(float r, float g, float b)
	: r((int)(r * 255)), g((int)(g * 255)), b((int)(b * 255)), a(255)
{
	Clamp();
}

Color::Color(int r, int g, int b, int a)
	: r(r), g(g), b(b), a(a)
{
	Clamp();
}

Color::Color(float r, float g, float b, float a)
	: r((int)(r * 255)), g((int)(g * 255)), b((int)(b * 255)), a((int)(a * 255))
{
	Clamp();
}

Color::Color(const Color& other)
	: r(other.r), g(other.g), b(other.b), a(other.a)
{
	Clamp();
}

Color::~Color()
{
}

Color Color::Lerp(Color color1, Color color2, float amount)
{
	color1.r += (int)((color2.r - color1.r) * amount);
	color1.g += (int)((color2.g - color1.g) * amount);
	color1.b += (int)((color2.b - color1.b) * amount);
	color1.a += (int)((color2.a - color1.a) * amount);
	return color1;
}

Color Color::Multiply(Color color, float scale)
{
	return (color * scale);
}

bool Color::Equals(Color other)
{
	return *this == other;
}

void Color::Clamp()
{
	r = (r > 255) ? 255 : r;
	g = (g > 255) ? 255 : g;
	b = (b > 255) ? 255 : b;
	a = (a > 255) ? 255 : a;

	r = (r < 0) ? 0 : r;
	g = (g < 0) ? 0 : g;
	b = (b < 0) ? 0 : b;
	a = (a < 0) ? 0 : a;
}

float Color::R()
{
	return r / 255.0f;
}
float Color::G()
{
	return g / 255.0f;
}
float Color::B()
{
	return b / 255.0f;
}
float Color::A()
{
	return a / 255.0f;
}