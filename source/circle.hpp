#ifndef CIRCLE_HPP
#define CIRCLE_HPP


#include <cmath>
#include "mat2.hpp"
#include "vec2.hpp"
#include "window.hpp"
#include "color.hpp"




class Circle 
{
  public:
    Circle();
    Circle(Vec2 const& ctr, float r ,Color const& clr);
    float circumference() const;
    void draw(Window const& wndw, Color const& clr) const; 
    float distance_to_center(Vec2 const& mp);
    bool is_inside(Vec2 const& mp);

    //set
    void radius(float r); 
    void center(Vec2 const& ctr);
    void color(Color const& clr);

    //get
    Vec2 center() const ;
    float radius() const;
    Color color() const;


  private:
    Vec2 center_;
    float radius_;
    Color color_;
};
#endif