/* ANSI-C code produced by gperf version 3.3 */
/* Command-line: gperf -m 10 unictype/pr_byname.gperf  */
/* Computed positions: -k'1-2,8,14,18,$' */

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

#line 25 "unictype/pr_byname.gperf"
struct named_property { int name; int property_index; };

#define TOTAL_KEYWORDS 219
#define MIN_WORD_LENGTH 2
#define MAX_WORD_LENGTH 34
#define MIN_HASH_VALUE 14
#define MAX_HASH_VALUE 565
/* maximum key range = 552, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
properties_hash (register const char *str, register size_t len)
{
  static const unsigned short asso_values[] =
    {
      566, 566, 566, 566, 566, 566, 566, 566, 566, 566,
      566, 566, 566, 566, 566, 566, 566, 566, 566, 566,
      566, 566, 566, 566, 566, 566, 566, 566, 566, 566,
      566, 566, 566, 566, 566, 566, 566, 566, 566, 566,
      566, 566, 566, 566, 566, 566, 566, 566, 566, 566,
      566, 566, 566, 566, 566, 566, 566, 566, 566, 566,
      566, 566, 566, 566, 566, 566, 566, 566, 566, 566,
      566, 566, 566, 566, 566, 566, 566, 566, 566, 566,
      566, 566, 566, 566, 566, 566, 566, 566, 566, 566,
      566, 566, 566, 566, 566,  88, 566,  36,  45,  84,
        4,   4, 127, 202, 118,   4,  76, 102,   6, 164,
       63,   4,  92,  14,   9,  25,   7,  57,  34, 122,
      159,  60,  13, 566, 566, 566, 566, 566
    };
  register unsigned int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[17]];
#if (defined __cplusplus && (__cplusplus >= 201703L || (__cplusplus >= 201103L && defined __clang__ && __clang_major__ + (__clang_minor__ >= 9) > 3))) || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 202000L && ((defined __GNUC__ && __GNUC__ >= 10) || (defined __clang__ && __clang_major__ >= 9)))
      [[fallthrough]];
#elif (defined __GNUC__ && __GNUC__ >= 7) || (defined __clang__ && __clang_major__ >= 10)
      __attribute__ ((__fallthrough__));
#endif
      /*FALLTHROUGH*/
      case 17:
      case 16:
      case 15:
      case 14:
        hval += asso_values[(unsigned char)str[13]];
#if (defined __cplusplus && (__cplusplus >= 201703L || (__cplusplus >= 201103L && defined __clang__ && __clang_major__ + (__clang_minor__ >= 9) > 3))) || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 202000L && ((defined __GNUC__ && __GNUC__ >= 10) || (defined __clang__ && __clang_major__ >= 9)))
      [[fallthrough]];
#elif (defined __GNUC__ && __GNUC__ >= 7) || (defined __clang__ && __clang_major__ >= 10)
      __attribute__ ((__fallthrough__));
#endif
      /*FALLTHROUGH*/
      case 13:
      case 12:
      case 11:
      case 10:
      case 9:
      case 8:
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
      case 4:
      case 3:
      case 2:
        hval += asso_values[(unsigned char)str[1]];
#if (defined __cplusplus && (__cplusplus >= 201703L || (__cplusplus >= 201103L && defined __clang__ && __clang_major__ + (__clang_minor__ >= 9) > 3))) || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 202000L && ((defined __GNUC__ && __GNUC__ >= 10) || (defined __clang__ && __clang_major__ >= 9)))
      [[fallthrough]];
#elif (defined __GNUC__ && __GNUC__ >= 7) || (defined __clang__ && __clang_major__ >= 10)
      __attribute__ ((__fallthrough__));
#endif
      /*FALLTHROUGH*/
      case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
  return hval + asso_values[(unsigned char)str[len - 1]];
}

