#include "utcstr2epoch.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  if(argc  < 2) {
    puts("Syntax: utcparse \"Wed, 31 Dec 1969 23:59:00\" [\"%a, %d %b %Y %H:%M:%S\"]");
    return EXIT_FAILURE;
  }
  setlocale(LC_TIME, ""); // respect the environment variables
  
  struct tm tmt;
  if(!utcstr2epoch(argv[1], argc > 2 ? argv[2] : "%a, %d %b %Y %H:%M:%S", &tmt)) {
    char buffer[80];
    if(strftime(buffer, sizeof(buffer), "%A, %e %B %Y %H:%M:%S, day of year %j", &tmt))
      printf("UTC Time: %s\ntime_t:   %ld\n", buffer, timegm(&tmt));
  }
  else
    puts("Failed to parse time string");
}
