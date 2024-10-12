#define INCL_BASE_CPRDCPR_HUFF
#define INCL_BASE_CPRDCPR_PIC
#define INCL_BASE_CPRDCPR_SOUND

#include "base/includes.h"

//huff.h
tBASE_CPRDCPR_HUFF BASE_CPRDCPR_HUFF;

//pic.h
tBASE_CPRDCPR_PIC BASE_CPRDCPR_PIC;

//sound.h
tBASE_CPRDCPR_SOUND BASE_CPRDCPR_SOUND;

INT const BASE_CPRDCPR_SOUND_CHANNELNUM[4][4]  =
{
    {0, 0, 0, 0},
    {0, 1, 0, 1},
    {0, 1, 0, 2},
    {1, 0, 2, 0}
};

INT const BASE_CPRDCPR_SOUND_MODELS[4] = {3, 6, 9, 9};
