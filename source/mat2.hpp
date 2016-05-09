#ifndef MAT2_HPP
#define MAT2_HPP
#include "vec2.hpp"



class Mat2
{
public:
	Mat2();
	Mat2(float v, float w, float x, float y);

	Mat2 & operator *=( Mat2 const & m );

	float det () const
	{
		return(a*d - c*b);
	} ;

	float a;
	float b;
	float c;
	float d;
	bool operator ==(const Mat2& m){return ((a == m.a) &&(b == m.b)
                                        &&  (c == m.c) &&(d == m.d));}
};

Mat2 operator*(Mat2 const& m1, Mat2 const& m2);

Vec2 operator*(Mat2 const & m , Vec2 const & v);
Mat2 inverse (Mat2 const & m );
Mat2 transpose (Mat2 const & m );
Mat2 make_rotation_mat2(float phi);


#endif