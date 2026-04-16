/* ANSI-C code produced by gperf version 3.3 */
/* Command-line: gperf -m 10 unictype/scripts_byname.gperf  */
/* Computed positions: -k'1,3,5,8' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gperf@gnu.org>."
#endif

#line 20 "unictype/scripts_byname.gperf"
struct named_script { int name; unsigned int index; };

#define TOTAL_KEYWORDS 174
#define MIN_WORD_LENGTH 2
#define MAX_WORD_LENGTH 22
#define MIN_HASH_VALUE 11
#define MAX_HASH_VALUE 267
/* maximum key range = 257, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
scripts_hash (register const char *str, register size_t len)
{
  static const unsigned short asso_values[] =
    {
      268, 268, 268, 268, 268, 268, 268, 268, 268, 268,
      268, 268, 268, 268, 268, 268, 268, 268, 268, 268,
      268, 268, 268, 268, 268, 268, 268, 268, 268, 268,
      268, 268, 268, 268, 268, 268, 268, 268, 268, 268,
      268, 268, 268, 268, 268, 268, 268, 268, 268, 268,
      268, 268, 268, 268, 268, 268, 268, 268, 268, 268,
      268, 268, 268, 268, 268,  33,  45,   3, 106,  19,
      268,  64, 117,  57,   3,  13,  36,   5,  70,  36,
       40, 268,  34,   6,   4,  49, 120, 108, 268, 156,
        9, 268, 268, 268, 268,  62, 268,   6,  84,  96,
       30,  41,  85,  50,  69,   9,  63,  46,  49,   5,
        3,   3,  98, 268,   9,  71,   4,  24,  11,  29,
      268,  73,   4, 268, 268, 268, 268, 268, 268, 268,
      268, 268, 268, 268, 268, 268, 268, 268, 268, 268,
      268, 268, 268, 268, 268, 268, 268, 268, 268, 268,
      268, 268, 268, 268, 268, 268, 268, 268, 268, 268,
      268, 268, 268, 268, 268, 268, 268, 268, 268, 268,
      268, 268, 268, 268, 268, 268, 268, 268, 268, 268,
      268, 268, 268, 268, 268, 268, 268, 268, 268, 268,
      268, 268, 268, 268, 268, 268, 268, 268, 268, 268,
      268, 268, 268, 268, 268, 268, 268, 268, 268, 268,
      268, 268, 268, 268, 268, 268, 268, 268, 268, 268,
      268, 268, 268, 268, 268, 268, 268, 268, 268, 268,
      268, 268, 268, 268, 268, 268, 268, 268, 268, 268,
      268, 268, 268, 268, 268, 268, 268, 268, 268, 268,
      268, 268, 268, 268, 268, 268
    };
  register unsigned int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[7]];
#if (defined __cplusplus && (__cplusplus >= 201703L || (__cplusplus >= 201103L && defined __clang__ && __clang_major__ + (__clang_minor__ >= 9) > 3))) || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 202000L && ((defined __GNUC__ && __GNUC__ >= 10) || (defined __clang__ && __clang_major__ >= 9)))
      [[fallthrough]];
#elif (defined __GNUC__ && __GNUC__ >= 7) || (defined __clang__ && __clang_major__ >= 10)
      __attribute__ ((__fallthrough__));
#endif
      /*FALLTHROUGH*/
      case 7:
      case 6:
      case 5:
        hval += asso_values[(unsigned char)str[4]];
#if (defined __cplusplus && (__cplusplus >= 201703L || (__cplusplus >= 201103L && defined __clang__ && __clang_major__ + (__clang_minor__ >= 9) > 3))) || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 202000L && ((defined __GNUC__ && __GNUC__ >= 10) || (defined __clang__ && __clang_major__ >= 9)))
      [[fallthrough]];
#elif (defined __GNUC__ && __GNUC__ >= 7) || (defined __clang__ && __clang_major__ >= 10)
      __attribute__ ((__fallthrough__));
