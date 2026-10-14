# Questions & Answers

Below, you'll find answers to common questions about PSTL, from installation to usage and contributions.

---

## General Questions

**Q: What is PSTL?**  
**A:** PSTL (Portable Standard Template Library) is a modern implementation of STL designed for portability, flexibility, and strict standards compliance.

**Q: Who can use PSTL?**  
**A:** Developers working on cross-platform projects, IoT devices, embedded systems, or applications requiring strict control over resources and compatibility, including safety-critical domains like automotive or aerospace.

**Q: Is PSTL a replacement for STL?**  
**A:** Not entirely. PSTL is a specialized implementation of STL tailored for specific use cases like cross-platform portability and resource-constrained environments.

**Q: Does PSTL support multithreading?**  
**A:** While PSTL is designed with multithreading in mind, full multithreading optimization is not yet implemented in the current version.

**Q: Is PSTL header-only?**  
**A:** Yes, PSTL is entirely header-only, simplifying integration and eliminating the need for additional binaries.

**Q: How portable is PSTL?**  
**A:** PSTL is highly portable, supporting environments from bare-metal and OS-free platforms to OS-based systems, with minimal platform-specific dependencies.

**Q: Is PSTL optimized for low-resource devices?**  
**A:** Yes, PSTL is designed to optimize resource usage, making it suitable for low-memory, low-power, and constrained environments.

---

## Installation Issues

**Q: I get a build error related to C++ standards. What should I do?**  
**A:** Ensure your compiler supports at least C++14. Check the [Installation](installation.md) section for more details.

**Q: I get a CMake error about missing project configuration.**  
**A:** Ensure you are running `cmake ..` from the correct build directory and have all required dependencies installed.

---

## Usage Scenarios

**Q: Can I use PSTL in a bare-metal environment?**  
**A:** Yes, PSTL is designed to work efficiently without operating systems and supports bare-metal environments.

**Q: Can I switch between exceptions and error codes?**  
**A:** Yes, PSTL supports both modes. See the [Error Handling](advanced/errors.md) section for details.

---

## Technical Details

**Q: Are all STL components implemented?**  
**A:** No, some outdated or non-standard components are intentionally excluded. See [PSTL Components](resources/pstl_components.md) for more details.

**Q: Are there plans to add missing STL components?**  
**A:** Yes, some components are under consideration. Contributions are welcome!

**Q: Can PSTL be used alongside other STL implementations?**  
**A:** Absolutely. PSTL is designed to work seamlessly alongside standard STL implementations, allowing for gradual migration and minimizing conflicts.

**Q: Does PSTL improve compilation time?**  
**A:** PSTL reduces compilation overhead by enabling selective inclusion of components, ensuring only the necessary parts are compiled.

**Q: How does PSTL handle industry standards compliance?**  
**A:** PSTL aligns with stringent industry standards, such as AutoSAR, and is rigorously tested using advanced tools like Parasoft C/C++test.

**Q: How does PSTL compare to other STL implementations?**  
**A:** PSTL emphasizes portability, selective component inclusion, and compatibility with safety-critical standards, distinguishing it from other STL libraries.

---

## Contribution

**Q: How can I contribute to PSTL?**  
**A:** Check out our [Contribution Guide](contributing.md) for instructions on how to get started.