struct properties_stringpool_t
  {
    char properties_stringpool_str14[sizeof("di")];
    char properties_stringpool_str15[sizeof("odi")];
    char properties_stringpool_str16[sizeof("ideo")];
    char properties_stringpool_str17[sizeof("loe")];
    char properties_stringpool_str19[sizeof("idst")];
    char properties_stringpool_str22[sizeof("idstart")];
    char properties_stringpool_str24[sizeof("lower")];
    char properties_stringpool_str25[sizeof("olower")];
    char properties_stringpool_str27[sizeof("id_continue")];
    char properties_stringpool_str29[sizeof("deprecated")];
    char properties_stringpool_str30[sizeof("id_start")];
    char properties_stringpool_str31[sizeof("decimaldigit")];
    char properties_stringpool_str35[sizeof("sd")];
    char properties_stringpool_str36[sizeof("ids")];
    char properties_stringpool_str37[sizeof("oids")];
    char properties_stringpool_str38[sizeof("idcms")];
    char properties_stringpool_str40[sizeof("other_id_continue")];
    char properties_stringpool_str43[sizeof("other_id_start")];
    char properties_stringpool_str46[sizeof("idcompatmathstart")];
    char properties_stringpool_str47[sizeof("dia")];
    char properties_stringpool_str48[sizeof("lowercase")];
    char properties_stringpool_str49[sizeof("titlecase")];
    char properties_stringpool_str50[sizeof("softdotted")];
    char properties_stringpool_str51[sizeof("soft_dotted")];
    char properties_stringpool_str53[sizeof("iso_control")];
    char properties_stringpool_str54[sizeof("isocontrol")];
    char properties_stringpool_str55[sizeof("otheridstart")];
    char properties_stringpool_str56[sizeof("other_grapheme_extend")];
    char properties_stringpool_str57[sizeof("idsb")];
    char properties_stringpool_str58[sizeof("radical")];
    char properties_stringpool_str59[sizeof("other_lowercase")];
    char properties_stringpool_str60[sizeof("sentence_terminal")];
    char properties_stringpool_str62[sizeof("ids_unary_operator")];
    char properties_stringpool_str65[sizeof("leftofpair")];
    char properties_stringpool_str68[sizeof("lineseparator")];
    char properties_stringpool_str69[sizeof("idsu")];
    char properties_stringpool_str70[sizeof("uideo")];
    char properties_stringpool_str73[sizeof("bidicontrol")];
    char properties_stringpool_str76[sizeof("oupper")];
    char properties_stringpool_str78[sizeof("bidiwhitespace")];
    char properties_stringpool_str79[sizeof("idsbinaryoperator")];
    char properties_stringpool_str80[sizeof("ids_binary_operator")];
    char properties_stringpool_str81[sizeof("bidieuropeandigit")];
    char properties_stringpool_str82[sizeof("oalpha")];
    char properties_stringpool_str83[sizeof("alpha")];
    char properties_stringpool_str84[sizeof("bidiotherneutral")];
    char properties_stringpool_str85[sizeof("idcontinue")];
    char properties_stringpool_str86[sizeof("vs")];
    char properties_stringpool_str88[sizeof("bidiembeddingoroverride")];
    char properties_stringpool_str89[sizeof("idstrinaryoperator")];
    char properties_stringpool_str91[sizeof("ascii_hex_digit")];
    char properties_stringpool_str93[sizeof("defaultignorablecodepoint")];
    char properties_stringpool_str94[sizeof("ci")];
    char properties_stringpool_str95[sizeof("idc")];
    char properties_stringpool_str96[sizeof("oidc")];
    char properties_stringpool_str97[sizeof("idcmc")];
    char properties_stringpool_str98[sizeof("notacharacter")];
    char properties_stringpool_str100[sizeof("idsunaryoperator")];
    char properties_stringpool_str101[sizeof("bidi_eur_num_terminator")];
    char properties_stringpool_str103[sizeof("dep")];
    char properties_stringpool_str104[sizeof("joincontrol")];
    char properties_stringpool_str105[sizeof("diacritic")];
    char properties_stringpool_str106[sizeof("idcompatmathcontinue")];
    char properties_stringpool_str108[sizeof("composite")];
    char properties_stringpool_str111[sizeof("terminal_punctuation")];
    char properties_stringpool_str113[sizeof("bidi_arabic_digit")];
    char properties_stringpool_str114[sizeof("variation_selector")];
    char properties_stringpool_str116[sizeof("decimal_digit")];
    char properties_stringpool_str118[sizeof("sentenceterminal")];
    char properties_stringpool_str119[sizeof("left_of_pair")];
    char properties_stringpool_str120[sizeof("bidiarabicdigit")];
    char properties_stringpool_str123[sizeof("bidi_eur_num_separator")];
    char properties_stringpool_str124[sizeof("other_alphabetic")];
    char properties_stringpool_str125[sizeof("otheruppercase")];
    char properties_stringpool_str126[sizeof("space")];
    char properties_stringpool_str129[sizeof("cased")];
    char properties_stringpool_str130[sizeof("bidi_control")];
    char properties_stringpool_str134[sizeof("line_separator")];
    char properties_stringpool_str137[sizeof("othergraphemeextend")];
    char properties_stringpool_str138[sizeof("bidic")];
    char properties_stringpool_str139[sizeof("bidi_c")];
    char properties_stringpool_str141[sizeof("caseignorable")];
    char properties_stringpool_str142[sizeof("hex_digit")];
    char properties_stringpool_str143[sizeof("alphabetic")];
    char properties_stringpool_str144[sizeof("hexdigit")];
    char properties_stringpool_str145[sizeof("othermath")];
    char properties_stringpool_str147[sizeof("other_uppercase")];
    char properties_stringpool_str148[sizeof("other_default_ignorable_code_point")];
    char properties_stringpool_str149[sizeof("zero_width")];
    char properties_stringpool_str151[sizeof("zerowidth")];
    char properties_stringpool_str154[sizeof("formatcontrol")];
    char properties_stringpool_str155[sizeof("otherlowercase")];
    char properties_stringpool_str156[sizeof("bidi_whitespace")];
    char properties_stringpool_str157[sizeof("wspace")];
    char properties_stringpool_str158[sizeof("patws")];
    char properties_stringpool_str159[sizeof("pat_ws")];
    char properties_stringpool_str160[sizeof("terminalpunctuation")];
    char properties_stringpool_str161[sizeof("join_control")];
    char properties_stringpool_str162[sizeof("dash")];
    char properties_stringpool_str163[sizeof("upper")];
    char properties_stringpool_str169[sizeof("joinc")];
    char properties_stringpool_str170[sizeof("join_c")];
    char properties_stringpool_str171[sizeof("otheridcontinue")];
    char properties_stringpool_str172[sizeof("privateuse")];
    char properties_stringpool_str173[sizeof("ext")];
    char properties_stringpool_str175[sizeof("other_math")];
    char properties_stringpool_str176[sizeof("bidi_european_digit")];
    char properties_stringpool_str177[sizeof("bidiboundaryneutral")];
    char properties_stringpool_str178[sizeof("bidiblockseparator")];
    char properties_stringpool_str179[sizeof("term")];
    char properties_stringpool_str180[sizeof("bidieurnumseparator")];
    char properties_stringpool_str181[sizeof("bidi_block_separator")];
    char properties_stringpool_str182[sizeof("xidcontinue")];
    char properties_stringpool_str183[sizeof("bidipdf")];
    char properties_stringpool_str184[sizeof("variationselector")];
    char properties_stringpool_str185[sizeof("xidstart")];
    char properties_stringpool_str186[sizeof("xid_continue")];
    char properties_stringpool_str187[sizeof("uppercase")];
    char properties_stringpool_str188[sizeof("xid_start")];
    char properties_stringpool_str189[sizeof("extender")];
    char properties_stringpool_str190[sizeof("quotationmark")];
    char properties_stringpool_str192[sizeof("xids")];
    char properties_stringpool_str195[sizeof("ideographic")];
    char properties_stringpool_str196[sizeof("bidilefttoright")];
    char properties_stringpool_str197[sizeof("patsyn")];
    char properties_stringpool_str198[sizeof("pat_syn")];
    char properties_stringpool_str199[sizeof("ids_trinary_operator")];
    char properties_stringpool_str204[sizeof("private_use")];
    char properties_stringpool_str205[sizeof("case_ignorable")];
    char properties_stringpool_str206[sizeof("otheralphabetic")];
    char properties_stringpool_str209[sizeof("bidi_arabic_right_to_left")];
    char properties_stringpool_str210[sizeof("bidihebrewrighttoleft")];
    char properties_stringpool_str211[sizeof("numeric")];
    char properties_stringpool_str213[sizeof("not_a_character")];
    char properties_stringpool_str214[sizeof("non_break")];
    char properties_stringpool_str215[sizeof("cwl")];
    char properties_stringpool_str216[sizeof("cwt")];
    char properties_stringpool_str217[sizeof("bidi_left_to_right")];
    char properties_stringpool_str218[sizeof("bidi_hebrew_right_to_left")];
    char properties_stringpool_str219[sizeof("ogrext")];
    char properties_stringpool_str220[sizeof("ogr_ext")];
    char properties_stringpool_str221[sizeof("grbase")];
    char properties_stringpool_str222[sizeof("gr_base")];
    char properties_stringpool_str223[sizeof("grext")];
    char properties_stringpool_str224[sizeof("gr_ext")];
    char properties_stringpool_str225[sizeof("id_compat_math_start")];
    char properties_stringpool_str226[sizeof("currency_symbol")];
    char properties_stringpool_str227[sizeof("currencysymbol")];
    char properties_stringpool_str228[sizeof("bidi_boundary_neutral")];
    char properties_stringpool_str230[sizeof("punctuation")];
    char properties_stringpool_str231[sizeof("graphemebase")];
    char properties_stringpool_str232[sizeof("grapheme_base")];
    char properties_stringpool_str237[sizeof("graphemeextend")];
    char properties_stringpool_str240[sizeof("asciihexdigit")];
    char properties_stringpool_str241[sizeof("format_control")];
    char properties_stringpool_str242[sizeof("ignorable_control")];
    char properties_stringpool_str243[sizeof("ignorablecontrol")];
    char properties_stringpool_str246[sizeof("bidiarabicrighttoleft")];
    char properties_stringpool_str247[sizeof("hyphen")];
    char properties_stringpool_str248[sizeof("unassigned_code_value")];
    char properties_stringpool_str251[sizeof("xidc")];
    char properties_stringpool_str252[sizeof("id_compat_math_continue")];
    char properties_stringpool_str254[sizeof("bidi_other_neutral")];
    char properties_stringpool_str255[sizeof("default_ignorable_code_point")];
    char properties_stringpool_str264[sizeof("logicalorderexception")];
    char properties_stringpool_str265[sizeof("paragraphseparator")];
    char properties_stringpool_str266[sizeof("cwu")];
    char properties_stringpool_str267[sizeof("unassignedcodevalue")];
    char properties_stringpool_str272[sizeof("pairedpunctuation")];
    char properties_stringpool_str276[sizeof("logical_order_exception")];
    char properties_stringpool_str279[sizeof("nonbreak")];
    char properties_stringpool_str281[sizeof("bidicommonseparator")];
    char properties_stringpool_str283[sizeof("bidi_common_separator")];
    char properties_stringpool_str284[sizeof("hex")];
    char properties_stringpool_str285[sizeof("qmark")];
    char properties_stringpool_str288[sizeof("paragraph_separator")];
    char properties_stringpool_str290[sizeof("whitespace")];
    char properties_stringpool_str291[sizeof("omath")];
    char properties_stringpool_str293[sizeof("quotation_mark")];
    char properties_stringpool_str294[sizeof("unifiedideograph")];
    char properties_stringpool_str297[sizeof("grapheme_extend")];
    char properties_stringpool_str305[sizeof("prependedconcatenationmark")];
    char properties_stringpool_str311[sizeof("bidi_pdf")];
    char properties_stringpool_str312[sizeof("bidieurnumterminator")];
    char properties_stringpool_str316[sizeof("bidi_segment_separator")];
    char properties_stringpool_str317[sizeof("ahex")];
    char properties_stringpool_str319[sizeof("grlink")];
    char properties_stringpool_str320[sizeof("gr_link")];
    char properties_stringpool_str322[sizeof("math")];
    char properties_stringpool_str325[sizeof("patternsyntax")];
    char properties_stringpool_str328[sizeof("changes_when_titlecased")];
    char properties_stringpool_str329[sizeof("graphemelink")];
    char properties_stringpool_str330[sizeof("grapheme_link")];
    char properties_stringpool_str332[sizeof("changes_when_lowercased")];
    char properties_stringpool_str337[sizeof("cwcf")];
    char properties_stringpool_str341[sizeof("bidisegmentseparator")];
    char properties_stringpool_str347[sizeof("white_space")];
    char properties_stringpool_str352[sizeof("unified_ideograph")];
    char properties_stringpool_str362[sizeof("combining")];
    char properties_stringpool_str363[sizeof("patternwhitespace")];
    char properties_stringpool_str374[sizeof("cwcm")];
    char properties_stringpool_str380[sizeof("changeswhencasefolded")];
    char properties_stringpool_str382[sizeof("prepended_concatenation_mark")];
    char properties_stringpool_str383[sizeof("changes_when_uppercased")];
    char properties_stringpool_str392[sizeof("changeswhentitlecased")];
    char properties_stringpool_str400[sizeof("paired_punctuation")];
    char properties_stringpool_str403[sizeof("bidi_non_spacing_mark")];
    char properties_stringpool_str411[sizeof("pattern_white_space")];
    char properties_stringpool_str413[sizeof("otherdefaultignorablecodepoint")];
    char properties_stringpool_str414[sizeof("bidi_embedding_or_override")];
    char properties_stringpool_str466[sizeof("changeswhencasemapped")];
    char properties_stringpool_str477[sizeof("changeswhenuppercased")];
    char properties_stringpool_str498[sizeof("bidinonspacingmark")];
    char properties_stringpool_str507[sizeof("changeswhenlowercased")];
    char properties_stringpool_str508[sizeof("modifier_combining_mark")];
    char properties_stringpool_str527[sizeof("modifiercombiningmark")];
    char properties_stringpool_str528[sizeof("changes_when_casefolded")];
    char properties_stringpool_str548[sizeof("pattern_syntax")];
    char properties_stringpool_str565[sizeof("changes_when_casemapped")];
  };