#endif
      /*FALLTHROUGH*/
      case 4:
      case 3:
        hval += asso_values[(unsigned char)str[2]];
#if (defined __cplusplus && (__cplusplus >= 201703L || (__cplusplus >= 201103L && defined __clang__ && __clang_major__ + (__clang_minor__ >= 9) > 3))) || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 202000L && ((defined __GNUC__ && __GNUC__ >= 10) || (defined __clang__ && __clang_major__ >= 9)))
      [[fallthrough]];
#elif (defined __GNUC__ && __GNUC__ >= 7) || (defined __clang__ && __clang_major__ >= 10)
      __attribute__ ((__fallthrough__));
#endif
      /*FALLTHROUGH*/
      case 2:
      case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
  return hval;
}

struct script_stringpool_t
  {
    char script_stringpool_str11[sizeof("Mro")];
    char script_stringpool_str12[sizeof("Toto")];
    char script_stringpool_str13[sizeof("Cham")];
    char script_stringpool_str14[sizeof("Thai")];
    char script_stringpool_str15[sizeof("Miao")];
    char script_stringpool_str17[sizeof("Common")];
    char script_stringpool_str19[sizeof("Thaana")];
    char script_stringpool_str20[sizeof("Chakma")];
    char script_stringpool_str21[sizeof("Mandaic")];
    char script_stringpool_str22[sizeof("Sinhala")];
    char script_stringpool_str23[sizeof("Myanmar")];
    char script_stringpool_str24[sizeof("Carian")];
    char script_stringpool_str25[sizeof("Sharada")];
    char script_stringpool_str26[sizeof("Mongolian")];
    char script_stringpool_str27[sizeof("Syriac")];
    char script_stringpool_str28[sizeof("Shavian")];
    char script_stringpool_str29[sizeof("Kannada")];
    char script_stringpool_str30[sizeof("Tai_Tham")];
    char script_stringpool_str31[sizeof("Chorasmian")];
    char script_stringpool_str32[sizeof("Khmer")];
    char script_stringpool_str33[sizeof("Cuneiform")];
    char script_stringpool_str35[sizeof("Samaritan")];
    char script_stringpool_str36[sizeof("Kharoshthi")];
    char script_stringpool_str37[sizeof("Tangut")];
    char script_stringpool_str39[sizeof("Modi")];
    char script_stringpool_str40[sizeof("Ahom")];
    char script_stringpool_str41[sizeof("Kirat_Rai")];
    char script_stringpool_str42[sizeof("Lao")];
    char script_stringpool_str44[sizeof("Tirhuta")];
    char script_stringpool_str45[sizeof("Sunuwar")];
    char script_stringpool_str46[sizeof("Kawi")];
    char script_stringpool_str47[sizeof("Sidetic")];
    char script_stringpool_str48[sizeof("Latin")];
    char script_stringpool_str49[sizeof("Todhri")];
    char script_stringpool_str50[sizeof("Saurashtra")];
    char script_stringpool_str51[sizeof("Osmanya")];
    char script_stringpool_str52[sizeof("Armenian")];
    char script_stringpool_str53[sizeof("Khitan_Small_Script")];
    char script_stringpool_str54[sizeof("Arabic")];
    char script_stringpool_str55[sizeof("Tai_Le")];
    char script_stringpool_str56[sizeof("Oriya")];
    char script_stringpool_str57[sizeof("Caucasian_Albanian")];
    char script_stringpool_str58[sizeof("Canadian_Aboriginal")];
    char script_stringpool_str60[sizeof("Bamum")];
    char script_stringpool_str61[sizeof("Bengali")];
    char script_stringpool_str62[sizeof("Brahmi")];
    char script_stringpool_str63[sizeof("Tamil")];
    char script_stringpool_str64[sizeof("Takri")];
    char script_stringpool_str65[sizeof("Phoenician")];
    char script_stringpool_str66[sizeof("Javanese")];
    char script_stringpool_str67[sizeof("Multani")];
    char script_stringpool_str68[sizeof("Khojki")];
    char script_stringpool_str69[sizeof("Anatolian_Hieroglyphs")];
    char script_stringpool_str70[sizeof("Limbu")];
    char script_stringpool_str71[sizeof("Mende_Kikakui")];
    char script_stringpool_str72[sizeof("Sogdian")];
    char script_stringpool_str73[sizeof("Tolong_Siki")];
    char script_stringpool_str74[sizeof("Tagbanwa")];
    char script_stringpool_str76[sizeof("Nko")];
    char script_stringpool_str77[sizeof("Katakana")];
    char script_stringpool_str78[sizeof("Lydian")];
    char script_stringpool_str79[sizeof("Beria_Erfe")];
    char script_stringpool_str81[sizeof("Grantha")];
    char script_stringpool_str82[sizeof("Khudawadi")];
    char script_stringpool_str83[sizeof("Gothic")];
    char script_stringpool_str84[sizeof("Tangsa")];
    char script_stringpool_str85[sizeof("Avestan")];
    char script_stringpool_str86[sizeof("Linear_A")];
    char script_stringpool_str87[sizeof("Glagolitic")];
    char script_stringpool_str88[sizeof("Osage")];
    char script_stringpool_str90[sizeof("Marchen")];
    char script_stringpool_str91[sizeof("Soyombo")];
    char script_stringpool_str92[sizeof("Adlam")];
    char script_stringpool_str93[sizeof("Old_South_Arabian")];
    char script_stringpool_str94[sizeof("Sora_Sompeng")];
    char script_stringpool_str95[sizeof("Sundanese")];
    char script_stringpool_str96[sizeof("Cherokee")];
    char script_stringpool_str97[sizeof("Kaithi")];
    char script_stringpool_str98[sizeof("Linear_B")];
    char script_stringpool_str99[sizeof("Tibetan")];
    char script_stringpool_str100[sizeof("Batak")];
    char script_stringpool_str101[sizeof("Gurung_Khema")];
    char script_stringpool_str103[sizeof("Newa")];
    char script_stringpool_str104[sizeof("Meetei_Mayek")];
    char script_stringpool_str105[sizeof("Elymaic")];
    char script_stringpool_str106[sizeof("Rejang")];
    char script_stringpool_str107[sizeof("Braille")];
    char script_stringpool_str108[sizeof("Ol_Onal")];
    char script_stringpool_str109[sizeof("Telugu")];
    char script_stringpool_str110[sizeof("Tagalog")];
    char script_stringpool_str111[sizeof("Lisu")];
    char script_stringpool_str112[sizeof("Siddham")];
    char script_stringpool_str113[sizeof("Old_Sogdian")];
    char script_stringpool_str114[sizeof("Gurmukhi")];
    char script_stringpool_str115[sizeof("Ogham")];
    char script_stringpool_str116[sizeof("Coptic")];
    char script_stringpool_str117[sizeof("Cypriot")];
    char script_stringpool_str118[sizeof("Zanabazar_Square")];
    char script_stringpool_str119[sizeof("Egyptian_Hieroglyphs")];
    char script_stringpool_str121[sizeof("Old_Permic")];
    char script_stringpool_str123[sizeof("Han")];
    char script_stringpool_str125[sizeof("Cypro_Minoan")];
    char script_stringpool_str126[sizeof("Old_Turkic")];
    char script_stringpool_str127[sizeof("Psalter_Pahlavi")];
    char script_stringpool_str128[sizeof("Georgian")];
    char script_stringpool_str129[sizeof("Makasar")];
    char script_stringpool_str130[sizeof("Hanunoo")];
    char script_stringpool_str131[sizeof("Phags_Pa")];
    char script_stringpool_str132[sizeof("Vai")];
    char script_stringpool_str133[sizeof("Hatran")];
    char script_stringpool_str134[sizeof("Warang_Citi")];
    char script_stringpool_str135[sizeof("Meroitic_Cursive")];
    char script_stringpool_str136[sizeof("Devanagari")];
    char script_stringpool_str137[sizeof("Bassa_Vah")];
    char script_stringpool_str138[sizeof("Runic")];
    char script_stringpool_str139[sizeof("Meroitic_Hieroglyphs")];
    char script_stringpool_str140[sizeof("Pau_Cin_Hau")];
    char script_stringpool_str141[sizeof("Syloti_Nagri")];
    char script_stringpool_str142[sizeof("Malayalam")];
    char script_stringpool_str143[sizeof("Nandinagari")];
    char script_stringpool_str144[sizeof("Lycian")];
    char script_stringpool_str145[sizeof("Tai_Viet")];
    char script_stringpool_str146[sizeof("Balinese")];
    char script_stringpool_str147[sizeof("Buginese")];
    char script_stringpool_str148[sizeof("Gunjala_Gondi")];
    char script_stringpool_str149[sizeof("Buhid")];
    char script_stringpool_str150[sizeof("Hangul")];
    char script_stringpool_str151[sizeof("Garay")];
    char script_stringpool_str152[sizeof("Bhaiksuki")];
    char script_stringpool_str153[sizeof("Gujarati")];
    char script_stringpool_str154[sizeof("Mahajani")];
    char script_stringpool_str155[sizeof("Manichaean")];
    char script_stringpool_str156[sizeof("Greek")];
    char script_stringpool_str157[sizeof("Old_North_Arabian")];
    char script_stringpool_str158[sizeof("Yi")];
    char script_stringpool_str159[sizeof("Bopomofo")];
    char script_stringpool_str160[sizeof("Masaram_Gondi")];
    char script_stringpool_str161[sizeof("Medefaidrin")];
    char script_stringpool_str162[sizeof("Inscriptional_Pahlavi")];
    char script_stringpool_str163[sizeof("Inscriptional_Parthian")];
    char script_stringpool_str165[sizeof("Cyrillic")];
    char script_stringpool_str166[sizeof("Nag_Mundari")];
    char script_stringpool_str167[sizeof("Dogra")];
    char script_stringpool_str168[sizeof("Ugaritic")];
    char script_stringpool_str169[sizeof("Tifinagh")];
    char script_stringpool_str170[sizeof("Nushu")];
    char script_stringpool_str172[sizeof("Kayah_Li")];
    char script_stringpool_str173[sizeof("Nabataean")];
    char script_stringpool_str174[sizeof("Palmyrene")];
    char script_stringpool_str175[sizeof("Tai_Yo")];
    char script_stringpool_str176[sizeof("New_Tai_Lue")];
    char script_stringpool_str178[sizeof("Tulu_Tigalari")];
    char script_stringpool_str179[sizeof("SignWriting")];
    char script_stringpool_str181[sizeof("Elbasan")];
    char script_stringpool_str182[sizeof("Old_Italic")];
    char script_stringpool_str184[sizeof("Ol_Chiki")];
    char script_stringpool_str185[sizeof("Inherited")];
    char script_stringpool_str186[sizeof("Wancho")];
    char script_stringpool_str187[sizeof("Vithkuqi")];
    char script_stringpool_str188[sizeof("Old_Persian")];
    char script_stringpool_str190[sizeof("Hiragana")];
    char script_stringpool_str193[sizeof("Deseret")];
    char script_stringpool_str194[sizeof("Old_Uyghur")];
    char script_stringpool_str195[sizeof("Ethiopic")];
    char script_stringpool_str196[sizeof("Yezidi")];
    char script_stringpool_str197[sizeof("Nyiakeng_Puachue_Hmong")];
    char script_stringpool_str209[sizeof("Lepcha")];
    char script_stringpool_str218[sizeof("Duployan")];
    char script_stringpool_str229[sizeof("Imperial_Aramaic")];
    char script_stringpool_str245[sizeof("Dives_Akuru")];
    char script_stringpool_str246[sizeof("Old_Hungarian")];
    char script_stringpool_str248[sizeof("Hebrew")];
    char script_stringpool_str254[sizeof("Hanifi_Rohingya")];
    char script_stringpool_str267[sizeof("Pahawh_Hmong")];
  };
