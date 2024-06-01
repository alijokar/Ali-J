/*
Goal: How to work with date and time in C. 

Simple time:
            Simple time is a compact representation of a calendar time; it is the number of seconds of elapsed time since Unix epoch.
            Uses the time_t data type.
Broken-down:
            Time represents a human-readable calendar time. It is divided into a set of components specifying the year, month, day,
            and so on in the Gregorian calendar, for a specific time zone. The broken-down time uses the struct tm data type.

ref: 
[1] https://zetcode.com/articles/cdatetime/
*/

// Unix Time

#include <stdio.h>
#include <time.h>

int main(void) {
        
    // Data Type (-1 will be returned if the time function fails) 
    // Getting the Unix time and save in "rawtime" 
    time_t rawtime = time(NULL);
    
    if (rawtime == -1) {
        
        puts("The time() function failed");
        return 1;
    }
    // Converting "rawtime" into the local broken-down time.

    /*
    The localtime() functions converts a simple calendar time into a broken-down time.
    It takes the current timezone into account.

        struct tm *localtime(const time_t *clock);
    
    It stores a tm structure and returns a pointer to that structure.

    struct tm {
        int    tm_sec   seconds [0,61]
        int    tm_min   minutes [0,59]
        int    tm_hour  hour [0,23]
        int    tm_mday  day of month [1,31]
        int    tm_mon   month of year [0,11]
        int    tm_year  years since 1900
        int    tm_wday  day of week [0,6] (Sunday = 0)
        int    tm_yday  day of year [0,365]
        int    tm_isdst daylight savings flag
    }

    */

    struct tm *ptm = localtime(&rawtime);
    
    if (ptm == NULL) {
        
        puts("The localtime() function failed");
        return 1;
    }

    printf("The date (mm-dd-yyyy) is %ld-%ld-%ld\n", ptm->tm_mon+1, ptm->tm_mday, ptm->tm_year+1900);
    
    printf("The time is: %02d:%02d:%02d\n", ptm->tm_hour, 
           ptm->tm_min, ptm->tm_sec);

    return 0;
}