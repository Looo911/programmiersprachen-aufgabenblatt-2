#include "rectangle.hpp"
#include "mat2.hpp"
#include "vec2.hpp"
#include <cmath>
#include <math.h>
#include "color.hpp"
#include "window.hpp"



Rectangle::Rectangle():
	point_{Vec2()},
    width_{1},
    height_{1},
    color_{0.0,0.0,0.0}
    {}

Rectangle::Rectangle(Vec2 const& p, float w, float h, Color const& clr):
	point_{p},
    width_{w},
    height_{h},
    color_{clr}
    {}



void Rectangle::point(Vec2 const& pnt)
{point_=pnt;}

void Rectangle::width(float wdth) 
{width_=wdth;}

void Rectangle::height(float hght) 
{height_=hght;}

void Rectangle::color(Color const& clr) 
{color_=clr;}



Vec2 Rectangle::point() const 
{return point_;}

float Rectangle::width() const 
{return width_;}

float Rectangle::height() const 
{return height_;}

Color Rectangle::color() const 
{return color_;}




float Rectangle::circumference() const
{
    return( fabs(2*Rectangle::height())+fabs(2*width()));          //fabs, da sonst negative und pos. Werte addiert werden könnten.
}



void Rectangle::draw(Window const& wndw, Color const& clr) const
{
    // Rechte Linie
    wndw.draw_line(point().x, point().y, point().x, point().y+height(), clr.r, clr.g, clr.b);

    // Obere Linie
    wndw.draw_line(point().x, point().y+height(), point().x+width(), point().y+height(), clr.r, clr.g, clr.b);

    //Untere Linie
    wndw.draw_line(point().x, point().y, point().x+width(), point().y, clr.r, clr.g, clr.b);

    //Linke Linie
    wndw.draw_line(point().x+width(), point().y, point().x+width(), point().y+height(), clr.r, clr.g, clr.b);
}



bool Rectangle::is_inside(Vec2 const& mp)
{
    if (mp.x >= point().x+width() || mp.x <= point().x
        || mp.y >= point().y+height() || mp.y <= point().y)
    {
        return false;
    }

    return true;
}



