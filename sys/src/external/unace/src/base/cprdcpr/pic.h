#ifndef _BASE_CPRDCPR_PIC_H_INCLUDED
#define _BASE_CPRDCPR_PIC_H_INCLUDED

#define BASE_CPRDCPR_PIC_N0              128
#define BASE_CPRDCPR_PIC_MAXPLANES       4
#define BASE_CPRDCPR_PIC_MAXCOLWIDTH     16384
#define BASE_CPRDCPR_PIC_CONTEXTNUMBER   365

#define BASE_CPRDCPR_PIC_S1              3
#define BASE_CPRDCPR_PIC_S2              7
#define BASE_CPRDCPR_PIC_S3              21


#define BASE_CPRDCPR_PIC_QuantizerArr(i)     BASE_CPRDCPR_PIC.QuantizerArr    [255+i]
#define BASE_CPRDCPR_PIC_QuantizerArrx9(i)   BASE_CPRDCPR_PIC.QuantizerArrx9  [255+i]
#define BASE_CPRDCPR_PIC_QuantizerArrx9x9(i) BASE_CPRDCPR_PIC.QuantizerArrx9x9[255+i]


#pragma pack(push, 1) // SETNOALIGNMENT -- packprag.h
typedef struct
{
  UCHAR   UsedCounter,
          PredictorNumber;
  SHORT   AverageCounter;
  UCHAR   ErrorCounters[4];
} tBASE_CPRDCPR_PIC_CONTEXT,
 *pBASE_CPRDCPR_PIC_CONTEXT;
#pragma pack(pop) // RESTOREALIGNMENT -- packprag.h

typedef struct
{
        INT     QuantizerArr    [511],
                QuantizerArrx9  [511],
                QuantizerArrx9x9[511];
} tBASE_CPRDCPR_PIC;

extern tBASE_CPRDCPR_PIC BASE_CPRDCPR_PIC; //pic.c

#endif