static const struct properties_stringpool_t properties_stringpool_contents =
  {
    "di",
    "odi",
    "ideo",
    "loe",
    "idst",
    "idstart",
    "lower",
    "olower",
    "id_continue",
    "deprecated",
    "id_start",
    "decimaldigit",
    "sd",
    "ids",
    "oids",
    "idcms",
    "other_id_continue",
    "other_id_start",
    "idcompatmathstart",
    "dia",
    "lowercase",
    "titlecase",
    "softdotted",
    "soft_dotted",
    "iso_control",
    "isocontrol",
    "otheridstart",
    "other_grapheme_extend",
    "idsb",
    "radical",
    "other_lowercase",
    "sentence_terminal",
    "ids_unary_operator",
    "leftofpair",
    "lineseparator",
    "idsu",
    "uideo",
    "bidicontrol",
    "oupper",
    "bidiwhitespace",
    "idsbinaryoperator",
    "ids_binary_operator",
    "bidieuropeandigit",
    "oalpha",
    "alpha",
    "bidiotherneutral",
    "idcontinue",
    "vs",
    "bidiembeddingoroverride",
    "idstrinaryoperator",
    "ascii_hex_digit",
    "defaultignorablecodepoint",
    "ci",
    "idc",
    "oidc",
    "idcmc",
    "notacharacter",
    "idsunaryoperator",
    "bidi_eur_num_terminator",
    "dep",
    "joincontrol",
    "diacritic",
    "idcompatmathcontinue",
    "composite",
    "terminal_punctuation",
    "bidi_arabic_digit",
    "variation_selector",
    "decimal_digit",
    "sentenceterminal",
    "left_of_pair",
    "bidiarabicdigit",
    "bidi_eur_num_separator",
    "other_alphabetic",
    "otheruppercase",
    "space",
    "cased",
    "bidi_control",
    "line_separator",
    "othergraphemeextend",
    "bidic",
    "bidi_c",
    "caseignorable",
    "hex_digit",
    "alphabetic",
    "hexdigit",
    "othermath",
    "other_uppercase",
    "other_default_ignorable_code_point",
    "zero_width",
    "zerowidth",
    "formatcontrol",
    "otherlowercase",
    "bidi_whitespace",
    "wspace",
    "patws",
    "pat_ws",
    "terminalpunctuation",
    "join_control",
    "dash",
    "upper",
    "joinc",
    "join_c",
    "otheridcontinue",
    "privateuse",
    "ext",
    "other_math",
    "bidi_european_digit",
    "bidiboundaryneutral",
    "bidiblockseparator",
    "term",
    "bidieurnumseparator",
    "bidi_block_separator",
    "xidcontinue",
    "bidipdf",
    "variationselector",
    "xidstart",
    "xid_continue",
    "uppercase",
    "xid_start",
    "extender",
    "quotationmark",
    "xids",
    "ideographic",
    "bidilefttoright",
    "patsyn",
    "pat_syn",
    "ids_trinary_operator",
    "private_use",
    "case_ignorable",
    "otheralphabetic",
    "bidi_arabic_right_to_left",
    "bidihebrewrighttoleft",
    "numeric",
    "not_a_character",
    "non_break",
    "cwl",
    "cwt",
    "bidi_left_to_right",
    "bidi_hebrew_right_to_left",
    "ogrext",
    "ogr_ext",
    "grbase",
    "gr_base",
    "grext",
    "gr_ext",
    "id_compat_math_start",
    "currency_symbol",
    "currencysymbol",
    "bidi_boundary_neutral",
    "punctuation",
    "graphemebase",
    "grapheme_base",
    "graphemeextend",
    "asciihexdigit",
    "format_control",
    "ignorable_control",
    "ignorablecontrol",
    "bidiarabicrighttoleft",
    "hyphen",
    "unassigned_code_value",
    "xidc",
    "id_compat_math_continue",
    "bidi_other_neutral",
    "default_ignorable_code_point",
    "logicalorderexception",
    "paragraphseparator",
    "cwu",
    "unassignedcodevalue",
    "pairedpunctuation",
    "logical_order_exception",
    "nonbreak",
    "bidicommonseparator",
    "bidi_common_separator",
    "hex",
    "qmark",
    "paragraph_separator",
    "whitespace",
    "omath",
    "quotation_mark",
    "unifiedideograph",
    "grapheme_extend",
    "prependedconcatenationmark",
    "bidi_pdf",
    "bidieurnumterminator",
    "bidi_segment_separator",
    "ahex",
    "grlink",
    "gr_link",
    "math",
    "patternsyntax",
    "changes_when_titlecased",
    "graphemelink",
    "grapheme_link",
    "changes_when_lowercased",
    "cwcf",
    "bidisegmentseparator",
    "white_space",
    "unified_ideograph",
    "combining",
    "patternwhitespace",
    "cwcm",
    "changeswhencasefolded",
    "prepended_concatenation_mark",
    "changes_when_uppercased",
    "changeswhentitlecased",
    "paired_punctuation",
    "bidi_non_spacing_mark",
    "pattern_white_space",
    "otherdefaultignorablecodepoint",
    "bidi_embedding_or_override",
    "changeswhencasemapped",
    "changeswhenuppercased",
    "bidinonspacingmark",
    "changeswhenlowercased",
    "modifier_combining_mark",
    "modifiercombiningmark",
    "changes_when_casefolded",
    "pattern_syntax",
    "changes_when_casemapped"
  };
