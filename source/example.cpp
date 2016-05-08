#include "window.hpp"
#include <utility>
#include <cmath>
#include <iostream>
#include <vector>

#include "vec2.hpp"
#include "mat2.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "color.hpp"

int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};
  std::vector<Circle> schniepi;
  schniepi.push_back(Circle(Vec2(0.5f, 0.5f), 0.1f, Color(1, 1, 0) ));

  std::vector<Rectangle> schniepi2;
  schniepi2.push_back(Rectangle(Vec2(0.5f, 0.5f), 0.1f, 0.1f, Color(1, 1, 0) ));

  while (!win.should_close()) {
    if (win.is_key_pressed(GLFW_KEY_ESCAPE)) {
      win.close();
    }
    

    auto m = win.mouse_position();
    Vec2 a = Vec2(m.first, m.second);

    
   
    
    if (schniepi2[0].Rectangle::is_inside(a))
    {
      schniepi2[0].draw(win, Color{0.0f, 0.0f, 1.0f});
    }
    else
      schniepi2[0].draw(win, Color{});

   
    
    if (schniepi[0].Circle::is_inside(a))
    {
      schniepi[0].draw(win, Color{0.38f, 1.0f, 1.0f});
    }
    else
      schniepi[0].draw(win, Color{});




    /*
    auto t = win.get_time();

    float x1{0.5f + 0.5f * std::sin(t)};
    float y1{0.5f + 0.5f * std::cos(t)};

    float x2{0.5f + 0.5f * std::sin(2.0f*t)};
    float y2{0.5f + 0.5f * std::cos(2.0f*t)};

    float x3{0.5f + 0.5f * std::sin(t-10.f)};
    float y3{0.5f + 0.5f * std::cos(t-10.f)};

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);
  
   
    win.draw_line(0.1f, 0.1f, 0.8f,0.1f, 1.0,0.0,0.0);

    win.draw_line(0.0f, m.second, 0.01f, m.second, 0.0, 0.0, 0.0);
    win.draw_line(0.99f, m.second,1.0f, m.second, 0.0, 0.0, 0.0);

    win.draw_line(m.first, 0.0f, m.first, 0.01f, 0.0, 0.0, 0.0);
    win.draw_line(m.first, 0.99f,m.first, 1.0f, 0.0, 0.0, 0.0);
    */
    win.update();
  }
  
  return 0;
}
