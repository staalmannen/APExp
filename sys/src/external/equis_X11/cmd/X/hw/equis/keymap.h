/* the key names define come from xwin/winkeynames.h, hence the NOTICE */

/*
 * Copyright 1990,91 by Thomas Roell, Dinkelscherben, Germany.
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of Thomas Roell not be used in
 * advertising or publicity pertaining to distribution of the software without
 * specific, written prior permission.  Thomas Roell makes no representations
 * about the suitability of this software for any purpose.  It is provided
 * "as is" without express or implied warranty.
 *
 * THOMAS ROELL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL THOMAS ROELL BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 *
 */

#define MAP_WIDTH   4
#define NUM_KEYCODES    248
#define MIN_KEYCODE     8
#define MAX_KEYCODE     (NUM_KEYCODES + MIN_KEYCODE-1)

/*
 * definition of the AT84/MF101/MF102 Keyboard:
 * ============================================================
 *       Defined             Key Cap Glyphs       Pressed value
 *      Key Name            Main       Also       (hex)    (dec)
 *      ----------------   ---------- -------    ------    ------
 */

#define KEY_Escape       /* Escape                0x01  */    1  
#define KEY_1            /* 1           !         0x02  */    2 
#define KEY_2            /* 2           @         0x03  */    3 
#define KEY_3            /* 3           #         0x04  */    4 
#define KEY_4            /* 4           $         0x05  */    5 
#define KEY_5            /* 5           %         0x06  */    6 
#define KEY_6            /* 6           ^         0x07  */    7 
#define KEY_7            /* 7           &         0x08  */    8 
#define KEY_8            /* 8           *         0x09  */    9 
#define KEY_9            /* 9           (         0x0a  */   10 
#define KEY_0            /* 0           )         0x0b  */   11 
#define KEY_Minus        /* - (Minus)   _ (Under) 0x0c  */   12
#define KEY_Equal        /* = (Equal)   +         0x0d  */   13 
#define KEY_BackSpace    /* Back Space            0x0e  */   14 
#define KEY_Tab          /* Tab                   0x0f  */   15
#define KEY_Q            /* Q                     0x10  */   16
#define KEY_W            /* W                     0x11  */   17
#define KEY_E            /* E                     0x12  */   18
#define KEY_R            /* R                     0x13  */   19
#define KEY_T            /* T                     0x14  */   20
#define KEY_Y            /* Y                     0x15  */   21
#define KEY_U            /* U                     0x16  */   22
#define KEY_I            /* I                     0x17  */   23
#define KEY_O            /* O                     0x18  */   24
#define KEY_P            /* P                     0x19  */   25
#define KEY_LBrace       /* [           {         0x1a  */   26
#define KEY_RBrace       /* ]           }         0x1b  */   27 
#define KEY_Enter        /* Enter                 0x1c  */   28
#define KEY_LCtrl        /* Ctrl(left)            0x1d  */   29
#define KEY_A            /* A                     0x1e  */   30
#define KEY_S            /* S                     0x1f  */   31
#define KEY_D            /* D                     0x20  */   32 
#define KEY_F            /* F                     0x21  */   33
#define KEY_G            /* G                     0x22  */   34
#define KEY_H            /* H                     0x23  */   35
#define KEY_J            /* J                     0x24  */   36
#define KEY_K            /* K                     0x25  */   37
#define KEY_L            /* L                     0x26  */   38
#define KEY_SemiColon    /* ;(SemiColon) :(Colon) 0x27  */   39
#define KEY_Quote        /* ' (Apostr)  " (Quote) 0x28  */   40
#define KEY_Tilde        /* ` (Accent)  ~ (Tilde) 0x29  */   41
#define KEY_ShiftL       /* Shift(left)           0x2a  */   42
#define KEY_BSlash       /* \(BckSlash) |(VertBar)0x2b  */   43
#define KEY_Z            /* Z                     0x2c  */   44
#define KEY_X            /* X                     0x2d  */   45
#define KEY_C            /* C                     0x2e  */   46
#define KEY_V            /* V                     0x2f  */   47
#define KEY_B            /* B                     0x30  */   48
#define KEY_N            /* N                     0x31  */   49
#define KEY_M            /* M                     0x32  */   50
#define KEY_Comma        /* , (Comma)   < (Less)  0x33  */   51
#define KEY_Period       /* . (Period)  >(Greater)0x34  */   52
#define KEY_Slash        /* / (Slash)   ?         0x35  */   53
#define KEY_ShiftR       /* Shift(right)          0x36  */   54
#define KEY_KP_Multiply  /* *                     0x37  */   55
#define KEY_Alt          /* Alt(left)             0x38  */   56
#define KEY_Space        /*   (SpaceBar)          0x39  */   57
#define KEY_CapsLock     /* CapsLock              0x3a  */   58
#define KEY_F1           /* F1                    0x3b  */   59
#define KEY_F2           /* F2                    0x3c  */   60
#define KEY_F3           /* F3                    0x3d  */   61
#define KEY_F4           /* F4                    0x3e  */   62
#define KEY_F5           /* F5                    0x3f  */   63
#define KEY_F6           /* F6                    0x40  */   64
#define KEY_F7           /* F7                    0x41  */   65
#define KEY_F8           /* F8                    0x42  */   66
#define KEY_F9           /* F9                    0x43  */   67
#define KEY_F10          /* F10                   0x44  */   68
#define KEY_NumLock      /* NumLock               0x45  */   69
#define KEY_ScrollLock   /* ScrollLock            0x46  */   70
#define KEY_KP_7         /* 7           Home      0x47  */   71 
#define KEY_KP_8         /* 8           Up        0x48  */   72 
#define KEY_KP_9         /* 9           PgUp      0x49  */   73 
#define KEY_KP_Minus     /* - (Minus)             0x4a  */   74
#define KEY_KP_4         /* 4           Left      0x4b  */   75
#define KEY_KP_5         /* 5                     0x4c  */   76
#define KEY_KP_6         /* 6           Right     0x4d  */   77
#define KEY_KP_Plus      /* + (Plus)              0x4e  */   78
#define KEY_KP_1         /* 1           End       0x4f  */   79
#define KEY_KP_2         /* 2           Down      0x50  */   80
#define KEY_KP_3         /* 3           PgDown    0x51  */   81
#define KEY_KP_0         /* 0           Insert    0x52  */   82
#define KEY_KP_Decimal   /* . (Decimal) Delete    0x53  */   83 
#define KEY_SysReqest    /* SysReqest             0x54  */   84
                         /* NOTUSED               0x55  */
