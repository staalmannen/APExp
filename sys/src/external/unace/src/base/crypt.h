#ifndef _BASE_CRYPT_H_INCLUDED
#define _BASE_CRYPT_H_INCLUDED

#define BASE_CRYPT_BLOWFISHROUNDS       16
#define BASE_CRYPT_SHACONST1		0x5a827999L
#define BASE_CRYPT_SHACONST2		0x6ed9eba1L
#define BASE_CRYPT_SHACONST3		0x8f1bbcdcL
#define BASE_CRYPT_SHACONST4		0xca62c1d6L

#define BASE_CRYPT_SHAFUNC1(X, Y, Z)	((X & Y) | (~X & Z))
#define BASE_CRYPT_SHAFUNC2(X, Y, Z)	(X ^ Y ^ Z)
#define BASE_CRYPT_SHAFUNC3(X, Y, Z)	((X & Y) | (X & Z) | (Y & Z))
#define BASE_CRYPT_SHAFUNC4(X, Y, Z)	(X ^ Y ^ Z)
#define BASE_CRYPT_SHAROT32(X, N)	((X << N) | (X >> (32 - N)))

#define BASE_CRYPT_SHAFUNC_1(I)       Temp = BASE_CRYPT_SHAROT32(A, 5) + BASE_CRYPT_SHAFUNC1(B, C, D) + E + W[I] + BASE_CRYPT_SHACONST1; E = D; D = C; C = BASE_CRYPT_SHAROT32(B,30); B = A; A = Temp; 
#define BASE_CRYPT_SHAFUNC_2(I)       Temp = BASE_CRYPT_SHAROT32(A, 5) + BASE_CRYPT_SHAFUNC2(B, C, D) + E + W[I] + BASE_CRYPT_SHACONST2; E = D; D = C; C = BASE_CRYPT_SHAROT32(B,30); B = A; A = Temp; 
#define BASE_CRYPT_SHAFUNC_3(I)       Temp = BASE_CRYPT_SHAROT32(A, 5) + BASE_CRYPT_SHAFUNC3(B, C, D) + E + W[I] + BASE_CRYPT_SHACONST3; E = D; D = C; C = BASE_CRYPT_SHAROT32(B,30); B = A; A = Temp; 
#define BASE_CRYPT_SHAFUNC_4(I)       Temp = BASE_CRYPT_SHAROT32(A, 5) + BASE_CRYPT_SHAFUNC4(B, C, D) + E + W[I] + BASE_CRYPT_SHACONST4; E = D; D = C; C = BASE_CRYPT_SHAROT32(B,30); B = A; A = Temp; 


#pragma pack(push, 1) // SETNOALIGNMENT -- packprag.h

typedef struct
{
  ULONG   Digest[5];            /* message Digest */
  ULONG   Data[16];             /* SHA data buffer */
} tBASE_CRYPT_SHAData;

typedef struct
{
  ULONG   Left,
          Right;
} tBASE_CRYPT_BLOWFISHBLOCK,
 *pBASE_CRYPT_BLOWFISHBLOCK;

typedef struct
{
  CHAR    Password[57];
  tBASE_CRYPT_BLOWFISHBLOCK LastBlock;
  ULONG   PixDigitsP[BASE_CRYPT_BLOWFISHROUNDS + 2];
  ULONG   PixDigitsS[4][256];
  tBASE_CRYPT_SHAData SHAData;
} tBASE_CRYPT_CRYPTIONDATA,
 *pBASE_CRYPT_CRYPTIONDATA;

#pragma pack(pop) // RESTOREALIGNMENT -- packprag.h


typedef struct
{
        BOOL    DoUseCurrentPassword;
} tBASE_CRYPT;

extern ULONG const BASE_CRYPT_PIXDIGITS[1042];
extern tBASE_CRYPT BASE_CRYPT;

void    BASE_CRYPT_MakeSHA(pBASE_CRYPT_CRYPTIONDATA CryptionData);
void    BASE_CRYPT_InitCryptKey(pBASE_CRYPT_CRYPTIONDATA CryptionData);

void    BASE_CRYPT_EncryptKey(pBASE_CRYPT_BLOWFISHBLOCK DataBlock,
                            pBASE_CRYPT_CRYPTIONDATA CryptionData);

void    BASE_CRYPT_DecryptBlock(pBASE_CRYPT_BLOWFISHBLOCK DataBlock);
INT     BASE_CRYPT_CryptLen(INT Len);
void    BASE_CRYPT_Decrypt(PCHAR Buf, INT Len);
void    BASE_CRYPT_ResetCryptKey(pBASE_CRYPT_CRYPTIONDATA CryptionData);

void    BASE_CRYPT_EXTERN_ResetCryptKeyUseCurrent(
          pBASE_CRYPT_CRYPTIONDATA CryptionData);
#endif
