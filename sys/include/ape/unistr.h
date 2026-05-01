#ifndef _UNISTR_H
#define _UNISTR_H

#include <unitypes.h>
#include <stddef.h>

uint32_t *u32_chr(const uint32_t *s, size_t n, uint32_t c);
uint32_t *u32_cpy(uint32_t *dest, const uint32_t *src, size_t n);
uint32_t *u32_pcpy(uint32_t *dest, const uint32_t *src, size_t n);
uint32_t *u32_strcat(uint32_t *dest, const uint32_t *src);
size_t u32_strlen(const uint32_t *s);

#endif
