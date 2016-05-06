#define CIRCLE_HPP
#ifndef RECTANGLE_HPP

#include "vec2.hpp"



class Circle 
{
  public:
    Circle();
    Circle(Vec2 const& ctr, float r ,Color const& clr);

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