#define properties_stringpool ((const char *) &properties_stringpool_contents)

#if (defined __GNUC__ && __GNUC__ + (__GNUC_MINOR__ >= 6) > 4) || (defined __clang__ && __clang_major__ >= 3)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
static const struct named_property properties[] =
  {
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1},
#line 49 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str14, UC_PROPERTY_INDEX_DEFAULT_IGNORABLE_CODE_POINT},
#line 52 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str15, UC_PROPERTY_INDEX_OTHER_DEFAULT_IGNORABLE_CODE_POINT},
#line 195 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str16, UC_PROPERTY_INDEX_IDEOGRAPHIC},
#line 57 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str17, UC_PROPERTY_INDEX_LOGICAL_ORDER_EXCEPTION},
    {-1},
#line 208 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str19, UC_PROPERTY_INDEX_IDS_TRINARY_OPERATOR},
    {-1}, {-1},
#line 99 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str22, UC_PROPERTY_INDEX_ID_START},
    {-1},
#line 71 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str24, UC_PROPERTY_INDEX_LOWERCASE},
#line 74 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str25, UC_PROPERTY_INDEX_OTHER_LOWERCASE},
    {-1},
#line 104 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str27, UC_PROPERTY_INDEX_ID_CONTINUE},
    {-1},
#line 53 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str29, UC_PROPERTY_INDEX_DEPRECATED},
#line 98 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str30, UC_PROPERTY_INDEX_ID_START},
#line 248 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str31, UC_PROPERTY_INDEX_DECIMAL_DIGIT},
    {-1}, {-1}, {-1},