static const struct script_stringpool_t script_stringpool_contents =
  {
    "Mro",
    "Toto",
    "Cham",
    "Thai",
    "Miao",
    "Common",
    "Thaana",
    "Chakma",
    "Mandaic",
    "Sinhala",
    "Myanmar",
    "Carian",
    "Sharada",
    "Mongolian",
    "Syriac",
    "Shavian",
    "Kannada",
    "Tai_Tham",
    "Chorasmian",
    "Khmer",
    "Cuneiform",
    "Samaritan",
    "Kharoshthi",
    "Tangut",
    "Modi",
    "Ahom",
    "Kirat_Rai",
    "Lao",
    "Tirhuta",
    "Sunuwar",
    "Kawi",
    "Sidetic",
    "Latin",
    "Todhri",
    "Saurashtra",
    "Osmanya",
    "Armenian",
    "Khitan_Small_Script",
    "Arabic",
    "Tai_Le",
    "Oriya",
    "Caucasian_Albanian",
    "Canadian_Aboriginal",
    "Bamum",
    "Bengali",
    "Brahmi",
    "Tamil",
    "Takri",
    "Phoenician",
    "Javanese",
    "Multani",
    "Khojki",
    "Anatolian_Hieroglyphs",
    "Limbu",
    "Mende_Kikakui",
    "Sogdian",
    "Tolong_Siki",
    "Tagbanwa",
    "Nko",
    "Katakana",
    "Lydian",
    "Beria_Erfe",
    "Grantha",
    "Khudawadi",
    "Gothic",
    "Tangsa",
    "Avestan",
    "Linear_A",
    "Glagolitic",
    "Osage",
    "Marchen",
    "Soyombo",
    "Adlam",
    "Old_South_Arabian",
    "Sora_Sompeng",
    "Sundanese",
    "Cherokee",
    "Kaithi",
    "Linear_B",
    "Tibetan",
    "Batak",
    "Gurung_Khema",
    "Newa",
    "Meetei_Mayek",
    "Elymaic",
    "Rejang",
    "Braille",
    "Ol_Onal",
    "Telugu",
    "Tagalog",
    "Lisu",
    "Siddham",
    "Old_Sogdian",
    "Gurmukhi",
    "Ogham",
    "Coptic",
    "Cypriot",
    "Zanabazar_Square",
    "Egyptian_Hieroglyphs",
    "Old_Permic",
    "Han",
    "Cypro_Minoan",
    "Old_Turkic",
    "Psalter_Pahlavi",
    "Georgian",
    "Makasar",
    "Hanunoo",
    "Phags_Pa",
    "Vai",
    "Hatran",
    "Warang_Citi",
    "Meroitic_Cursive",
    "Devanagari",
    "Bassa_Vah",
    "Runic",
    "Meroitic_Hieroglyphs",
    "Pau_Cin_Hau",
    "Syloti_Nagri",
    "Malayalam",
    "Nandinagari",
    "Lycian",
    "Tai_Viet",
    "Balinese",
    "Buginese",
    "Gunjala_Gondi",
    "Buhid",
    "Hangul",
    "Garay",
    "Bhaiksuki",
    "Gujarati",
    "Mahajani",
    "Manichaean",
    "Greek",
    "Old_North_Arabian",
    "Yi",
    "Bopomofo",
    "Masaram_Gondi",
    "Medefaidrin",
    "Inscriptional_Pahlavi",
    "Inscriptional_Parthian",
    "Cyrillic",
    "Nag_Mundari",
    "Dogra",
    "Ugaritic",
    "Tifinagh",
    "Nushu",
    "Kayah_Li",
    "Nabataean",
    "Palmyrene",
    "Tai_Yo",
    "New_Tai_Lue",
    "Tulu_Tigalari",
    "SignWriting",
    "Elbasan",
    "Old_Italic",
    "Ol_Chiki",
    "Inherited",
    "Wancho",
    "Vithkuqi",
    "Old_Persian",
    "Hiragana",
    "Deseret",
    "Old_Uyghur",
    "Ethiopic",
    "Yezidi",
    "Nyiakeng_Puachue_Hmong",
    "Lepcha",
    "Duployan",
    "Imperial_Aramaic",
    "Dives_Akuru",
    "Old_Hungarian",
    "Hebrew",
    "Hanifi_Rohingya",
    "Pahawh_Hmong"
  };
