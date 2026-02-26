#ifndef _npe_SDL_endian_h_
#define _npe_SDL_endian_h_

#define SDL_LIL_ENDIAN  1234
#define SDL_BIG_ENDIAN  4321

#if defined(__amd64__) || defined(__386__) || defined(__arm__) || defined(__arm64__) || defined(__spim__)
#define SDL_BYTEORDER	SDL_LIL_ENDIAN
#elif defined(__mips__) || defined(__power__)
#define SDL_BYTEORDER	SDL_BIG_ENDIAN
#endif

static u16int
SDL_Swap16(u16int x)
{
	return (x<<8) | (x>>8);
}

static u32int
SDL_Swap32(u32int x)
{
	return ((x << 24) | ((x << 8) & 0x00FF0000) | ((x >> 8) & 0x0000FF00) | (x >> 24));
}

static u64int
SDL_Swap64(u64int x)
{
    u32int hi, lo;

    /* Separate into high and low 32-bit values and swap them */
    lo = x & 0xFFFFFFFF;
    x >>= 32;
    hi = x & 0xFFFFFFFF;
    x = SDL_Swap32(lo);
    x <<= 32;
    x |= SDL_Swap32(hi);
    return (x);
}

#if SDL_BYTEORDER == SDL_LIL_ENDIAN
#define SDL_SwapLE16(X) (X)
#define SDL_SwapLE32(X) (X)
#define SDL_SwapLE64(X) (X)
#define SDL_SwapFloatLE(X)  (X)
#define SDL_SwapBE16(X) SDL_Swap16(X)
#define SDL_SwapBE32(X) SDL_Swap32(X)
#define SDL_SwapBE64(X) SDL_Swap64(X)
#define SDL_SwapFloatBE(X)  SDL_SwapFloat(X)
#else
#define SDL_SwapLE16(X) SDL_Swap16(X)
#define SDL_SwapLE32(X) SDL_Swap32(X)
#define SDL_SwapLE64(X) SDL_Swap64(X)
#define SDL_SwapFloatLE(X)  SDL_SwapFloat(X)
#define SDL_SwapBE16(X) (X)
#define SDL_SwapBE32(X) (X)
#define SDL_SwapBE64(X) (X)
#define SDL_SwapFloatBE(X)  (X)
#endif

#endif
