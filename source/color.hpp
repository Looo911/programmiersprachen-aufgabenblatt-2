#if !defined(COLOR_HPP)
#define COLOR_HPP

inline float minmax (float d)
{
	 d = (d <= 0 || d >= 1) ? 0;  
}

struct Color
{
	Color():
	r{0};
	g{0};
	b{0};
	{}

	Color(float x):
	r{minmax(x)};
	g{minmax(x)};
	b{minmax(x)};
	{}


	Color(float a, float b, float c):
	r{minmax(a)};
	g{minmax(b)};
	b{minmax(c)};
	{}

	float r;
	float g;
	float b;

};
#endif