#line 97 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str35, UC_PROPERTY_INDEX_SOFT_DOTTED},
#line 100 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str36, UC_PROPERTY_INDEX_ID_START},
#line 103 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str37, UC_PROPERTY_INDEX_OTHER_ID_START},
#line 118 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str38, UC_PROPERTY_INDEX_ID_COMPAT_MATH_START},
    {-1},
#line 107 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str40, UC_PROPERTY_INDEX_OTHER_ID_CONTINUE},
    {-1}, {-1},
#line 101 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str43, UC_PROPERTY_INDEX_OTHER_ID_START},
    {-1}, {-1},
#line 117 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str46, UC_PROPERTY_INDEX_ID_COMPAT_MATH_START},
#line 251 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str47, UC_PROPERTY_INDEX_DIACRITIC},
#line 70 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str48, UC_PROPERTY_INDEX_LOWERCASE},
#line 75 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str49, UC_PROPERTY_INDEX_TITLECASE},
#line 96 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str50, UC_PROPERTY_INDEX_SOFT_DOTTED},
#line 95 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str51, UC_PROPERTY_INDEX_SOFT_DOTTED},
    {-1},
#line 214 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str53, UC_PROPERTY_INDEX_ISO_CONTROL},
#line 215 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str54, UC_PROPERTY_INDEX_ISO_CONTROL},
#line 102 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str55, UC_PROPERTY_INDEX_OTHER_ID_START},
#line 142 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str56, UC_PROPERTY_INDEX_OTHER_GRAPHEME_EXTEND},
#line 205 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str57, UC_PROPERTY_INDEX_IDS_BINARY_OPERATOR},
#line 199 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str58, UC_PROPERTY_INDEX_RADICAL},
#line 72 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str59, UC_PROPERTY_INDEX_OTHER_LOWERCASE},
#line 230 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str60, UC_PROPERTY_INDEX_SENTENCE_TERMINAL},
    {-1},
#line 200 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str62, UC_PROPERTY_INDEX_IDS_UNARY_OPERATOR},
    {-1}, {-1},
#line 244 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str65, UC_PROPERTY_INDEX_LEFT_OF_PAIR},
    {-1}, {-1},
#line 224 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str68, UC_PROPERTY_INDEX_LINE_SEPARATOR},
#line 202 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str69, UC_PROPERTY_INDEX_IDS_UNARY_OPERATOR},
#line 198 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str70, UC_PROPERTY_INDEX_UNIFIED_IDEOGRAPH},
    {-1}, {-1},
#line 153 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str73, UC_PROPERTY_INDEX_BIDI_CONTROL},
    {-1}, {-1},
#line 69 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str76, UC_PROPERTY_INDEX_OTHER_UPPERCASE},
    {-1},
#line 177 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str78, UC_PROPERTY_INDEX_BIDI_WHITESPACE},
#line 204 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str79, UC_PROPERTY_INDEX_IDS_BINARY_OPERATOR},
#line 203 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str80, UC_PROPERTY_INDEX_IDS_BINARY_OPERATOR},
#line 163 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str81, UC_PROPERTY_INDEX_BIDI_EUROPEAN_DIGIT},
#line 44 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str82, UC_PROPERTY_INDEX_OTHER_ALPHABETIC},
#line 41 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str83, UC_PROPERTY_INDEX_ALPHABETIC},
#line 187 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str84, UC_PROPERTY_INDEX_BIDI_OTHER_NEUTRAL},
#line 105 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str85, UC_PROPERTY_INDEX_ID_CONTINUE},
#line 60 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str86, UC_PROPERTY_INDEX_VARIATION_SELECTOR},
    {-1},
#line 185 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str88, UC_PROPERTY_INDEX_BIDI_EMBEDDING_OR_OVERRIDE},
#line 207 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str89, UC_PROPERTY_INDEX_IDS_TRINARY_OPERATOR},
    {-1},
#line 191 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str91, UC_PROPERTY_INDEX_ASCII_HEX_DIGIT},
    {-1},
#line 48 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str93, UC_PROPERTY_INDEX_DEFAULT_IGNORABLE_CODE_POINT},
#line 79 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str94, UC_PROPERTY_INDEX_CASE_IGNORABLE},
#line 106 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str95, UC_PROPERTY_INDEX_ID_CONTINUE},
#line 109 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str96, UC_PROPERTY_INDEX_OTHER_ID_CONTINUE},
#line 121 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str97, UC_PROPERTY_INDEX_ID_COMPAT_MATH_CONTINUE},
#line 46 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str98, UC_PROPERTY_INDEX_NOT_A_CHARACTER},
    {-1},
