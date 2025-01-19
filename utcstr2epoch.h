#pragma once
#include <sys/time.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

int utcstr2epoch(const char* timestr, const char* fmtstr, struct tm* output);

#ifdef __cplusplus
}
#endif