#define script_stringpool ((const char *) &script_stringpool_contents)

#if (defined __GNUC__ && __GNUC__ + (__GNUC_MINOR__ >= 6) > 4) || (defined __clang__ && __clang_major__ >= 3)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
static const struct named_script script_names[] =
  {
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1},
#line 145 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str11, 114},
#line 190 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str12, 159},
#line 107 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str13, 76},
#line 50 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str14, 19},
#line 129 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str15, 98},
    {-1},
#line 31 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str17, 0},
    {-1},
#line 39 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str19, 8},
#line 126 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str20, 95},
#line 125 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str21, 94},
#line 49 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str22, 18},
#line 53 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str23, 22},
#line 105 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str24, 74},
#line 130 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str25, 99},
#line 62 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str26, 31},
#line 38 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str27, 7},
#line 80 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str28, 49},
#line 47 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str29, 16},
#line 108 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str30, 77},
#line 183 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str31, 152},
#line 61 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str32, 30},
#line 93 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str33, 62},
    {-1},
#line 112 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str35, 81},
#line 91 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str36, 60},
#line 167 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str37, 136},
    {-1},
#line 144 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str39, 113},
#line 156 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str40, 125},
#line 196 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str41, 165},
#line 51 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str42, 20},
    {-1},
#line 154 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str44, 123},
#line 198 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str45, 167},
#line 192 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str46, 161},
#line 201 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str47, 170},
#line 32 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str48, 1},
#line 199 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str49, 168},
#line 101 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str50, 70},
#line 81 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str51, 50},
#line 35 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str52, 4},
#line 185 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str53, 154},
#line 37 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str54, 6},
#line 77 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str55, 46},
#line 44 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str56, 13},
#line 133 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str57, 102},
#line 58 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str58, 27},
    {-1},
