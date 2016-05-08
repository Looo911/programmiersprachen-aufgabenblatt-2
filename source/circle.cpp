#include "circle.hpp"
#include "vec2.hpp"
#include <cmath>
#include "window.hpp"


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


float circumference() const
{
	return((2*radius()*M_PI));
}