#define KEY_Less         /* < (Less)   >(Greater) 0x56  */   86
#define KEY_F11          /* F11                   0x57  */   87
#define KEY_F12          /* F12                   0x58  */   88

#define KEY_Prefix0      /* special               0x60  */   96
#define KEY_Prefix1      /* specail               0x61  */   97

/*
 * The 'scancodes' below are generated by the server, because the MF101/102
 * keyboard sends them as sequence of other scancodes
 */
#define KEY_Home         /* Home                  0x59  */   89
#define KEY_Up           /* Up                    0x5a  */   90
#define KEY_PgUp         /* PgUp                  0x5b  */   91
#define KEY_Left         /* Left                  0x5c  */   92
#define KEY_Begin        /* Begin                 0x5d  */   93
#define KEY_Right        /* Right                 0x5e  */   94
#define KEY_End          /* End                   0x5f  */   95
#define KEY_Down         /* Down                  0x60  */   96
#define KEY_PgDown       /* PgDown                0x61  */   97
#define KEY_Insert       /* Insert                0x62  */   98
#define KEY_Delete       /* Delete                0x63  */   99
#define KEY_KP_Enter     /* Enter                 0x64  */  100
#define KEY_RCtrl        /* Ctrl(right)           0x65  */  101
#define KEY_Pause        /* Pause                 0x66  */  102
#define KEY_Print        /* Print                 0x67  */  103
#define KEY_KP_Divide    /* Divide                0x68  */  104
#define KEY_AltLang      /* AtlLang(right)        0x69  */  105
#define KEY_Break        /* Break                 0x6a  */  106
#define KEY_LMeta        /* Left Meta             0x6b  */  107
#define KEY_RMeta        /* Right Meta            0x6c  */  108
#define KEY_Menu         /* Menu                  0x6d  */  109
#define KEY_F13          /* F13                   0x6e  */  110
#define KEY_F14          /* F14                   0x6f  */  111
#define KEY_F15          /* F15                   0x70  */  112
#define KEY_F16          /* F16                   0x71  */  113
#define KEY_F17          /* F17                   0x72  */  114
#define KEY_KP_DEC       /* KP_DEC                0x73  */  115
#define KEY_KP_Equal     /* Equal (Keypad)        0x76  */  118
#define KEY_XFER         /* Kanji Transfer        0x79  */  121
#define KEY_NFER         /* No Kanji Transfer     0x7b  */  123
#define KEY_Yen          /* Yen                   0x7d  */  125
#define KEY_HKTG         /* Hirugana/Katakana tog 0xc8  */  200
#define KEY_BSlash2      /* \           _         0xcb  */  203

