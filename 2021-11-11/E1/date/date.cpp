#include "date.hpp"

#include <iostream>
using namespace std;

// Constructors

Date::Date(unsigned d, unsigned m, unsigned y) : REF_YEAR(1970) {
  day = d;
  month = m;
  year = y;

  if (!Valid()) {
    day = 1;
    month = 1;
    year = REF_YEAR;
  }
}

Date::Date(const Date &d) : REF_YEAR(d.REF_YEAR) {
  day = d.day;
  month = d.month;
  year = d.year;
}

Date::Date() : REF_YEAR(1970) {
  day = 1;
  month = 1;
  year = REF_YEAR;
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

Date &Date::operator++() {
  if (day < MonthDays()) {
    day++;
  } else {
    if (month < 12) {
      day = 1;
      month++;
    } else {
      day = 1;
      month = 1;
      year++;
    }
  }

  return *this;
}

Date &Date::operator--() {
  if (day > 1) {
    day--;
  } else {
    if (month > 1) {
      month--;
      day = MonthDays();
    } else {
      day = 31;
      month = 12;
      year--;
    }
  }

  return *this;
}

void Date::operator+=(int n) {
  if (n > 0) {
    for (int i = 0; i < n; i++) {
      ++(*this);
    }
  } else {
    for (int i = 0; i > n; i--) {
      --(*this);
    }
  }
}

Date Date::operator+(int n) const {
  Date d = *this;

  if (n > 0) {
    for (int i = 0; i < n; i++) {
      ++d;
    }
  } else {
    for (int i = 0; i > n; i--) {
      --d;
    }
  }

  return d;
}

Date &Date::operator=(const Date &d) {
  day = d.day;
  month = d.month;
  year = d.year;
  return *this;
}

// Friend functions
bool operator==(const Date &d1, const Date &d2) {
  return d1.day == d2.day && d1.month == d2.month && d1.year == d2.year;
}

bool operator<(const Date &d1, const Date &d2) {
  return d1.year < d2.year || (d1.year == d2.year && d1.month < d2.month) ||
         (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day);
}

bool operator<=(const Date &d1, const Date &d2) {
  return d1.year < d2.year || (d1.year == d2.year && d1.month < d2.month) ||
         (d1.year == d2.year && d1.month == d2.month && d1.day <= d2.day);
}

ostream &operator<<(ostream &os, const Date &d) {
  os << d.day << "/" << d.month << "/" << d.year;
  return os;
}

istream &operator>>(istream &is, Date &d) {
  char c;
  is >> d.day >> c >> d.month >> c >> d.year;

  if (!d.Valid()) {
    d.day = 1;
    d.month = 1;
    d.year = d.REF_YEAR;
  }

  return is;
}

// Private functions

bool Date::Valid() const {
  return (year >= 1) && (month >= 1 && month <= 12) &&
         (day >= 1 && day <= MonthDays());
}
