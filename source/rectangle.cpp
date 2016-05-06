#include "rectangle.hpp"
#include "mat2.hpp"
#include "vec2.hpp"
#include <cmath>
#include <math.h>
#include "window.hpp"
#include "color.hpp"


Rectangle::Rectangle():
	point_{Vec2()},
    width_{1},
    height_{1},
    color_{0.0,0.0,0.0}
    {}

rectangle::Rectangle(Vec2 const& p, float w, float h, Color const& clr):
	point_{p},
    width_{w},
    height_{h},
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
