#define LZ77Min (2U+5U+4U)
#define LKMin 3U+LZ77Min
#define CDiCCP 0x801U, LKMin, 1, 1, 0
#define PNG_CHUNK(cHNK) { CD ## cHNK }
#define PNG_KNOWN_CHUNKS PNG_CHUNK(iCCP)

static const struct {
    unsigned int a : 12;
    unsigned int b : 8;
    unsigned int c : 4;
    unsigned int d : 4;
    unsigned int e : 1;
} table[] = {
    PNG_KNOWN_CHUNKS
};

int main() { return 0; }