#line 114 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str60, 83},
#line 41 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str61, 10},
#line 124 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str62, 93},
#line 45 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str63, 14},
#line 132 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str64, 101},
#line 94 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str65, 63},
#line 115 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str66, 84},
#line 159 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str67, 128},
#line 139 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str68, 108},
#line 157 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str69, 126},
#line 76 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str70, 45},
#line 143 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str71, 112},
#line 177 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str72, 146},
#line 203 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str73, 172},
#line 75 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str74, 44},
    {-1},
#line 96 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str76, 65},
#line 64 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str77, 33},
#line 106 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str78, 75},
#line 204 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str79, 173},
    {-1},
#line 137 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str81, 106},
#line 153 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str82, 122},
#line 69 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str83, 38},
#line 189 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str84, 158},
#line 110 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str85, 79},
#line 140 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str86, 109},
#line 87 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str87, 56},
#line 166 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str88, 135},
    {-1},
#line 164 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str90, 133},
#line 170 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str91, 139},
#line 162 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str92, 131},
#line 118 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str93, 87},
#line 131 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str94, 100},
#line 97 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str95, 66},
#line 57 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str96, 26},
#line 122 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str97, 91},
#line 78 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str98, 47},
#line 52 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str99, 21},
#line 123 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str100, 92},
#line 195 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str101, 164},
    {-1},