struct{
    unsigned char key, mod;
}rune2keycode[] = {
    KEY_Delete, KEY_ShiftL, /* 0x000 */
    KEY_A,  KEY_LCtrl,  /* 0x001 */
    KEY_B,  KEY_LCtrl,  /* 0x002 */
    KEY_C,  KEY_LCtrl,  /* 0x003 */
    KEY_D,  KEY_LCtrl,  /* 0x004 */
    KEY_E,  KEY_LCtrl,  /* 0x005 */
    KEY_F,  KEY_LCtrl,  /* 0x006 */
    KEY_G,  KEY_LCtrl,  /* 0x007 */
    KEY_BackSpace,  0,  /* 0x008 */
    KEY_Tab,    0,  /* 0x009 */
    KEY_Enter,  0,  /* 0x00a */
    KEY_K,  KEY_LCtrl,  /* 0x00b */
    KEY_L,  KEY_LCtrl,  /* 0x00c */
    KEY_M,    KEY_LCtrl,  /* 0x00d */
    KEY_N,  KEY_LCtrl,  /* 0x00e */
    KEY_O,  KEY_LCtrl,  /* 0x00f */
    KEY_P,  KEY_LCtrl,  /* 0x010 */
    KEY_Q,  KEY_LCtrl,  /* 0x011 */
    KEY_R,  KEY_LCtrl,  /* 0x012 */
    KEY_S,  KEY_LCtrl,  /* 0x013 */
    KEY_T,  KEY_LCtrl,  /* 0x014 */
    KEY_U,  KEY_LCtrl,  /* 0x015 */
    KEY_V,  KEY_LCtrl,  /* 0x016 */
    KEY_W,  KEY_LCtrl,  /* 0x017 */
    KEY_X,  KEY_LCtrl,  /* 0x018 */
    KEY_Y,  KEY_LCtrl,  /* 0x019 */
    KEY_Z,  KEY_LCtrl,  /* 0x01a */
    KEY_Escape, 0,  /* 0x01b */
    KEY_BSlash, KEY_LCtrl,  /* 0x01c */
    KEY_RBrace, KEY_LCtrl,  /* 0x01d */
    KEY_Period, KEY_LCtrl,  /* 0x01e */
    KEY_Slash,  KEY_LCtrl,  /* 0x01f */
    KEY_Space,  0,  /* 0x020 */
    KEY_1,  KEY_ShiftL, /* 0x021 */
    KEY_Quote,  KEY_ShiftL, /* 0x022 */
    KEY_3,  KEY_ShiftL, /* 0x023 */
    KEY_4,  KEY_ShiftL, /* 0x024 */
    KEY_5,  KEY_ShiftL, /* 0x025 */
    KEY_7,  KEY_ShiftL, /* 0x026 */
    KEY_Quote,  0,  /* 0x027 */
    KEY_9,  KEY_ShiftL, /* 0x028 */
    KEY_0,  KEY_ShiftL, /* 0x029 */
    KEY_8,  KEY_ShiftL, /* 0x02a */
    KEY_Equal,  KEY_ShiftL, /* 0x02b */
    KEY_Comma,  0,  /* 0x02c */
    KEY_KP_Minus,   0,  /* 0x02d */
    KEY_Period,0,   /* 0x02e */
    KEY_Slash,  0,  /* 0x02f */
    KEY_0,  0,  /* 0x030 */
    KEY_1,  0,  /* 0x031 */
    KEY_2,  0,  /* 0x032 */
    KEY_3,  0,  /* 0x033 */
    KEY_4,  0,  /* 0x034 */
    KEY_5,  0,  /* 0x035 */
    KEY_6,  0,  /* 0x036 */
    KEY_7,  0,  /* 0x037 */
    KEY_8,  0,  /* 0x038 */
    KEY_9,  0,  /* 0x039 */
    KEY_SemiColon,  KEY_ShiftL, /* 0x03a */
    KEY_SemiColon,  0,  /* 0x03b */
    KEY_Comma,  KEY_ShiftL, /* 0x03c */
    KEY_Equal,  0,  /* 0x03d */
    KEY_Period, KEY_ShiftL, /* 0x03e */
    KEY_Slash,  KEY_ShiftL, /* 0x03f */
    KEY_2,  KEY_ShiftL, /* 0x040 */
    KEY_A,  KEY_ShiftL, /* 0x041 */
    KEY_B,  KEY_ShiftL, /* 0x042 */
    KEY_C,  KEY_ShiftL, /* 0x043 */
    KEY_D,  KEY_ShiftL, /* 0x044 */
    KEY_E,  KEY_ShiftL, /* 0x045 */
    KEY_F,  KEY_ShiftL, /* 0x046 */
    KEY_G,  KEY_ShiftL, /* 0x047 */
    KEY_H,  KEY_ShiftL, /* 0x048 */
    KEY_I,  KEY_ShiftL, /* 0x049 */
    KEY_J,  KEY_ShiftL, /* 0x04a */
    KEY_K,  KEY_ShiftL, /* 0x04b */
    KEY_L,  KEY_ShiftL, /* 0x04c */
    KEY_M,  KEY_ShiftL, /* 0x04d */
    KEY_N,  KEY_ShiftL, /* 0x04e */
    KEY_O,  KEY_ShiftL, /* 0x04f */
    KEY_P,  KEY_ShiftL, /* 0x050 */
    KEY_Q,  KEY_ShiftL, /* 0x051 */
    KEY_R,  KEY_ShiftL, /* 0x052 */
    KEY_S,  KEY_ShiftL, /* 0x053 */
    KEY_T,  KEY_ShiftL, /* 0x054 */
    KEY_U,  KEY_ShiftL, /* 0x055 */
    KEY_V,  KEY_ShiftL, /* 0x056 */
    KEY_W,  KEY_ShiftL, /* 0x057 */
    KEY_X,  KEY_ShiftL, /* 0x058 */
    KEY_Y,  KEY_ShiftL, /* 0x059 */
    KEY_Z,  KEY_ShiftL, /* 0x05a */
    KEY_LBrace, 0,  /* 0x05b */
    KEY_BSlash, 0,  /* 0x05c */
    KEY_RBrace, 0,  /* 0x05d */
    KEY_6,  KEY_ShiftL, /* 0x05e */
    KEY_Minus,  KEY_ShiftL, /* 0x05f */
    KEY_Tilde,0,    /* 0x060 */
    KEY_A,  0,  /* 0x061 */
    KEY_B,  0,  /* 0x062 */
    KEY_C,  0,  /* 0x063 */
    KEY_D,  0,  /* 0x064 */
    KEY_E,  0,  /* 0x065 */
    KEY_F,  0,  /* 0x066 */
    KEY_G,  0,  /* 0x067 */
    KEY_H,  0,  /* 0x068 */
    KEY_I,  0,  /* 0x069 */
    KEY_J,  0,  /* 0x06a */
    KEY_K,  0,  /* 0x06b */
    KEY_L,  0,  /* 0x06c */
    KEY_M,  0,  /* 0x06d */
    KEY_N,  0,  /* 0x06e */
    KEY_O,  0,  /* 0x06f */
    KEY_P,  0,  /* 0x070 */
    KEY_Q,  0,  /* 0x071 */
    KEY_R,  0,  /* 0x072 */
    KEY_S,  0,  /* 0x073 */
    KEY_T,  0,  /* 0x074 */
    KEY_U,  0,  /* 0x075 */
    KEY_V,  0,  /* 0x076 */
    KEY_W,  0,  /* 0x077 */
    KEY_X,  0,  /* 0x078 */
    KEY_Y,  0,  /* 0x079 */
    KEY_Z,  0,  /* 0x07a */
    KEY_LBrace, KEY_ShiftL, /* 0x07b */
    KEY_BSlash, KEY_ShiftL, /* 0x07c */
    KEY_RBrace, KEY_ShiftL, /* 0x07d */
    KEY_Tilde,  KEY_ShiftL, /* 0x07e */
    KEY_Delete, 0,  /* 0x07f */
    0,   0,  /* 0x080 */
    KEY_F1,  0,  /* 0x081 */
    KEY_F2,  0,  /* 0x082 */
    KEY_F3,  0,  /* 0x083 */
    KEY_F4,  0,  /* 0x084 */
    KEY_F5,  0,  /* 0x085 */
    KEY_F6,  0,  /* 0x086 */
    KEY_F7,  0,  /* 0x087 */
    KEY_F8,  0,  /* 0x088 */
    KEY_F9,  0,  /* 0x089 */
    KEY_F10,  0,  /* 0x08a */
    KEY_F11,  0,  /* 0x08b */
    KEY_F12,  0,  /* 0x08c */
    KEY_Home,  0,  /* 0x08d */
    KEY_Up,  0,  /* 0x08e */
    KEY_PgUp,  0,  /* 0x08f */
    KEY_Print,  0,  /* 0x090 */
    KEY_Left,  0,  /* 0x091 */
    KEY_Right,  0,  /* 0x092 */
    KEY_PgDown,  0,  /* 0x093 */
    KEY_Insert,  0,  /* 0x094 */
    0,  0,  /* 0x095 */
    0,  0,  /* 0x096 */
    0,  0,  /* 0x097 */
    KEY_End,  0,  /* 0x098 */
    KEY_Down,  0,  /* 0x099 */
    0,  0,  /* 0x09a */
    0,  0,  /* 0x09b */
    0,  0,  /* 0x09c */
    0,  0,  /* 0x09d */
    0,  0,  /* 0x09e */
    0,  0,  /* 0x09f */
    0,  0,  /* 0x0a0 */
    0,  0,  /* 0x0a1 */
    0,  0,  /* 0x0a2 */
    0,  0,  /* 0x0a3 */
    0,  0,  /* 0x0a4 */
    0,  0,  /* 0x0a5 */
    0,  0,  /* 0x0a6 */
    0,  0,  /* 0x0a7 */
    0,  0,  /* 0x0a8 */
    0,  0,  /* 0x0a9 */
    0,  0,  /* 0x0aa */
    0,  0,  /* 0x0ab */
    0,  0,  /* 0x0ac */
    0,  0,  /* 0x0ad */
    0,  0,  /* 0x0ae */
    0,  0,  /* 0x0af */
    0,  0,  /* 0x0b0 */
    0,  0,  /* 0x0b1 */
    0,  0,  /* 0x0b2 */
    0,  0,  /* 0x0b3 */
    0,  0,  /* 0x0b4 */
    0,  0,  /* 0x0b5 */
    0,  0,  /* 0x0b6 */
    0,  0,  /* 0x0b7 */
    0,  0,  /* 0x0b8 */
    0,  0,  /* 0x0b9 */
    0,  0,  /* 0x0ba */
    0,  0,  /* 0x0bb */
    0,  0,  /* 0x0bc */
    0,  0,  /* 0x0bd */
    0,  0,  /* 0x0be */
    0,  0,  /* 0x0bf */
    0,  0,  /* 0x0c0 */
    0,  0,  /* 0x0c1 */
    0,  0,  /* 0x0c2 */
    0,  0,  /* 0x0c3 */
    0,  0,  /* 0x0c4 */
    0,  0,  /* 0x0c5 */
    0,  0,  /* 0x0c6 */
    0,  0,  /* 0x0c7 */
    0,  0,  /* 0x0c8 */
    0,  0,  /* 0x0c9 */
    0,  0,  /* 0x0ca */
    0,  0,  /* 0x0cb */
    0,  0,  /* 0x0cc */
    0,  0,  /* 0x0cd */
    0,  0,  /* 0x0ce */
    0,  0,  /* 0x0cf */
    0,  0,  /* 0x0d0 */
    0,  0,  /* 0x0d1 */
    0,  0,  /* 0x0d2 */
    0,  0,  /* 0x0d3 */
    0,  0,  /* 0x0d4 */
    0,  0,  /* 0x0d5 */
    0,  0,  /* 0x0d6 */
    0,  0,  /* 0x0d7 */
    0,  0,  /* 0x0d8 */
    0,  0,  /* 0x0d9 */
    0,  0,  /* 0x0da */
    0,  0,  /* 0x0db */
    0,  0,  /* 0x0dc */
    0,  0,  /* 0x0dd */
    0,  0,  /* 0x0de */
    0,  0,  /* 0x0df */
    0,  0,  /* 0x0e0 */
    0,  0,  /* 0x0e1 */
    0,  0,  /* 0x0e2 */
    0,  0,  /* 0x0e3 */
    0,  0,  /* 0x0e4 */
    0,  0,  /* 0x0e5 */
    0,  0,  /* 0x0e6 */
    0,  0,  /* 0x0e7 */
    0,  0,  /* 0x0e8 */
    0,  0,  /* 0x0e9 */
    0,  0,  /* 0x0ea */
    0,  0,  /* 0x0eb */
    0,  0,  /* 0x0ec */
    0,  0,  /* 0x0ed */
    0,  0,  /* 0x0ee */
    0,  0,  /* 0x0ef */
    0,  0,  /* 0x0f0 */
    0,  0,  /* 0x0f1 */
    0,  0,  /* 0x0f2 */
    0,  0,  /* 0x0f3 */
    0,  0,  /* 0x0f4 */
    0,  0,  /* 0x0f5 */
    0,  0,  /* 0x0f6 */
    0,  0,  /* 0x0f7 */
    0,  0,  /* 0x0f8 */
    0,  0,  /* 0x0f9 */
    0,  0,  /* 0x0fa */
    0,  0,  /* 0x0fb */
    0,  0,  /* 0x0fc */
    0,  0,  /* 0x0fd */
    0,  0,  /* 0x0fe */
    0,  0,  /* 0x0ff */
};

