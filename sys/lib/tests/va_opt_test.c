#define xprint(a, ...) print(a __VA_OPT__(,) __VA_ARGS__)

int main() {
    xprint("format", 1, 2, 3); // should expand to print("format", 1, 2, 3)
    xprint("no args");         // should expand to print("format")
    return 0;
}