#line 201 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str100, UC_PROPERTY_INDEX_IDS_UNARY_OPERATOR},
#line 166 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str101, UC_PROPERTY_INDEX_BIDI_EUR_NUM_TERMINATOR},
    {-1},
#line 54 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str103, UC_PROPERTY_INDEX_DEPRECATED},
#line 131 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str104, UC_PROPERTY_INDEX_JOIN_CONTROL},
#line 250 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str105, UC_PROPERTY_INDEX_DIACRITIC},
#line 120 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str106, UC_PROPERTY_INDEX_ID_COMPAT_MATH_CONTINUE},
    {-1},
#line 246 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str108, UC_PROPERTY_INDEX_COMPOSITE},
    {-1}, {-1},
#line 232 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str111, UC_PROPERTY_INDEX_TERMINAL_PUNCTUATION},
    {-1},
#line 168 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str113, UC_PROPERTY_INDEX_BIDI_ARABIC_DIGIT},
#line 58 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str114, UC_PROPERTY_INDEX_VARIATION_SELECTOR},
    {-1},
#line 247 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str116, UC_PROPERTY_INDEX_DECIMAL_DIGIT},
    {-1},
#line 231 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str118, UC_PROPERTY_INDEX_SENTENCE_TERMINAL},
#line 243 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str119, UC_PROPERTY_INDEX_LEFT_OF_PAIR},
#line 169 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str120, UC_PROPERTY_INDEX_BIDI_ARABIC_DIGIT},
    {-1}, {-1},
#line 164 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str123, UC_PROPERTY_INDEX_BIDI_EUR_NUM_SEPARATOR},
#line 42 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str124, UC_PROPERTY_INDEX_OTHER_ALPHABETIC},
#line 68 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str125, UC_PROPERTY_INDEX_OTHER_UPPERCASE},
#line 211 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str126, UC_PROPERTY_INDEX_SPACE},
    {-1}, {-1},
#line 76 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str129, UC_PROPERTY_INDEX_CASED},
#line 152 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str130, UC_PROPERTY_INDEX_BIDI_CONTROL},
    {-1}, {-1}, {-1},
#line 223 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str134, UC_PROPERTY_INDEX_LINE_SEPARATOR},
    {-1}, {-1},
#line 143 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str137, UC_PROPERTY_INDEX_OTHER_GRAPHEME_EXTEND},
#line 155 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str138, UC_PROPERTY_INDEX_BIDI_CONTROL},
#line 154 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str139, UC_PROPERTY_INDEX_BIDI_CONTROL},
    {-1},
#line 78 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str141, UC_PROPERTY_INDEX_CASE_IGNORABLE},
#line 188 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str142, UC_PROPERTY_INDEX_HEX_DIGIT},
#line 40 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str143, UC_PROPERTY_INDEX_ALPHABETIC},
#line 189 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str144, UC_PROPERTY_INDEX_HEX_DIGIT},
#line 239 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str145, UC_PROPERTY_INDEX_OTHER_MATH},
    {-1},
#line 67 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str147, UC_PROPERTY_INDEX_OTHER_UPPERCASE},
#line 50 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str148, UC_PROPERTY_INDEX_OTHER_DEFAULT_IGNORABLE_CODE_POINT},
#line 209 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str149, UC_PROPERTY_INDEX_ZERO_WIDTH},
    {-1},
#line 210 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str151, UC_PROPERTY_INDEX_ZERO_WIDTH},
    {-1}, {-1},
#line 217 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str154, UC_PROPERTY_INDEX_FORMAT_CONTROL},
#line 73 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str155, UC_PROPERTY_INDEX_OTHER_LOWERCASE},
#line 176 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str156, UC_PROPERTY_INDEX_BIDI_WHITESPACE},
#line 39 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str157, UC_PROPERTY_INDEX_WHITE_SPACE},
#line 125 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str158, UC_PROPERTY_INDEX_PATTERN_WHITE_SPACE},
#line 124 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str159, UC_PROPERTY_INDEX_PATTERN_WHITE_SPACE},
#line 233 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str160, UC_PROPERTY_INDEX_TERMINAL_PUNCTUATION},
#line 130 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str161, UC_PROPERTY_INDEX_JOIN_CONTROL},
#line 220 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str162, UC_PROPERTY_INDEX_DASH},
#line 66 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str163, UC_PROPERTY_INDEX_UPPERCASE},
    {-1}, {-1}, {-1}, {-1}, {-1},
#line 133 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str169, UC_PROPERTY_INDEX_JOIN_CONTROL},
#line 132 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str170, UC_PROPERTY_INDEX_JOIN_CONTROL},
#line 108 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str171, UC_PROPERTY_INDEX_OTHER_ID_CONTINUE},
#line 62 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str172, UC_PROPERTY_INDEX_PRIVATE_USE},
#line 253 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str173, UC_PROPERTY_INDEX_EXTENDER},
    {-1},
#line 238 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str175, UC_PROPERTY_INDEX_OTHER_MATH},
#line 162 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str176, UC_PROPERTY_INDEX_BIDI_EUROPEAN_DIGIT},
#line 181 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str177, UC_PROPERTY_INDEX_BIDI_BOUNDARY_NEUTRAL},
#line 173 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str178, UC_PROPERTY_INDEX_BIDI_BLOCK_SEPARATOR},
#line 234 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str179, UC_PROPERTY_INDEX_TERMINAL_PUNCTUATION},
#line 165 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str180, UC_PROPERTY_INDEX_BIDI_EUR_NUM_SEPARATOR},
#line 172 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str181, UC_PROPERTY_INDEX_BIDI_BLOCK_SEPARATOR},
#line 114 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str182, UC_PROPERTY_INDEX_XID_CONTINUE},
#line 183 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str183, UC_PROPERTY_INDEX_BIDI_PDF},
#line 59 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str184, UC_PROPERTY_INDEX_VARIATION_SELECTOR},
#line 111 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str185, UC_PROPERTY_INDEX_XID_START},
#line 113 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str186, UC_PROPERTY_INDEX_XID_CONTINUE},
#line 65 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str187, UC_PROPERTY_INDEX_UPPERCASE},
#line 110 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str188, UC_PROPERTY_INDEX_XID_START},
#line 252 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str189, UC_PROPERTY_INDEX_EXTENDER},
#line 228 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str190, UC_PROPERTY_INDEX_QUOTATION_MARK},
    {-1},
