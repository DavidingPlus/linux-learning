#include "leap_year.h"


bool isLeapYear(int year) { return year > 0 && (0 == year % 400 || (0 == year % 4 && 0 != year % 100)); }
