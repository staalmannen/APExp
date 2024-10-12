/*
 * Uninorm - A free ANSI C Implementation of Unicode
 * Normalization Forms NFD and NFC.
 *
 * You may use this library on either the terms of the
 * GNU General Public Licence or the Artistic Licence.
 *
 * The project is maintained at
 * http://sourceforge.net/projects/uninorm
 *
 * Copyright (c) 2001 Bjoern Hoehrmann <bjoern@hoehrmann.de>
 *
 * $Id: unincore.c,v 1.1 2003/11/11 17:00:31 kolja Exp $
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "base/uninorm/unincore.h"
#include "base/includes.h" /* BASE_LFN_MAXLEN */
#include "unidata.h"

/* Hangul constants */
#define SBase  0xAC00
#define LBase  0x1100
#define VBase  0x1161
#define TBase  0x11A7
#define HLast  0xD7A3
#define LCount 19
#define VCount 21
#define TCount 28
#define NCount (VCount * TCount)
#define SCount (LCount * NCount)

/* convenience null */
#define null 0
#define MAX_FILENAME_SIZE BASE_LFN_MAXLEN


/**
  * Get number of fields in int array.
  *
  * @param str given null-terminated int array
  *
  * @return length of the array
  *
  */
uint istrlen(uint *str)
{
    uint i = 0;

    if (!str)
        return 0;

    while(*str++)
        ++i;

    return i;
}

/**
  * Compare two null-terminated int arrays
  *
  * @param s1 first int array
  * @param s2 second int array
  *
  * @return result of the analysis as for strcmp()
  *
  */
uint istrcmp(uint *s1, uint *s2)
{
    uint i;

    while ((i = *s1) == *s2)
    {
        if (i == 0)
            return 0;

        ++s1;
        ++s2;
    }

    return (*s1 > *s2 ? 1 : -1);
}

/**
  * Checks if given code point is excluded from recomposition
  * using data derived from CompositionExclusions.txt.
  *
  * @param c given code point
  *
  * @return true value if excluded, false otherwise
  *
  */
uint is_excluded(uint c)
{
    uint i;

    for (i = 0; exclusions[i]; ++i)
    {
        if (exclusions[i] == c)
            return 1;
    }

    return 0;
}

/**
  * Looks up combining class of given code point
  *
  * @param c given code point
  *
  * @return the combining class
  *
  */
uint get_combining_class(uint c)
{
    uint i;

    for (i = 0; combclass[i].code != null; ++i)
    {
        if (combclass[i].code == c)
        {
            return combclass[i].comb;
        }
    }

    return 0;
}

/**
  * Get canonical composition of given code point
  *
  * @param c1 initial code point
  * @param c2 combining code point
  *
  * @return combined code point or -1 if none found
  * or the code point was excluded from composition
  *
  */
int get_recombined_codepoint(uint c1, uint c2)
{
    uint i;
    int r = -1;

    for (i = 0; mapping[i].code; ++i)
    {
        if (mapping[i].decomp[0] == c1 &&
            mapping[i].decomp[1] == c2)
        {
            if (get_combining_class(mapping[i].code) == 0)
                r = mapping[i].code;

            break;
        }
    }

    if (r != -1 && !is_excluded(r))
        return r;

    return -1;
}

/**
  * Get canonical decomposition of given code point
  *
  * @param buf null-terminated destination int array
  * @param c code point to decompose
  *
  * @return null-terminated destination int array
  *
  */
uint *get_decomposition(uint *buf, uint c)
{
    uint i;

    for (i = 0; mapping[i].code; ++i)
    {
        if (mapping[i].code == c)
        {
            buf[0] = mapping[i].decomp[0];
            buf[1] = mapping[i].decomp[1];
            return buf;
        }
    }

    for (i = 0; singleton[i].code; ++i)
    {
        if (singleton[i].code == c)
        {
            buf[0] = singleton[i].decomp;
            buf[1] = null;
            return buf;
        }
    }

    return null;
}

/**
  * Recursivly decomposes given code point to int array.
  *
  * @param buf null-terminated destination int array
  * @param c code point to decompose
  *
  * @return null-terminated destination int array
  *
  */
