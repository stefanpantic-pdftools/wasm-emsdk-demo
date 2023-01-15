#include <iostream>

#include <emscripten/bind.h>
#include <emscripten/val.h>

namespace ping {

void calculate_equation_result(const emscripten::val &js_val) {
  std::cout << "Calling set_result from C++ code!" << std::endl;

  if (!js_val.hasOwnProperty("numbers")) {
    std::cerr << "Invalid Equation passed into C++!" << std::endl;
    return;
  }

  // super complex math
  double result = 0;
  auto numbers =
      emscripten::convertJSArrayToNumberVector<double>(js_val["numbers"]);
  for (auto num : numbers) {
    result = std::pow(num, num); // This is the bug, should be += instead of =
  }

  js_val.call<void>("set_result", result);
}

} // namespace ping

EMSCRIPTEN_BINDINGS(js_val) {
  emscripten::function("CalculateEquationResult",
                       &ping::calculate_equation_result);
}
