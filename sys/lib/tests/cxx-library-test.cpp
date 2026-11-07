/*
 * cxx-library-test -- manual EDC/APExp C++ library smoke and behavior test.
 *
 * On 9front, from /sys/lib/tests:
 *
 *     c++ -o cxx-library-test cxx-library-test.cpp
 *     ./cxx-library-test
 *
 * The driver uses the installed EDC headers and links libedg. This test
 * deliberately stays in main: the current EDC startup path does not yet
 * run translated namespace-scope constructors reliably.
 */
#include <algorithm>
#include <array>
#include <cmath>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <cfenv>
#include <cinttypes>
#include <ciso646>
#include <climits>
#include <clocale>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdbool>
#include <cstddef>
#include <cstdint>
#include <cwchar>
#include <cwctype>
#include <forward_list>
#include <functional>
#include <list>
#include <map>
#include <expected>
#include <memory>
#include <string>
#include <string_view>
#include <tuple>
#include <utility>
#include <variant>
#include <vector>

static int failures;

static void check(const char *name, bool ok)
{
    if (ok) {
        std::printf("PASS  %s\n", name);
    } else {
        std::printf("FAIL  %s\n", name);
        ++failures;
    }
}

int main()
{
    std::printf("APExp C++ library test\n\n");

    /* C header wrappers and their std namespace declarations. */
    check("cctype std functions", std::isalpha('A') && !std::isdigit('A'));
    check("cmath re-export", std::sqrt(81.0) == 9.0);
    check("cstdlib re-export", std::abs(-17) == 17);
    check("cstring re-export", std::strlen("APExp") == 5);
    check("cwchar re-export", std::wcslen(L"ape") == 3);
    check("cwctype std function", std::iswalpha(L'A') != 0);
    check("cstdint names", sizeof(std::uint8_t) == 1 && sizeof(std::uint32_t) == 4);
    check("cstddef byte", sizeof(std::byte) == 1);
    check("C header macros", DBL_MAX > 1.0 && INT_MAX > 1000 && EXIT_SUCCESS == 0);

    /* Core utilities, arrays, tuples, moves, and callable wrappers. */
    std::array<int, 3> fixed = {{ 2, 4, 6 }};
    check("array indexing", fixed[1] == 4 && fixed.size() == 3);

    std::tuple<int, int> pair(7, 8);
    check("tuple get", std::get<0>(pair) + std::get<1>(pair) == 15);

    std::function<int(int)> twice = [](int value) { return value * 2; };
    check("function invocation", twice(9) == 18);

    std::unique_ptr<int> owned = std::make_unique<int>(23);
    check("unique_ptr and make_unique", owned && *owned == 23);

    /* Existing and newly exposed containers. */
    std::vector<int> values;
    auto vector_result = values.push_back(5);
    vector_result = values.push_back(10);
    check("vector operations", vector_result.has_value() && values.size() == 2
          && values[0] == 5 && values[1] == 10);
    check("algorithm find", std::find(values.begin(), values.end(), 10) != values.end());

    std::list<int> linked;
    auto list_result = linked.push_back(31);
    check("list entrypoint and push_back", list_result.has_value() && linked.front() == 31);

    std::forward_list<int> singly_linked;
    auto forward_result = singly_linked.push_front(41);
    check("forward_list entrypoint and push_front",
          forward_result.has_value() && singly_linked.front() == 41);

    std::map<int, int> lookup;
    lookup[3] = 27;
    check("map entrypoint and subscript", lookup.size() == 1 && lookup[3] == 27);

    /* Expected, variant, string, and string_view exercise newer headers. */
    std::expected<int, int> answer(42);
    check("expected value", answer.has_value() && answer.value() == 42);

    std::variant<int, const char *> choice(13);
    check("variant alternative", std::get<int>(choice) == 13);

    std::string greeting("APExp");
    greeting += " C++";
    std::string_view view(greeting);
    check("string and string_view", view.size() == 9 && view[0] == 'A');

    std::printf("\n%d failure%s\n", failures, failures == 1 ? "" : "s");
    return failures ? 1 : 0;
}
