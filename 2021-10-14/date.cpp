#include "date.hpp"

// Constructors

Date::Date(unsigned d, unsigned m, unsigned y) : REF_YEAR(1970) {
  day   = d;
  month = m;
  year  = y;

  if (!Valid()) {
    day   = 1;
    month = 1;
    year  = 1970;
  }
}

Date::Date() : REF_YEAR(1970) {
  day   = 1;
  month = 1;
  year  = 1970;
}

// Public functions

unsigned Date::MonthDays() const {
  if (month == 11 || month == 4 || month == 6 || month == 9)
    return 30;
  else if (month == 2)
    return IsLeapYear() ? 29 : 28;
  else
    return 31;
}

bool Date::IsLeapYear() const {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void Date::Next() {
  if (day < MonthDays()) {
    day++;
  } else {
    if (month < 12) {
      day = 1;
      month++;
    } else {
      day   = 1;
      month = 1;
      year++;
    }
  }
}

void Date::Previous() {
  if (day > 1) {
    day--;
  } else {
    if (month > 1) {
      day = MonthDays();
      month--;
    } else {
      day   = 31;
      month = 12;
      year--;
    }
  }
}

// Private functions

bool Date::Valid() const {
  return (year >= 1) && (month >= 1 && month <= 12) &&
         (day >= 1 && day <= MonthDays());
}