#line 112 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str192, UC_PROPERTY_INDEX_XID_START},
    {-1}, {-1},
#line 194 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str195, UC_PROPERTY_INDEX_IDEOGRAPHIC},
#line 157 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str196, UC_PROPERTY_INDEX_BIDI_LEFT_TO_RIGHT},
#line 129 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str197, UC_PROPERTY_INDEX_PATTERN_SYNTAX},
#line 128 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str198, UC_PROPERTY_INDEX_PATTERN_SYNTAX},
#line 206 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str199, UC_PROPERTY_INDEX_IDS_TRINARY_OPERATOR},
    {-1}, {-1}, {-1}, {-1},
#line 61 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str204, UC_PROPERTY_INDEX_PRIVATE_USE},
#line 77 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str205, UC_PROPERTY_INDEX_CASE_IGNORABLE},
#line 43 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str206, UC_PROPERTY_INDEX_OTHER_ALPHABETIC},
    {-1}, {-1},
#line 160 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str209, UC_PROPERTY_INDEX_BIDI_ARABIC_RIGHT_TO_LEFT},
#line 159 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str210, UC_PROPERTY_INDEX_BIDI_HEBREW_RIGHT_TO_LEFT},
#line 249 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str211, UC_PROPERTY_INDEX_NUMERIC},
    {-1},
#line 45 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str213, UC_PROPERTY_INDEX_NOT_A_CHARACTER},
#line 212 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str214, UC_PROPERTY_INDEX_NON_BREAK},
#line 82 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str215, UC_PROPERTY_INDEX_CHANGES_WHEN_LOWERCASED},
#line 88 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str216, UC_PROPERTY_INDEX_CHANGES_WHEN_TITLECASED},
#line 156 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str217, UC_PROPERTY_INDEX_BIDI_LEFT_TO_RIGHT},
#line 158 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str218, UC_PROPERTY_INDEX_BIDI_HEBREW_RIGHT_TO_LEFT},
#line 145 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str219, UC_PROPERTY_INDEX_OTHER_GRAPHEME_EXTEND},
#line 144 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str220, UC_PROPERTY_INDEX_OTHER_GRAPHEME_EXTEND},
#line 137 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str221, UC_PROPERTY_INDEX_GRAPHEME_BASE},
#line 136 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str222, UC_PROPERTY_INDEX_GRAPHEME_BASE},
#line 141 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str223, UC_PROPERTY_INDEX_GRAPHEME_EXTEND},
#line 140 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str224, UC_PROPERTY_INDEX_GRAPHEME_EXTEND},
#line 116 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str225, UC_PROPERTY_INDEX_ID_COMPAT_MATH_START},
#line 235 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str226, UC_PROPERTY_INDEX_CURRENCY_SYMBOL},
#line 236 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str227, UC_PROPERTY_INDEX_CURRENCY_SYMBOL},
#line 180 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str228, UC_PROPERTY_INDEX_BIDI_BOUNDARY_NEUTRAL},
    {-1},
#line 222 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str230, UC_PROPERTY_INDEX_PUNCTUATION},
#line 135 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str231, UC_PROPERTY_INDEX_GRAPHEME_BASE},
#line 134 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str232, UC_PROPERTY_INDEX_GRAPHEME_BASE},
    {-1}, {-1}, {-1}, {-1},
#line 139 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str237, UC_PROPERTY_INDEX_GRAPHEME_EXTEND},
    {-1}, {-1},
#line 192 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str240, UC_PROPERTY_INDEX_ASCII_HEX_DIGIT},
#line 216 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str241, UC_PROPERTY_INDEX_FORMAT_CONTROL},
#line 254 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str242, UC_PROPERTY_INDEX_IGNORABLE_CONTROL},
#line 255 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str243, UC_PROPERTY_INDEX_IGNORABLE_CONTROL},
    {-1}, {-1},
#line 161 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str246, UC_PROPERTY_INDEX_BIDI_ARABIC_RIGHT_TO_LEFT},
#line 221 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str247, UC_PROPERTY_INDEX_HYPHEN},
#line 63 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str248, UC_PROPERTY_INDEX_UNASSIGNED_CODE_VALUE},
    {-1}, {-1},
#line 115 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str251, UC_PROPERTY_INDEX_XID_CONTINUE},
#line 119 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str252, UC_PROPERTY_INDEX_ID_COMPAT_MATH_CONTINUE},
    {-1},
#line 186 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str254, UC_PROPERTY_INDEX_BIDI_OTHER_NEUTRAL},
#line 47 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str255, UC_PROPERTY_INDEX_DEFAULT_IGNORABLE_CODE_POINT},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 56 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str264, UC_PROPERTY_INDEX_LOGICAL_ORDER_EXCEPTION},
#line 226 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str265, UC_PROPERTY_INDEX_PARAGRAPH_SEPARATOR},
#line 85 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str266, UC_PROPERTY_INDEX_CHANGES_WHEN_UPPERCASED},
#line 64 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str267, UC_PROPERTY_INDEX_UNASSIGNED_CODE_VALUE},
    {-1}, {-1}, {-1}, {-1},
#line 242 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str272, UC_PROPERTY_INDEX_PAIRED_PUNCTUATION},
    {-1}, {-1}, {-1},
#line 55 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str276, UC_PROPERTY_INDEX_LOGICAL_ORDER_EXCEPTION},
    {-1}, {-1},
#line 213 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str279, UC_PROPERTY_INDEX_NON_BREAK},
    {-1},
#line 171 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str281, UC_PROPERTY_INDEX_BIDI_COMMON_SEPARATOR},
    {-1},
#line 170 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str283, UC_PROPERTY_INDEX_BIDI_COMMON_SEPARATOR},
#line 190 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str284, UC_PROPERTY_INDEX_HEX_DIGIT},
#line 229 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str285, UC_PROPERTY_INDEX_QUOTATION_MARK},
    {-1}, {-1},
