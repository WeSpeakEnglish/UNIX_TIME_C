#ifndef calc_time_h
#define calc_time_h

struct tm{
  int tm_year;
  int tm_mon;
  int tm_yday;
  int tm_mday;
  int tm_wday;
  int tm_hour;
  int tm_min;
  int tm_sec;
};

unsigned long getUnixSeconds ( struct tm *tm );
int day_of_week ( int tm_year, int tm_mon, int tm_mday );
int leap_years_to_end (int tm_year );
int is_leap_year (int tm_year );


#endif
