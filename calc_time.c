#include "calc_time.h"
 /**
* Determine whether or not year is a leap year
* @v tm_year           Years since 1900
* @v is_leap_year      Year is a leap year
*/
int is_leap_year (int tm_year ) {
        int leap_year = 0;
 
         if ( ( tm_year % 4 ) == 0 )
                 leap_year = 1;
         if ( ( tm_year % 100 ) == 0 )
                 leap_year = 0;
         if ( ( tm_year % 400 ) == 100 )
                 leap_year = 1;
 
         return leap_year;
}
 
/*
 * Calculate number of leap years since 1900
 * @v tm_year           Years since 1900
 * @v num_leap_years    Number of leap years
 */
 int leap_years_to_end (int tm_year ) {
         unsigned int leap_years = 0;
         leap_years += ( tm_year / 4 );
         leap_years -= ( tm_year / 100 );
         leap_years += ( ( tm_year + 300 ) / 400 );
         return leap_years;
 }
 
 /**
  * Calculate day of week
  * @v tm_year           Years since 1900
  * @v tm_mon            Month of year [0,11]
  * @v tm_day            Day of month [1,31]
  */
int day_of_week ( int tm_year, int tm_mon, int tm_mday ) {
         static const unsigned char offset[12] =
                 { 1, 4, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5 };
         int pseudo_year = tm_year;

         if ( tm_mon < 2 )
                 pseudo_year--;
         return ( ( pseudo_year + leap_years_to_end ( pseudo_year ) +
                    offset[tm_mon] + tm_mday ) % 7 );
 }
 
/** Days from start of year until start of months (in non-leap years) */
const unsigned int days_to_month_start[] =
         { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
 
/**
  * Calculate seconds since the Epoch
  * @v tm                Broken-down time
  * @ret time            Seconds since the Epoch
*/


unsigned long getUnixSeconds ( struct tm *tm ) {
         int days_since_epoch;
         int seconds_since_day;
         unsigned long seconds;
 /* Calculate day of year */
         tm->tm_yday = ( ( tm->tm_mday - 1 ) +
                         days_to_month_start[ tm->tm_mon ] );
         if ( ( tm->tm_mon >= 2 ) && is_leap_year ( tm->tm_year ) )
                tm->tm_yday++;
 /* Calculate day of week */
         tm->tm_wday = day_of_week ( tm->tm_year, tm->tm_mon, tm->tm_mday );
 /* Calculate seconds since the Epoch */
         days_since_epoch = ( tm->tm_yday + ( 365 * tm->tm_year ) - 25567 +
                              leap_years_to_end ( tm->tm_year - 1 ) );
         seconds_since_day =
                 ( ( ( ( tm->tm_hour * 60 ) + tm->tm_min ) * 60 ) + tm->tm_sec );
       seconds = ( ( ( ( unsigned long ) days_since_epoch ) * ( ( unsigned long ) 86400 ) ) +
                    seconds_since_day );
         return seconds;
}



