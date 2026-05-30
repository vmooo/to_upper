#ifndef TO_UPPER_TO_UPPER_H
#define TO_UPPER_TO_UPPER_H

#include <array>
#include <cassert>

constexpr char to_upper(const char c) {
   if (c >= 'a' && c <= 'z') {
      return  static_cast<char>(c - 32);
   }
   assert(c >= 0 && c <= 127);
   return c;
}

template<char... chars>
constexpr auto operator""_upper() {
   constexpr char str[] = {chars..., '\0'};
   std::array<char, sizeof...(chars) + 1> result{};
   for (size_t i = 0; i < sizeof...(chars); ++i) {
      assert(str[i] != '\0');
      result[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] : to_upper(str[i]);
   }
   result[sizeof...(chars)] = '\0';
   return result;
}

#endif //TO_UPPER_TO_UPPER_H