#line 165 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str103, 134},
#line 116 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str104, 85},
#line 179 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str105, 148},
#line 103 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str106, 72},
#line 83 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str107, 52},
#line 197 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str108, 166},
#line 46 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str109, 15},
#line 72 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str110, 41},
#line 113 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str111, 82},
#line 152 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str112, 121},
#line 178 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str113, 147},
#line 42 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str114, 11},
#line 59 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str115, 28},
#line 85 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str116, 54},
#line 82 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str117, 51},
#line 171 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str118, 140},
#line 111 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str119, 80},
    {-1},
#line 150 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str121, 119},
    {-1},
#line 66 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str123, 35},
    {-1},
#line 187 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str125, 156},
#line 121 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str126, 90},
#line 151 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str127, 120},
#line 54 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str128, 23},
#line 174 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str129, 143},
#line 73 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str130, 42},
#line 95 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str131, 64},
#line 100 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str132, 69},
#line 158 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str133, 127},
#line 155 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str134, 124},
#line 127 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str135, 96},
#line 40 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str136, 9},
#line 134 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str137, 103},
#line 60 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str138, 29},
#line 128 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str139, 97},
#line 149 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str140, 118},
#line 89 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str141, 58},
#line 48 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str142, 17},
#line 180 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str143, 149},
#line 104 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str144, 73},
#line 109 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str145, 78},
#line 92 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str146, 61},
#line 84 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str147, 53},
#line 173 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str148, 142},
#line 74 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str149, 43},
#line 55 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str150, 24},
#line 194 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str151, 163},
#line 163 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str152, 132},
#line 43 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str153, 12},
#line 141 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str154, 110},
#line 142 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str155, 111},
#line 33 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str156, 2},
#line 146 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str157, 115},
#line 67 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str158, 36},
#line 65 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str159, 34},
#line 168 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str160, 137},
#line 175 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str161, 144},
#line 120 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str162, 89},
#line 119 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str163, 88},
    {-1},
