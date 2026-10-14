# Troubleshooting

## Common Issues

### Build Errors
- **Problem**: Compilation fails with an error related to C++ standards.  
  **Solution**: Ensure your compiler supports at least C++14 and that the appropriate flags are enabled. See [Installation](../installation.md) for details.

### Linking Problems
- **Problem**: Missing symbols when linking against PSTL.  
  **Solution**: Verify that all necessary PSTL headers are included and that the library is properly linked during the build process.

### Unexpected Behavior
- **Problem**: Unexpected results when using custom allocators or exception-free error handling.  
  **Solution**: Check your configuration and review the documentation on [Memory Management](memory.md) and [Error Handling](errors.md).

---

## Debugging Tips

1. **Use Compiler Diagnostics**  
   Enable verbose compiler output and warnings to identify issues early.

2. **Test Small Code Snippets**  
   Isolate the problem by testing individual components in smaller programs.

3. **Check for Platform-Specific Behavior**  
   Verify that your platform's compiler and environment are compatible with PSTL requirements.

