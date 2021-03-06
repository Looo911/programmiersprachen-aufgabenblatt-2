#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP


#include "mat2.hpp"
#include "vec2.hpp"
#include "window.hpp"
#include "color.hpp"


class Rectangle 
{
  public:
    Rectangle();
    Rectangle(Vec2 const& p, float w, float h, Color const& clr);

    float circumference() const;
    void draw(Window const& wndw, Color const& clr) const; 
    bool is_inside(Vec2 const& mp);


   //set 
    void point(Vec2 const& pnt);
    void width(float w);
    void height(float h);
    void color(Color const& clr);

    //get
    Vec2 point() const ;
    float width() const;
    float height() const;
    Color color() const;

  private:
    Vec2 point_;
    float width_;
    float height_;
    Color color_;
};

#endif
