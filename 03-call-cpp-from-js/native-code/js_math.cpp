#include <cmath>
#include <iostream>

#include <emscripten/bind.h>

namespace math {

class Point {
public:
  Point(double x, double y) : m_x(x), m_y(y) {
    std::cout << "Constructing a point with coordinates x=" << x
              << " and y=" << y << "." << std::endl;
  }

  double get_x() const { return m_x; }
  void set_x(double x) { m_x = x; }

  double get_y() const { return m_y; }
  void set_y(double y) { m_y = y; }

  std::string to_string() const {
    return "Point(" + std::to_string(get_x()) + ", " + std::to_string(get_y()) +
           ")";
  }

private:
  double m_x;
  double m_y;
};

double euclidean_distance_2d(const Point &lhs, const Point &rhs) {
  std::cout << "Calculating Euclidean distance between " << lhs.to_string()
            << " and " << rhs.to_string() << std::endl;
  return std::sqrt(std::pow(rhs.get_x() - lhs.get_x(), 2) +
                   std::pow(rhs.get_y() - lhs.get_y(), 2));
}

} // namespace math

EMSCRIPTEN_BINDINGS(js_math) {
  emscripten::class_<math::Point>("Point")
      .constructor<double, double>()
      .property("x", &math::Point::get_x, &math::Point::set_x)
      .property("y", &math::Point::get_y, &math::Point::set_y)
      .function("ToString", &math::Point::to_string);

  emscripten::function("EuclideanDistance2D", &math::euclidean_distance_2d);
}
