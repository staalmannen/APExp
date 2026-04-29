#define LZ77Min (2U+5U+4U)
#define LKMin 3U+LZ77Min
#define CDiCCP LKMin
#define PNG_CHUNK(a, b) CD ## a
#define PNG_KNOWN_CHUNKS PNG_CHUNK(iCCP, 14)

int main() {
    unsigned int x = PNG_KNOWN_CHUNKS;
    return 0;
}