#line 34 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str165, 3},
#line 193 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str166, 162},
#line 172 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str167, 141},
#line 79 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str168, 48},
#line 88 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str169, 57},
#line 169 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str170, 138},
    {-1},
#line 102 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str172, 71},
#line 147 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str173, 116},
#line 148 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str174, 117},
#line 202 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str175, 171},
#line 86 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str176, 55},
    {-1},
#line 200 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str178, 169},
#line 161 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str179, 130},
    {-1},
#line 136 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str181, 105},
#line 68 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str182, 37},
    {-1},
#line 99 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str184, 68},
#line 71 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str185, 40},
#line 182 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str186, 151},
#line 191 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str187, 160},
#line 90 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str188, 59},
    {-1},
#line 63 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str190, 32},
    {-1}, {-1},
#line 70 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str193, 39},
#line 188 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str194, 157},
#line 56 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str195, 25},
#line 186 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str196, 155},
#line 181 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str197, 150},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1},
#line 98 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str209, 67},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 135 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str218, 104},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1},
#line 117 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str229, 86},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 184 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str245, 153},
#line 160 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str246, 129},
    {-1},
#line 36 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str248, 5},
    {-1}, {-1}, {-1}, {-1}, {-1},
#line 176 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str254, 145},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1},
#line 138 "unictype/scripts_byname.gperf"
    {(int)(size_t)&((struct script_stringpool_t *)0)->script_stringpool_str267, 107}
  };
#if (defined __GNUC__ && __GNUC__ + (__GNUC_MINOR__ >= 6) > 4) || (defined __clang__ && __clang_major__ >= 3)
#pragma GCC diagnostic pop
#endif

static const struct named_script *
uc_script_lookup (register const char *str, register size_t len)
{
  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register unsigned int key = scripts_hash (str, len);

      if (key <= MAX_HASH_VALUE)
        {
          register int o = script_names[key].name;
          if (o >= 0)
            {
              register const char *s = o + script_stringpool;

              if (*str == *s && !strcmp (str + 1, s + 1))
                return &script_names[key];
            }
        }
    }
  return (struct named_script *) 0;
}
