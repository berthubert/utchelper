#include <sys/time.h>
#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>
#include <time.h>

/* Returns -1 on error. fmtstr is according to strptime() */

extern "C"
int utcstr2epoch(const char* timestr, const char* fmtstr, struct tm* output)
{
  std::tm t = {}; // tm_isdst = 0, don't think about it please, this is UTC
  std::istringstream ss(timestr);
  ss.imbue(std::locale()); // "LANG=C", but local
  
  ss >> std::get_time(&t, fmtstr);
  if (ss.fail()) 
    return -1;
  // now fix up the day of week, day of year etc
  t.tm_isdst = 0; // no thinking!
  t.tm_wday = -1;
  if(mktime(&t) == -1 && t.tm_wday == -1) // "real error"
    return -1;
  
  *output = t;
  return 0;
}
