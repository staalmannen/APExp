// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="to_string2.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TO_STRING2_H
#define PSTL_TO_STRING2_H

#include "../common/numeric_limits.h"
#include "../common/size_t.h"
#include "../iterator/back_insert_iterator.h"
#include "../metaprogramming/primary_type/is_floating_point.h"
#include "../metaprogramming/primary_type/is_integral.h"
#include "../metaprogramming/sign_modifications/make_unsigned.h"
#include "convert.h"

namespace portable_stl {

template<class t_string, class t_type, class = ::portable_stl::is_floating_point<t_type>>
class base_to_string_converter final {
public:
  t_string operator()(t_type in_value) noexcept {
    using value_type    = typename t_string::value_type;
    using unsigned_type = ::portable_stl::make_unsigned_t<t_type>;

    constexpr auto const          max_digits{::portable_stl::numeric_limits<t_type>::digits10};
    constexpr unsigned_type const conv_base{10U};
    t_string                      result;
    auto                          result_inserter = ::portable_stl::back_inserter(result);
    bool                          conv_result{true};

    char32_t               digits[max_digits + 1U];
    ::portable_stl::size_t curr_d{0U};

    bool          needMinus{in_value < 0};
    unsigned_type value = (needMinus) ? static_cast<unsigned_type>(-in_value) : static_cast<unsigned_type>(in_value);
    do {
      digits[curr_d++] = '0' + (value % conv_base);
      value /= conv_base;
    } while (0U != value);
    if (needMinus) {
      conv_result &= ::portable_stl::put_utf32<value_type>(result_inserter, '-');
    }
    while (curr_d > 0U) {
      conv_result &= ::portable_stl::put_utf32<value_type>(result_inserter, digits[--curr_d]);
    }
    return result;
  }
};

namespace {
  template<class t_type, class = ::portable_stl::is_integral<t_type>> class Comparator final {
  public:
    constexpr static int check(t_type const &lhv, t_type const &rhv) noexcept {
      return (lhv < rhv) ? ((rhv - lhv) < ::portable_stl::numeric_limits<t_type>::epsilon() ? 0 : -1)
           : (lhv - rhv) < numeric_limits<t_type>::epsilon() ? 0
                                                             : 1;
    }
  };

  template<class t_type> class Comparator<t_type, ::portable_stl::true_type> final {
  public:
    constexpr static int check(t_type const &lhv, t_type const &rhv) noexcept {
      return static_cast<int>(lhv - rhv);
    }
  };

  template<class t_type> constexpr bool is_equal(t_type const &lhv, t_type const &rhv) noexcept {
    return 0 == Comparator<t_type>::check(lhv, rhv);
  }

  template<class t_type> constexpr bool is_zero(t_type const &lhv) noexcept {
    return 0 == Comparator<t_type>::check(lhv, t_type{0});
  }

  template<class t_type> constexpr bool is_less(t_type const &lhv, t_type const &rhv) noexcept {
    return Comparator<t_type>::check(lhv, rhv) < 0;
  }

  template<class t_type> constexpr bool is_less_zero(t_type const &lhv) noexcept {
    return Comparator<t_type>::check(lhv, t_type{0}) < 0;
  }
} // namespace

template<class t_string, typename t_type>
class base_to_string_converter<t_string, t_type, ::portable_stl::true_type> final {
public:
  t_string operator()(t_type value) noexcept {
    using value_type    = typename t_string::value_type;
    using integral_type = unsigned long long;

    constexpr integral_type const conv_base{10ULL};
    ::portable_stl::int32_t       remaining_digits{::portable_stl::numeric_limits<t_type>::digits10};

    t_string result;
    auto     result_inserter = ::portable_stl::back_inserter(result);
    bool     conv_result{true};

    if (is_zero(value)) {
      conv_result &= ::portable_stl::put_utf32<value_type>(result_inserter, '0');
      return result;
    }

    bool const needMinus{is_less_zero(value)};
    if (needMinus) {
      value = -value;
    }

    if (is_less(value, static_cast<t_type>(1.))) {
      result.insert(0U, 1U, '0');
    } else {
      auto const max_integral = static_cast<t_type>(::portable_stl::numeric_limits<integral_type>::max());
      while (value > max_integral) {
        conv_result &= ::portable_stl::put_utf32<value_type>(result_inserter, '0');
        value /= conv_base;
      }
      auto integral = static_cast<integral_type>(value);
      if (integral == 0U) {
        result.insert(0U, 1U, '0');
      } else {
        value -= static_cast<t_type>(integral);
        do {
          result.insert(0U, 1U, static_cast<value_type>('0' + static_cast<::portable_stl::char_t>(integral % conv_base)));
          integral /= conv_base;
          if (remaining_digits > 0) {
            remaining_digits--;
          }
        } while (0U != integral);
      }
    }
    if (needMinus) {
      result.insert(0U, 1U, '-');
    }
    if (!is_zero(value)) {
      conv_result &= ::portable_stl::put_utf32<value_type>(result_inserter, '.');

      auto test_value = value;
      if (remaining_digits == ::portable_stl::numeric_limits<t_type>::digits10) {
        while (static_cast<integral_type>(test_value + ::portable_stl::numeric_limits<t_type>::epsilon()) == 0U) {
          remaining_digits++;
          test_value *= t_type{conv_base};
        }
        remaining_digits--;
      }
      auto multiplier = static_cast<t_type>(1.0);
      for (::portable_stl::int32_t i{0}; i < remaining_digits; i++) {
        multiplier *= conv_base;
      }
      t_type precision = 1 / multiplier;
      value += (static_cast<t_type>(0.5) * precision);
      while ((value > precision) && (remaining_digits-- > 0)) {
        value *= t_type{conv_base};
        precision *= conv_base;

        auto integral = static_cast<integral_type>(value);
        conv_result &= ::portable_stl::put_utf32<value_type>(result_inserter, '0' + (integral % conv_base));

        value -= static_cast<t_type>(integral);
      }
    }
    return result;
  }
};

// integral
template<class t_string> t_string to_string2(int value) noexcept {
  return move(base_to_string_converter<t_string, int>()(value));
}
template<class t_string> t_string to_string2(unsigned value) noexcept {
  return move(base_to_string_converter<t_string, unsigned>()(value));
}
template<class t_string> t_string to_string2(long value) noexcept {
  return move(base_to_string_converter<t_string, long>()(value));
}
template<class t_string> t_string to_string2(unsigned long value) noexcept {
  return move(base_to_string_converter<t_string, unsigned long>()(value));
}
template<class t_string> t_string to_string2(long long value) noexcept {
  return move(base_to_string_converter<t_string, long long>()(value));
}
template<class t_string> t_string to_string2(unsigned long long value) noexcept {
  return move(base_to_string_converter<t_string, unsigned long long>()(value));
}

// float
template<class t_string> t_string to_string2(float value) noexcept {
  return move(base_to_string_converter<t_string, float>()(value));
}
template<class t_string> t_string to_string2(double value) noexcept {
  return move(base_to_string_converter<t_string, double>()(value));
}
template<class t_string> t_string to_string2(long double value) noexcept {
  return move(base_to_string_converter<t_string, long double>()(value));
}

} // namespace portable_stl

#endif // PSTL_TO_STRING2_H
