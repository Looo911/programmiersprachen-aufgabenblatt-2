#include <iostream>
#include <cmath>
#include "mat2.hpp"
#include "vec2.hpp"

Mat2::Mat2() :
a{1.0f},
b{0.0f},
c{0.0f},
d{1.0f}
{}

Mat2::Mat2(float v, float w, float x, float y) :
a{v},
b{w},
c{x},
d{y}
{}

Mat2& Mat2::operator *=( Mat2 const & m )
{
	float an = a*m.a + b*m.c;
	float bn = a*m.b + b*m.d;
	float cn = c*m.a + d*m.c;
	float dn = c*m.b + d*m.d;

	a = an;
	b = bn;
	c = cn;
	d = dn;

	return *this;
}

Vec2 operator *(Mat2 const & m , Vec2 const & v)
{
	return Vec2((m.a*v.x + m.b*v.y), (m.c*v.x + m.d*v.y));
}

/*
Vec2 operator *(Vec2 const & v , Mat2 const & m)
{
	std::cout << "Das ist keine zulässige Operation!" << std::endl;		// hier nochmal drüber schauen!
	return *this;
}


Vec2 operator *(Vec2 const & v , Mat2 const & m)
{
	return Vec2((m.a*v.x + m.b*v.y), (m.c*v.x + m.d*v.y))
}
*/

Mat2 operator*(float v,Mat2 const& u)
{
	return(Mat2((u.a*v),(u.b*v),(u.c*v),(u.d*v)));
}


Mat2 inverse (Mat2 const & m )
{
	return (1/(m.a*m.d - m.b*m.c) * Mat2(m.d,-m.b,-m.c,m.a));
}

Mat2 transpose (Mat2 const & m )
{
	return(Mat2(m.a,m.c,m.b,m.d));
}

Mat2 make_rotation_mat2(float phi)
{
	return Mat2(std::cos(phi), -(std::sin(phi)), std::sin(phi), std::cos(phi));
}