/* from xwin/winkeymap.h */
static KeySym map[NUM_KEYCODES*MAP_WIDTH]={
    /* 0x00 */  NoSymbol,       NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x01 */  XK_Escape,      NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x02 */  XK_1,           XK_exclam,  NoSymbol,   NoSymbol,
    /* 0x03 */  XK_2,           XK_at,      NoSymbol,   NoSymbol,
    /* 0x04 */  XK_3,           XK_numbersign,  NoSymbol,   NoSymbol,
    /* 0x05 */  XK_4,           XK_dollar,  NoSymbol,   NoSymbol,
    /* 0x06 */  XK_5,           XK_percent, NoSymbol,   NoSymbol,
    /* 0x07 */  XK_6,           XK_asciicircum, NoSymbol,   NoSymbol,
    /* 0x08 */  XK_7,           XK_ampersand,   NoSymbol,   NoSymbol,
    /* 0x09 */  XK_8,           XK_asterisk,    NoSymbol,   NoSymbol,
    /* 0x0a */  XK_9,           XK_parenleft,   NoSymbol,   NoSymbol,
    /* 0x0b */  XK_0,           XK_parenright,  NoSymbol,   NoSymbol,
    /* 0x0c */  XK_minus,       XK_underscore,  NoSymbol,   NoSymbol,
    /* 0x0d */  XK_equal,       XK_plus,    NoSymbol,   NoSymbol,
    /* 0x0e */  XK_BackSpace,   NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x0f */  XK_Tab,         XK_ISO_Left_Tab,NoSymbol,   NoSymbol,
    /* 0x10 */  XK_Q,           NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x11 */  XK_W,           NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x12 */  XK_E,           NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x13 */  XK_R,           NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x14 */  XK_T,           NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x15 */  XK_Y,           NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x16 */  XK_U,           NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x17 */  XK_I,           NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x18 */  XK_O,           NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x19 */  XK_P,           NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x1a */  XK_bracketleft, XK_braceleft,   NoSymbol,   NoSymbol,
    /* 0x1b */  XK_bracketright,XK_braceright,  NoSymbol,   NoSymbol,
    /* 0x1c */  XK_Return,      NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x1d */  XK_Control_L,   NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x1e */  XK_A,           NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x1f */  XK_S,           NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x20 */  XK_D,           NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x21 */  XK_F,           NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x22 */  XK_G,           NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x23 */  XK_H,           NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x24 */  XK_J,           NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x25 */  XK_K,           NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x26 */  XK_L,           NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x27 */  XK_semicolon,   XK_colon,   NoSymbol,   NoSymbol,
    /* 0x28 */  XK_quoteright,  XK_quotedbl,    NoSymbol,   NoSymbol,
    /* 0x29 */  XK_quoteleft,   XK_asciitilde,  NoSymbol,   NoSymbol,
    /* 0x2a */  XK_Shift_L,     NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x2b */  XK_backslash,   XK_bar,     NoSymbol,   NoSymbol,
    /* 0x2c */  XK_Z,           NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x2d */  XK_X,           NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x2e */  XK_C,           NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x2f */  XK_V,           NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x30 */  XK_B,           NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x31 */  XK_N,           NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x32 */  XK_M,           NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x33 */  XK_comma,       XK_less,    NoSymbol,   NoSymbol,
    /* 0x34 */  XK_period,      XK_greater, NoSymbol,   NoSymbol,
    /* 0x35 */  XK_slash,       XK_question,    NoSymbol,   NoSymbol,
    /* 0x36 */  XK_Shift_R,     NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x37 */  XK_KP_Multiply, NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x38 */  XK_Alt_L,   XK_Meta_L,  NoSymbol,   NoSymbol,
    /* 0x39 */  XK_space,       NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x3a */  XK_Caps_Lock,   NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x3b */  XK_F1,          NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x3c */  XK_F2,          NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x3d */  XK_F3,          NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x3e */  XK_F4,          NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x3f */  XK_F5,          NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x40 */  XK_F6,          NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x41 */  XK_F7,          NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x42 */  XK_F8,          NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x43 */  XK_F9,          NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x44 */  XK_F10,         NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x45 */  XK_Num_Lock,    NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x46 */  XK_Scroll_Lock, NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x47 */  XK_KP_Home, XK_KP_7,    NoSymbol,   NoSymbol,
    /* 0x48 */  XK_KP_Up,   XK_KP_8,    NoSymbol,   NoSymbol,
    /* 0x49 */  XK_KP_Prior,    XK_KP_9,    NoSymbol,   NoSymbol,
    /* 0x4a */  XK_KP_Subtract, NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x4b */  XK_KP_Left, XK_KP_4,    NoSymbol,   NoSymbol,
    /* 0x4c */  XK_KP_Begin,    XK_KP_5,    NoSymbol,   NoSymbol,
    /* 0x4d */  XK_KP_Right,    XK_KP_6,    NoSymbol,   NoSymbol,
    /* 0x4e */  XK_KP_Add,      NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x4f */  XK_KP_End,  XK_KP_1,    NoSymbol,   NoSymbol,
    /* 0x50 */  XK_KP_Down, XK_KP_2,    NoSymbol,   NoSymbol,
    /* 0x51 */  XK_KP_Next, XK_KP_3,    NoSymbol,   NoSymbol,
    /* 0x52 */  XK_KP_Insert,   XK_KP_0,    NoSymbol,   NoSymbol,
    /* 0x53 */  XK_KP_Delete,   XK_KP_Decimal,  NoSymbol,   NoSymbol,
    /* 0x54 */  XK_Sys_Req, NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x55 */  NoSymbol,   NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x56 */  XK_less,    XK_greater, NoSymbol,   NoSymbol,
    /* 0x57 */  XK_F11,     NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x58 */  XK_F12,     NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x59 */  XK_Home,    NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x5a */  XK_Up,      NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x5b */  XK_Prior,   NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x5c */  XK_Left,    NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x5d */  XK_Begin,   NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x5e */  XK_Right,   NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x5f */  XK_End,     NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x60 */  XK_Down,    NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x61 */  XK_Next,    NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x62 */  XK_Insert,  NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x63 */  XK_Delete,  NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x64 */  XK_KP_Enter,    NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x65 */  XK_Control_R,   NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x66 */  XK_Pause,   NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x67 */  XK_Print,   NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x68 */  XK_KP_Divide,   NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x69 */  XK_Alt_R,   XK_Meta_R,  NoSymbol,   NoSymbol,
    /* 0x6a */  XK_Break,   NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x6b */  XK_Meta_L,  NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x6c */  XK_Meta_R,  NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x6d */  XK_Menu,    NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x6e */  XK_F13,     NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x6f */  XK_F14,     NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x70 */  XK_F15,     NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x71 */  XK_F16,     NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x72 */  XK_F17,     NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x73 */  XK_backslash,   XK_underscore,  NoSymbol,   NoSymbol,
    /* 0x74 */  NoSymbol,   NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x75 */  NoSymbol,   NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x76 */  NoSymbol,   NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x77 */  NoSymbol,   NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x78 */  NoSymbol,   NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x79 */  XK_Henkan,  XK_Mode_switch, NoSymbol,   NoSymbol,
    /* 0x7a */  NoSymbol,   NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x7b */  XK_Muhenkan,    NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x7c */  NoSymbol,   NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x7d */  XK_backslash,   XK_bar,     NoSymbol,   NoSymbol,
    /* 0x7e */  NoSymbol,   NoSymbol,   NoSymbol,   NoSymbol,
    /* 0x7f */  NoSymbol,   NoSymbol,   NoSymbol,   NoSymbol,
};
