#include "circle.hpp"
#include "vec2.hpp"
#include "mat2.hpp"
#include <cmath>
#include "window.hpp"
#include "color.hpp"


Circle::Circle():
    center_{Vec2()},
    radius_{1.0},
    color_{0.0, 0.0, 0.0} 
    {}
        

Circle::Circle(Vec2 const& ctr, float r, Color const& clr) :
    center_{ctr},
    radius_{r},
    color_{clr}
    {}


void Circle::radius(float r) 
{radius_=r;}

void Circle::center(Vec2 const& ctr) 
{center_=ctr;}

void Circle::color(Color const& clr) 
{color_=clr;}


Vec2 Circle::center() const 
{return center_;}

float Circle::radius() const 
{return radius_;}

Color Circle::color() const 
{return color_;}


float Circle::circumference() const
{	
	float r = radius();
	return((2*r*M_PI));
}

void Circle::draw(Window const& wndw, Color const& clr) const
{	
	Vec2 a= Vec2(radius(),0)+center();
	Vec2 b;
	for (int i = 1; i <= 500; ++i)
	{
		b = make_rotation_mat2(2*M_PI*(i+1)/500) * Vec2(radius(),0)+center();
		wndw.draw_line(a.x, a.y, b.x, b.y, clr.r, clr.b, clr.g);
		a = b;
	}
}


 float Circle::distance_to_center(Vec2 const& mp)
 {
 	return sqrt(pow(mp.x-center().x, 2) + pow(mp.y-center().y, 2));
 }



bool Circle::is_inside(Vec2 const& mp)
{
    if (distance_to_center(mp) >= radius())
    {
        return false;
    }

    return true;
}
