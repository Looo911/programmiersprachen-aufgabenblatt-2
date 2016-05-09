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
	bool operator ==(const Vec2& v)const{return((x == v.x) && (y == v.y));}

	//Membervariablen
	float x;
	float y;
};


Vec2 operator +( Vec2 const & u , Vec2 const & v );
Vec2 operator -( Vec2 const & u , Vec2 const & v );
Vec2 operator *( Vec2 const & v , float s );
Vec2 operator /( Vec2 const & v , float s );
Vec2 operator *( float s , Vec2 const & v );



#endif