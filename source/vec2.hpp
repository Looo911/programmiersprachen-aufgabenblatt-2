#ifndef VEC2_HPP
#define VEC2_HPP

class Vec2
{
public:
	//Konstruktoren
	Vec2();
	Vec2(float a, float b);
	Vec2& operator+=(Vec2 const& v);
	Vec2& operator-=(Vec2 const& v);
	Vec2& operator*=(float v);
	Vec2& operator/=(float v);


	//Membervariablen
	float x;
	float y;
};



#endif