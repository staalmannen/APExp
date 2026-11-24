/* Date's local time zone (quickts): libc's own tm_gmtoff, the branch for a
 * libc without it (newlib, as on the ESP32; forced here with
 * -DCONFIG_NO_TM_GMTOFF) and an embedder's JS_SetTimezoneOffsetFunc.
 *
 * Built and run twice by tz.sh, once per branch. The expected offsets come
 * from this file's own localtime_r(), so the host libc must have tm_gmtoff
 * (glibc, macOS, musl, BSD).
 */
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "quickjs.h"

static int failures;

static int eval_int(JSContext *ctx, const char *src)
{
    JSValue v = JS_Eval(ctx, src, strlen(src), "<tz>", JS_EVAL_TYPE_GLOBAL);
    int32_t n = 0;
    if (JS_IsException(v)) {
        JSValue e = JS_GetException(ctx);
        const char *msg = JS_ToCString(ctx, e);
        fprintf(stderr, "exception in `%s`: %s\n", src, msg ? msg : "?");
        JS_FreeCString(ctx, msg);
        JS_FreeValue(ctx, e);
        failures++;
        return 0;
    }
    JS_ToInt32(ctx, &n, v);
    JS_FreeValue(ctx, v);
    return n;
}

static void expect(const char *what, int got, int want)
{
    if (got != want) {
        fprintf(stderr, "FAIL %s: got %d, want %d\n", what, got, want);
        failures++;
    }
}

/* India, +5:30, whatever libc thinks */
static int india(int64_t time)
{
    (void)time;
    return -330;
}

int main(int argc, char **argv)
{
    static const char *zones[] = {
        "UTC", "Europe/Tallinn", "America/New_York", "Australia/Adelaide",
        "America/St_Johns", "Asia/Kathmandu", "Pacific/Chatham",
    };
    /* 2024-01-15 and 2024-07-15 at noon UTC, the epoch, and 2099-12-31 */
    static const int64_t instants[] = {
        INT64_C(1705320000000), INT64_C(1721044800000), 0, INT64_C(4102358400000),
    };
    const char *variant = argc > 1 ? argv[1] : "?";
    JSRuntime *rt = JS_NewRuntime();
    JSContext *ctx = JS_NewContext(rt);
    char src[128], what[160];
    size_t z, i;

    for (z = 0; z < sizeof(zones) / sizeof(zones[0]); z++) {
        setenv("TZ", zones[z], 1);
        tzset();
        for (i = 0; i < sizeof(instants) / sizeof(instants[0]); i++) {
            time_t ti = (time_t)(instants[i] / 1000);
            struct tm tm;
            localtime_r(&ti, &tm);
            snprintf(src, sizeof(src), "new Date(%" PRId64 ").getTimezoneOffset()", instants[i]);
            snprintf(what, sizeof(what), "%s %s at %" PRId64, variant, zones[z], instants[i]);
            expect(what, eval_int(ctx, src), (int)(-tm.tm_gmtoff / 60));
            /* local fields follow the offset both ways */
            snprintf(src, sizeof(src), "new Date(%" PRId64 ").getHours()", instants[i]);
            snprintf(what, sizeof(what), "%s %s getHours at %" PRId64, variant, zones[z], instants[i]);
            expect(what, eval_int(ctx, src), tm.tm_hour);
        }
    }

    setenv("TZ", "UTC", 1);
    tzset();
    JS_SetTimezoneOffsetFunc(india);
    expect("hook getTimezoneOffset", eval_int(ctx, "new Date(0).getTimezoneOffset()"), -330);
    expect("hook getHours", eval_int(ctx, "new Date(0).getHours()"), 5);
    expect("hook getMinutes", eval_int(ctx, "new Date(0).getMinutes()"), 30);
    expect("hook local constructor", eval_int(ctx, "new Date(1970, 0, 1, 5, 30).getTime()"), 0);
    JS_SetTimezoneOffsetFunc(NULL);
    expect("hook cleared", eval_int(ctx, "new Date(0).getTimezoneOffset()"), 0);

    JS_FreeContext(ctx);
    JS_FreeRuntime(rt);
    if (failures) {
        fprintf(stderr, "test_tz %s: %d failed\n", variant, failures);
        return 1;
    }
    printf("test_tz %s: ok\n", variant);
    return 0;
}
