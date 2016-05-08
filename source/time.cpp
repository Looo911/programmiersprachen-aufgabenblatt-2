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
  Circle schniepi{Circle(Vec2(0.5f, 0.5f), 0.41f, Color(0.38f, 1.0f, 1.0f))};

  while (!win.should_close()) {
	  if (win.is_key_pressed(GLFW_KEY_ESCAPE)) {
	    win.close();
	  }

	  


	  auto t = win.get_time();

	  Vec2 cntr = schniepi.center();
	  Vec2 second = Vec2(cntr.x + 0.4 *  std::sin(2*M_PI*t/60), cntr.y +0.4 * std::cos(2*M_PI*t/60));
	  Vec2 minute = Vec2(cntr.x + 0.36 *  std::sin(2*M_PI*t/3600), cntr.y + 0.36 * std::cos(2*M_PI*t/3600));
	  Vec2 hour = Vec2(cntr.x +  0.3 * std::sin(2*M_PI*t/21600), cntr.y + 0.3 * std::cos(2*M_PI*t/21600));

	  schniepi.draw(win, Color{});
	  win.draw_line(cntr.x, cntr.y, second.x, second.y, 0.4f, 0.3f, 1.f);
	  win.draw_line(cntr.x, cntr.y, minute.x, minute.y, 0.4f, 0.3f, 0.5f);
	  win.draw_line(cntr.x, cntr.y, hour.x, hour.y, 0.4f, 0.3f, 0.f);

	  win.update();
  }

  return 0;

}
