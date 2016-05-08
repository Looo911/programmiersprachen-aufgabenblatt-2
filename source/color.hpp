#ifndef COLOR_HPP
#define COLOR_HPP


inline float minmax (float d)
{
	 d = (d <= 0 || d > 1) ? 0 : d;
	 return d;
}

struct Color
{	
	float r;
	float g;
	float b;
	
	Color():
	r{0.0f},
	g{0.0f},
	b{0.0f}
	{}

	Color(float x):
	r{minmax(x)},
	g{minmax(x)},
	b{minmax(x)}
	{}


	Color(float a, float b, float c):
	r{minmax(a)},
	g{minmax(b)},
	b{minmax(c)}
	{}
	

};
#endif