#line 225 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str288, UC_PROPERTY_INDEX_PARAGRAPH_SEPARATOR},
    {-1},
#line 38 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str290, UC_PROPERTY_INDEX_WHITE_SPACE},
#line 240 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str291, UC_PROPERTY_INDEX_OTHER_MATH},
    {-1},
#line 227 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str293, UC_PROPERTY_INDEX_QUOTATION_MARK},
#line 197 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str294, UC_PROPERTY_INDEX_UNIFIED_IDEOGRAPH},
    {-1}, {-1},
#line 138 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str297, UC_PROPERTY_INDEX_GRAPHEME_EXTEND},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 219 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str305, UC_PROPERTY_INDEX_PREPENDED_CONCATENATION_MARK},
    {-1}, {-1}, {-1}, {-1}, {-1},
#line 182 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str311, UC_PROPERTY_INDEX_BIDI_PDF},
#line 167 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str312, UC_PROPERTY_INDEX_BIDI_EUR_NUM_TERMINATOR},
    {-1}, {-1}, {-1},
#line 174 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str316, UC_PROPERTY_INDEX_BIDI_SEGMENT_SEPARATOR},
#line 193 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str317, UC_PROPERTY_INDEX_ASCII_HEX_DIGIT},
    {-1},
#line 149 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str319, UC_PROPERTY_INDEX_GRAPHEME_LINK},
#line 148 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str320, UC_PROPERTY_INDEX_GRAPHEME_LINK},
    {-1},
#line 237 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str322, UC_PROPERTY_INDEX_MATH},
    {-1}, {-1},
#line 127 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str325, UC_PROPERTY_INDEX_PATTERN_SYNTAX},
    {-1}, {-1},
#line 86 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str328, UC_PROPERTY_INDEX_CHANGES_WHEN_TITLECASED},
#line 147 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str329, UC_PROPERTY_INDEX_GRAPHEME_LINK},
#line 146 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str330, UC_PROPERTY_INDEX_GRAPHEME_LINK},
    {-1},
#line 80 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str332, UC_PROPERTY_INDEX_CHANGES_WHEN_LOWERCASED},
    {-1}, {-1}, {-1}, {-1},
#line 91 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str337, UC_PROPERTY_INDEX_CHANGES_WHEN_CASEFOLDED},
    {-1}, {-1}, {-1},
#line 175 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str341, UC_PROPERTY_INDEX_BIDI_SEGMENT_SEPARATOR},
    {-1}, {-1}, {-1}, {-1}, {-1},
#line 37 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str347, UC_PROPERTY_INDEX_WHITE_SPACE},
    {-1}, {-1}, {-1}, {-1},
#line 196 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str352, UC_PROPERTY_INDEX_UNIFIED_IDEOGRAPH},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 245 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str362, UC_PROPERTY_INDEX_COMBINING},
#line 123 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str363, UC_PROPERTY_INDEX_PATTERN_WHITE_SPACE},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1},
#line 94 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str374, UC_PROPERTY_INDEX_CHANGES_WHEN_CASEMAPPED},
    {-1}, {-1}, {-1}, {-1}, {-1},
#line 90 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str380, UC_PROPERTY_INDEX_CHANGES_WHEN_CASEFOLDED},
    {-1},
#line 218 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str382, UC_PROPERTY_INDEX_PREPENDED_CONCATENATION_MARK},
#line 83 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str383, UC_PROPERTY_INDEX_CHANGES_WHEN_UPPERCASED},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 87 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str392, UC_PROPERTY_INDEX_CHANGES_WHEN_TITLECASED},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 241 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str400, UC_PROPERTY_INDEX_PAIRED_PUNCTUATION},
    {-1}, {-1},
#line 178 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str403, UC_PROPERTY_INDEX_BIDI_NON_SPACING_MARK},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 122 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str411, UC_PROPERTY_INDEX_PATTERN_WHITE_SPACE},
    {-1},
#line 51 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str413, UC_PROPERTY_INDEX_OTHER_DEFAULT_IGNORABLE_CODE_POINT},
#line 184 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str414, UC_PROPERTY_INDEX_BIDI_EMBEDDING_OR_OVERRIDE},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 93 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str466, UC_PROPERTY_INDEX_CHANGES_WHEN_CASEMAPPED},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1},
#line 84 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str477, UC_PROPERTY_INDEX_CHANGES_WHEN_UPPERCASED},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1},
#line 179 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str498, UC_PROPERTY_INDEX_BIDI_NON_SPACING_MARK},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 81 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str507, UC_PROPERTY_INDEX_CHANGES_WHEN_LOWERCASED},
#line 150 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str508, UC_PROPERTY_INDEX_MODIFIER_COMBINING_MARK},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 151 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str527, UC_PROPERTY_INDEX_MODIFIER_COMBINING_MARK},
#line 89 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str528, UC_PROPERTY_INDEX_CHANGES_WHEN_CASEFOLDED},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1},
#line 126 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str548, UC_PROPERTY_INDEX_PATTERN_SYNTAX},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
    {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
#line 92 "unictype/pr_byname.gperf"
    {(int)(size_t)&((struct properties_stringpool_t *)0)->properties_stringpool_str565, UC_PROPERTY_INDEX_CHANGES_WHEN_CASEMAPPED}
  };
#if (defined __GNUC__ && __GNUC__ + (__GNUC_MINOR__ >= 6) > 4) || (defined __clang__ && __clang_major__ >= 3)
#pragma GCC diagnostic pop
#endif

static const struct named_property *
uc_property_lookup (register const char *str, register size_t len)
{
  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register unsigned int key = properties_hash (str, len);

      if (key <= MAX_HASH_VALUE)
        {
          register int o = properties[key].name;
          if (o >= 0)
            {
              register const char *s = o + properties_stringpool;

              if (*str == *s && !strcmp (str + 1, s + 1))
                return &properties[key];
            }
        }
    }
  return (struct named_property *) 0;
}
