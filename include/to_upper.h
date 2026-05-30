#ifndef TO_UPPER_TO_UPPER_H
#define TO_UPPER_TO_UPPER_H

#include <array>
#include <cassert>
#include <algorithm>
#include <string_view>

namespace literal_config {
   constexpr size_t max_size = 256;
}

constexpr char to_upper(const char c) {
   if (c >= 'a' && c <= 'z') {
      return  static_cast<char>(c - 32);
   }
   return c;
}

consteval auto operator""_upper(const char* str, const std::size_t len) {
   std::array<char, literal_config::max_size> result{};
   std::transform(str, str + len, result.begin(), to_upper);
   return result;
}

#endif //TO_UPPER_TO_UPPER_H