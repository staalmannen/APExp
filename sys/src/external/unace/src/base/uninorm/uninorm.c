#include <stdio.h>
#include <string.h>

#include "base/includes.h"

#include "unincore.h"
#include "wincode.h"

/*-----------------BASE_UNINORM_CP850ToUTF8NFD------------------------------*/
/* UTF-8 NFD is the filename representation format in Apple's Mac OS X (Darwin) HFS+ file system */
INT BASE_UNINORM_CP850ToUTF8NFD(UCHAR *cp850String, INT len)
{
   UINT Unicode[BASE_LFN_MAXLEN+1], Normalized[BASE_LFN_MAXLEN+1], *destptr = Unicode;
   UCHAR *srcptr = cp850String, *resultstr = cp850String;

   srcptr[len] = 0;
   /* First, convert that DOS CP850 encoded String to Unicode */
   while (*srcptr)
   {
     UCHAR srccode = *srcptr++;
     *destptr++ = CP850toUnicode[srccode];
   }
   *destptr = 0;
   
   /* Then normalize and return UTF-8 encoded in place of the input string */
   normalize_nfd(Normalized, Unicode);
   encode_utf8((char *) resultstr, Normalized);
   
   return strlen((char *) resultstr);
}

/*-----------------BASE_UNINORM_CP850ToUTF8NFC------------------------------*/
/* UTF-8 NFC is the filename representation format in most other UNIX systems including Linux */
INT BASE_UNINORM_CP850ToUTF8NFC(UCHAR *cp850String, INT len)
{
   UINT Unicode[BASE_LFN_MAXLEN+1], Normalized[BASE_LFN_MAXLEN+1], *destptr = Unicode;
   UCHAR *srcptr = cp850String, *resultstr = cp850String;

   if ((UINT) len >= BASE_LFN_MAXLEN)
     len = BASE_LFN_MAXLEN - 1;

   srcptr[len] = 0;
   /* First, convert that DOS CP850 encoded String to Unicode */
   while (*srcptr)
   {
     UCHAR srccode = *srcptr++;
     *destptr++ = CP850toUnicode[srccode];
   }
   *destptr = 0;
   
   /* Then normalize and return UTF-8 encoded in place of the input string */
   normalize_nfc(Normalized, Unicode);
   encode_utf8( (char *) resultstr, Normalized);
   resultstr[len] = 0;

   
   return strlen( (char *) resultstr);
}


UCHAR OEMToANSI(UCHAR cp850) {
  INT i, Unicode = CP850toUnicode[cp850];
  for (i=0; i<256; i++) if (Unicode==CP1252toUnicode[i]) return (UCHAR) i; /* Latin-1 */
//  for (i=0; i<256; i++) if (Unicode==CP1250toUnicode[i]) return (UCHAR) i;
//  for (i=0; i<256; i++) if (Unicode==CP1254toUnicode[i]) return (UCHAR) i;
//  for (i=0; i<256; i++) if (Unicode==CP1257toUnicode[i]) return (UCHAR) i;
  
  return '_';
} 

/*-----------------BASE_UNINORM_CP850ToANSI------------------------------*/
/* For UNIX (Linux) file systems with Latin-1/CP1252 based filename encoding */
INT BASE_UNINORM_CP850ToANSI(UCHAR *cp850String, INT len)
{
   UCHAR *ptr = cp850String;

   ptr[len] = 0;
   for (; *ptr; ptr++)
   {
     *ptr = OEMToANSI(*ptr);
   }

   return len;
}


/*-----------------BASE_UNINORM_UTF8NFCToNFD (Alternative Implementation using Apples OSX 10.2 API)
#include <CoreFoundation/CoreFoundation.h>

INT BASE_UNINORM_CP850ToUTF8NFD(UCHAR *utf8src, INT len)
{
  CFStringRef	     cfs = CFStringCreateWithBytes(NULL, utf8src, len, kCFStringEncodingDOSLatin1, 0);
  CFMutableStringRef str = CFStringCreateMutableCopy(NULL, 0, cfs);
  CFRelease(cfs);
  // HFS+ imposes Unicode2.1 decomposed UTF-8 encoding on all path elements
  CFStringNormalize(str, kCFStringNormalizationFormD); // canonical decomposition
  {
    CFRange rng = CFRangeMake(0, CFStringGetLength(str));
    UCHAR *dest = utf8src;
    CFIndex destlen = 0;
    CFStringGetBytes(str, rng, kCFStringEncodingUTF8, '?', 0, (UInt8 *)utf8src, BASE_LFN_MAXLEN, &destlen);
    CFRelease(str);
    dest[destlen]= '\0';
    return destlen;
  }
}

*/
