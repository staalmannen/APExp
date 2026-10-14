# Configure Your Project

## Integration with Your Project

### Using CMake
Add PSTL to your `CMakeLists.txt`:

```cmake
add_subdirectory(external/pstl)
target_link_libraries(your_project PRIVATE pstl)
```

### Without CMake
Include PSTL headers directly in your project:

```cpp
#include "pstl/vector.hpp"
```

Ensure `-I` points to the PSTL `include` directory in your build commands.

---

## Checking Your Setup

### Verify Installation

Ensure the library files are properly installed and accessible:
- The `include` directory is correctly referenced in your project.
- PSTL header files are visible to your compiler.

### Test Build

Compile and run a minimal example to confirm your setup. See [Hello PSTL](hello_pstl.md).

---

## Troubleshooting

### Common Issues

- **`error: missing -std=c++14`**  
  Solution: Ensure your compiler flags include `-std=c++14` or higher.

- **Build Error: "CMake cannot find project configuration"**  
  Solution: Run `cmake ..` from the `build` directory.

### Additional Tips

- Verify your compiler version matches the `prerequisites` (*This link will be updated once available*).  
- Check for missing dependencies, such as CMake, or update your build tools if necessary.