void decompose_recursive(uint *buf, uint c)
{
    uint pos = 0;
    uint decomp[2];

    buf[0] = c;
    buf[1] = null;

    if (c >= SBase && c <= HLast)
    {
        int SIndex = c - SBase;

        if (SIndex < 0 || SIndex >= SCount)
        {
            return;
        }
        else
        {
            int L = LBase +  SIndex / NCount;
            int V = VBase + (SIndex % NCount) / TCount;
            int T = TBase +  SIndex % TCount;

            buf[pos++] = L;
            buf[pos++] = V;
            
            if (T != TBase)
                buf[pos++] = T;

            buf[pos++] = null;
        }
    }
    else
    {
        if (get_decomposition(decomp, c) != null)
        {
            buf[pos++] = decomp[0];
            decompose_recursive(buf, decomp[0]);
            
            pos = istrlen(buf);
            
            if (decomp[1])
            {
                buf[pos++] = decomp[1];
            }
            
            buf[pos++] = null;
        }
    }
}

/**
  * Put code points in canonical order
  *
  * @param str null-terminated int array to order
  *
  * @return ordered int array
  *
  */
void canonical_order(uint *str)
{
    int i;
    int len = istrlen(str);

    for (i = 0; i < len-1; ++i)
    {
        uint first = get_combining_class(str[i]);
        uint second = get_combining_class(str[i+1]);

        if ((first > second) && (second != 0))
        {
            uint c = str[i];

            str[i] = str[i+1];
            str[i+1] = c;

            if (i == 0)
              --i;
            else
              i -= 2;
        }
    }
}

/**
  * Create canonical composition of given int array
  *
  * @param str null-terminated int array to compose
  *
  * @return canonically composed int array
  *
  */
void canonical_composition(uint *str)
{
    uint ipos = 0, /* position of initial */
         cpos = 0, /* current position    */
         opos = 0; /* writing position    */
    uint len = istrlen(str);
    uint SIndex;
    int initial = -1;
    int c;

    if (!len)
        return;

    while (cpos < len)
    {
        uint this_class = get_combining_class(str[cpos]);

        if (initial >= LBase && initial < (LBase + LCount) && str[cpos] >= VBase && str[cpos] < (VBase + VCount))
        {
            initial = str[ipos] = ((initial - LBase) * VCount + str[cpos] - VBase) * TCount + SBase;
            ++cpos;
        }
        else if (0 <= (SIndex = initial - SBase) && SIndex < SCount && SIndex % TCount == 0)
        {
            int TIndex = str[cpos] - TBase;

            if (0 <= TIndex && TIndex < TCount)
            {
                str[ipos] = initial + str[cpos++] - TBase;
            }
            else
            {
                str[opos++] = str[cpos++];
            }
        }
        else if ((initial != -1) && (initial == (int)str[opos - 1] || get_combining_class(str[opos - 1]) != this_class) && (c = get_recombined_codepoint(initial, str[cpos])) != -1)
        {
            initial = str[ipos] = c;
            ++cpos;
        }
        else if (this_class == 0)
        {
            ipos = opos++;
            str[ipos] = initial = str[cpos++];
        }
        else
        {
            str[opos++] = str[cpos++];
        }
    }

    str[opos++] = null;
}

/**
  * Create canonical decomposition of given int array
  *
  * @param buf null-terminated destination int array
  * @param str null-terminated source int array
  *
  * @return destination int array
  *
  */
void canonical_decomposition(uint *buf, uint *str)
{
    uint i, j, pos = 0, len = 0;
    uint length = istrlen(str);

    uint temp[MAX_FILENAME_SIZE];
    temp[0] = null;

    for (i = 0; i < length && pos < MAX_FILENAME_SIZE; ++i)
    {
        decompose_recursive(temp, str[i]);
        len = istrlen(temp);

        for (j = 0; j < len; ++j)
            buf[pos++] = temp[j];
    }

    buf[pos++] = null;
}

/**
  * Decode UTF-8 encoded char* to int array.
  *
  * @param buf null-terminated destination int array
  * @param str null-terminated source string
  *
  * @return the destination int array
  *
  */
