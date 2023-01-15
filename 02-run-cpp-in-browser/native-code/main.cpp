#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>

int main() {
  std::cout << "Hello WASM!" << std::endl;

  std::array<int, 10> numbers;
  std::iota(numbers.begin(), numbers.end(), 0);

  for (auto num : numbers) {
    std::cout << num << std::endl;
  }

  return 0;
}