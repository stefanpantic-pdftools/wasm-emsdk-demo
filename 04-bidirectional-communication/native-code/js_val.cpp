#include <iostream>

#include <emscripten/bind.h>
#include <emscripten/val.h>

namespace ping {

void ping_cpp(const emscripten::val &js_val) {
  std::cout << "Calling ping_cpp from C++ code!" << std::endl;
  js_val.call<void>("ping_cpp");
}

} // namespace ping

EMSCRIPTEN_BINDINGS(js_val) {
  emscripten::function("PingCpp", &ping::ping_cpp);
}