void decode_utf8(uint *buf, char *str)
{
    uint len = strlen(str);
    uint i, j = 0;

    for (i = 0; i < len; ++i)
    {
        uint k, n, count;
        uint c = str[i];
        
        if ((c & 0xE0) == 0xC0)
        {
            n = c & 31;
            count = 1;
        }
        else if ((c & 0xF0) == 0xE0)
        {
            n = c & 15;
            count = 2;
        }
        else if ((c & 0xF8) == 0xF0)
        {
            n = c & 7;
            count = 3;
        }
        else if ((c & 0xFC) == 0xF8)
        {
            n = c & 3;
            count = 4;
        }
        else if ((c & 0xFE) == 0xFC)
        {
            n = c & 1;
            count = 5;
        }
        else
        {
            buf[j++] = c;
            continue;
        }

        if (i + count > len)
            break;
        
        for (k = 0; k < count; ++k)
        {
            c = str[++i];
            n = (n << 6) | (c & 0x3F);
        }

        buf[j++] = n;        
    }

    buf[j++] = null;
}

/**
  * Encode int array to UTF-8 string.
  *
  * @param buf null-terminated destination string
  * @param str null-terminated source int array
  *
  * @return the destination int array
  *
  */
void encode_utf8(char *buf, uint *str)
{
    int i, j = 0;
    int len = istrlen(str);

    for (i = 0; i < len && j < MAX_FILENAME_SIZE; ++i)
    {
        uint c = str[i];

        if (c < 128)
        {
            buf[j++] = (char)c;
        }
        else if (c <= 0x7FF)
        {
            buf[j++] = (char)(0xC0 | (c >> 6));
            buf[j++] = (char)(0x80 | (c & 0x3F));
        }
        else if (c <= 0xFFFF)
        {
            buf[j++] = (char)(0xE0 | (c >> 12));
            buf[j++] = (char)(0x80 | ((c >> 6) & 0x3F));
            buf[j++] = (char)(0x80 | (c & 0x3F));
        }
        else if (c <= 0x1FFFFF)
        {
            buf[j++] = (char)(0xF0 | (c >> 18));
            buf[j++] = (char)(0x80 | ((c >> 12) & 0x3F));
            buf[j++] = (char)(0x80 | ((c >> 6) & 0x3F));
            buf[j++] = (char)(0x80 | (c & 0x3F));
        }
        else
        {
            buf[j++] = (char)(0xF8 | (c >> 24));
            buf[j++] = (char)(0x80 | ((c >> 18) & 0x3F));
            buf[j++] = (char)(0x80 | ((c >> 12) & 0x3F));
            buf[j++] = (char)(0x80 | ((c >> 6) & 0x3F));
            buf[j++] = (char)(0x80 | (c & 0x3F));
        }
    }

    buf[j++] = null;
}

/**
  * Apply Normalization Form D to given int array.
  *
  * @param buf null-terminated destination int array
  * @param str null-terminated source int array
  *
  * @return the destination int array in normalized form
  *
  */
void normalize_nfd(uint *buf, uint *str)
{
    canonical_decomposition(buf, str);
    canonical_order(buf);
}

/**
  * Apply Normalization Form C to given int array.
  *
  * @param buf null-terminated destination int array
  * @param str null-terminated source int array
  *
  * @return the destination int array in normalized form
  *
  */
void normalize_nfc(uint *buf, uint *str)
{
    normalize_nfd(buf, str);
    canonical_composition(buf);
}

/**
  * Apply Normalization Form D to given UTF-8 encoded string.
  *
  * @param buf null-terminated destination string
  * @param str null-terminated source string
  *
  * @return the destination UTF-8 encoded string in normalized form
  *
  */
void normalize_nfd_utf8(char *buf, char *str)
{
    uint temp1[MAX_FILENAME_SIZE];
    uint temp2[MAX_FILENAME_SIZE];

    decode_utf8(temp1, str);
    normalize_nfd(temp2, temp1);

    encode_utf8(buf, temp2);
}

/**
  * Apply Normalization Form C to given UTF-8 encoded string.
  *
  * @param buf null-terminated destination string
  * @param str null-terminated source string
  *
  * @return the destination UTF-8 encoded string in normalized form
  *
  */
void normalize_nfc_utf8(char *buf, char *str)
{
    uint temp1[MAX_FILENAME_SIZE];
    uint temp2[MAX_FILENAME_SIZE];

    decode_utf8(temp1, str);
    normalize_nfc(temp2, temp1);

    encode_utf8(buf, temp2);
}
