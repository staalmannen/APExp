/* empty ctor/dtor tables for the munch binary itself (no C++ statics) */
typedef void (*PFV)();
PFV _ctors[] = { 0 };
// PFV _dtors[] = { 0 };
