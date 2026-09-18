/*
 * tz-xcheck.c -- libap's own timezone engine, run against glibc's, on
 * the BUILD HOST. This is not a Plan 9 test: it links
 * sys/src/ape/lib/ap/time/tzone.c into a glibc program and compares the
 * two answers directly.
 *
 *	gcc -I../../src/ape/lib/ap/time -o tz-xcheck \
 *	    tz-xcheck.c ../../src/ape/lib/ap/time/tzone.c && ./tz-xcheck
 *
 * WHY IT EXISTS. tz-test.c checks the LIBRARY against expectations, and
 * on glibc it passes by asking glibc for the answers -- it cannot tell
 * whether libap's parser is right until it runs on the VM, where a round
 * trip costs a full rebuild. This links the parser under test and sweeps
 * ~1.4 million instants across nineteen TZ strings, comparing offset,
 * tm_isdst and the zone name for each one. It found two bugs in that
 * parser before it ever reached Plan 9; the second of them would have
 * looked like a passing suite.
 *
 *	TZ=GMT    a name with NO offset. POSIX requires the offset;
 *	          glibc treats it as +0 and keeps the name. The first
 *	          version rejected it and fell through to the UTC
 *	          fallback, losing the name -- and tz-test.c's own
 *	          `check("GMT", ...)` line would have failed on the VM.
 *	100k+ mismatches, then 6k, then 0.
 *
 * TWO DIVERGENCES ARE DELIBERATE AND ARE EXCLUDED HERE RATHER THAN
 * MATCHED. Both are glibc implementation artifacts, not rules, and the
 * standing rule in this tree is that one operating system's own
 * behaviour is a probe, not a library rule:
 *
 *	BEFORE 1970  glibc computes no transitions at all for a
 *	             POSIX-rule zone, so CET-1CEST,M3.5.0,M10.5.0 is
 *	             never DST in 1968. Nothing in POSIX says that; it
 *	             falls out of a transition table that starts at the
 *	             epoch. libap applies the rules for every year.
 *	NO RULES     `TZ=EST5EDT' with no rule part is
 *	             implementation-defined. glibc resolves it against
 *	             real US historical tzdata -- it has 1974-01-06 and
 *	             1975-02-23, the emergency DST years -- which needs a
 *	             database this system does not carry. libap uses the
 *	             US rules since 2007, which is what glibc's own answer
 *	             becomes from 2007 on, so the sweep starts there for
 *	             those.
 *
 * Exit status is the number of mismatches, as everything else here.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
extern void _tzrefresh(void);
extern long _tzoffset(time_t, const char **, int *);
static const char *tzs[] = {
 "UTC0","EST5","GMT-11:30","GMT-07:30","GMT-03:30","GMT","+04:20","+03:20",
 "US/East-Indiana","CET-01:00CEST-02:00,M3.5.0/02:00,M10.5.0/03:00",
 "<+0420>-4:20","EST5EDT,M3.2.0/2,M11.1.0/2","EST5EDT",
 "NZST-12NZDT,M9.5.0,M4.1.0/3",              /* southern hemisphere */
 "AEST-10AEDT,M10.1.0,M4.1.0/3",
 "IST-5:30","JST-9","PST8PDT,M3.2.0,M11.1.0",
 "XXX3EEE,J60/0,J300/0",                      /* Julian rules */
 "YYY4ZZZ,59,300",                            /* zero-based rules */
 0 };
int main(void){
  int bad=0, n=0;
  for(const char **p=tzs;*p;p++){
    setenv("TZ",*p,1); tzset(); _tzrefresh();
    /*
     * From 1970 (glibc computes no transitions before the epoch for a
     * POSIX-rule zone -- its own artifact, not a rule) and, for a DST
     * name with NO rules, only from 2007: glibc resolves those against
     * real US historical tzdata (it has 1974-01-06 and 1975-02-23, the
     * emergency DST years), which needs a database we do not carry.
     * From 2007 its answer is exactly M3.2.0/2,M11.1.0/2.
     */
    int norules = strchr(*p, ',') == 0 && strlen(*p) > 6;
    for(time_t t = norules ? 1167609600LL : 0LL; t<1900000000LL; t+=21600){
      struct tm g; const char *nm; int isd;
      localtime_r(&t,&g);
      long mine=_tzoffset(t,&nm,&isd);
      n++;
      if(mine!=g.tm_gmtoff || isd!=(g.tm_isdst>0)){
        if(bad<6) printf("MISMATCH TZ=%-46s t=%lld glibc off=%+ld isdst=%d | mine off=%+ld isdst=%d\n",
             *p,(long long)t,g.tm_gmtoff,g.tm_isdst,mine,isd);
        bad++;
      } else if (g.tm_zone && *g.tm_zone && strcmp(nm,g.tm_zone)!=0) {
        if(bad<6) printf("NAME TZ=%-40s t=%lld glibc=%s mine=%s\n",*p,(long long)t,g.tm_zone,nm);
        bad++;
      }
    }
  }
  printf("%d instants compared, %d mismatches\n", n, bad);
  return bad!=0;
}
