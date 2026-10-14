# Hello PSTL!

To quickly verify that PSTL is working in your environment, try the following example:

```cpp
#include "pstl/vector.hpp"
#include "pstl/algorithm.hpp"
#include <iostream>

int main() {
    pstl::vector<int> numbers = {1, 2, 3, 4, 5};
    pstl::for_each(numbers.begin(), numbers.end(), [](int& n) {
        n *= 2;
    });

    for (const auto& n : numbers) {
        std::cout << n << " ";
    }
    return 0;
}
```

This example doubles the values in a `pstl::vector` and prints the result. If the output matches the expected sequence `2 4 6 8 10`, your environment is configured correctly.
