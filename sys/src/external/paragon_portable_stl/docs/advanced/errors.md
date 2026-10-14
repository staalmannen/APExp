# Error Handling

Portable STL provides a robust and flexible error-handling mechanism through the `expected` class. This approach, inspired by C++23 but available for C++14, allows developers to manage errors predictably while maintaining compatibility with resource-constrained environments.

You can handle errors in two distinct modes to meet the compliance and performance requirements of your code across various use cases:

1. **No Exceptions Mode**  
   Designed for environments where exceptions are prohibited or undesirable, such as safety-critical systems or OS-free platforms. This mode ensures predictable execution by avoiding the use of exceptions entirely.

2. **Exceptions Mode**  
   Provides traditional exception handling, which is often preferred for debugging and testing. This mode integrates seamlessly with existing C++ exception mechanisms, allowing developers to utilize familiar practices.

---

## Examples

### Basic Usage

#### No Exceptions Mode:

```cpp
#include <portable_stl/utility/expected/expected.h>

portable_stl::expected<int, error> do_something();

int main() {
    auto result = do_something();
    if (result.has_value()) {
        auto value = *result;
        // Process value
    }
}
```

#### Exceptions Mode:

```cpp
#include <portable_stl/utility/expected/expected.h>

portable_stl::expected<int, error> do_something();

int main() {
    auto result = do_something();
    try {
        auto value = result.value();
        // Process value
    } catch (portable_stl::bad_expected_access<error>& error) {
        // Handle error
    }
}
```

---

### Chaining Function Calls

The `expected` class supports chaining function calls using the `and_then` method. This allows for a clean and readable flow when processing a series of dependent operations.

#### No Exceptions Mode:

```cpp
portable_stl::expected<result_object_c, error> test() {
    return do_something_a().and_then([](result_object_a value) {
        return do_something_b(portable_stl::move(value)).and_then([](result_object_b value) {
            return do_something_c(portable_stl::move(value));
        });
    });
}

int main() {
    auto result = test();
    if (result.has_value()) {
        auto process_value = *result;
        // Process value
    }
    return 0;
}
```

#### Exceptions Mode:

```cpp
portable_stl::expected<result_object_c, error> test() {
    return do_something_a().and_then([](result_object_a value) {
        return do_something_b(portable_stl::move(value)).and_then([](result_object_b value) {
            return do_something_c(portable_stl::move(value));
        });
    });
}

int main() {
    auto result = test();
    try {
        auto process_value = result.value();
        // Process value
    } catch (portable_stl::bad_expected_access<error>& error) {
        // Handle error
    }
    return 0;
}
```

---

### Generating Results or Errors

#### No Exceptions Mode:

```cpp
portable_stl::expected<int, error> do_something() {
    if (on_error) {
        return portable_stl::unexpected<error>{error_value}; // Return error
    }
    return 42; // Return successful result
}
```

#### Exceptions Mode:

```cpp
portable_stl::expected<int, error> do_something() {
    if (on_error) {
        return portable_stl::unexpected<error>{error_value}; // Return error
    }
    return 42; // Return successful result
}
```
