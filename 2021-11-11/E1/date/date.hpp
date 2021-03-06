#pragma once

#include <iostream>
using namespace std;

class Date {

  // Sembra che abbia tre operandi ma in realtà, essendo una funzione esterna,
  // ne ha due.
  friend bool     operator==(const Date&, const Date&);
  friend bool     operator<(const Date&, const Date&);
  friend bool     operator<=(const Date&, const Date&);
  friend ostream& operator<<(ostream&, const Date&);
  friend istream& operator>>(istream&, Date&);

public:
  Date(unsigned d, unsigned m, unsigned y);
  Date(const Date& d);
  Date();

  unsigned MonthDays() const;
  bool     IsLeapYear() const;

  Date& operator++();
  Date& operator--();

  void operator+=(int n);

  Date  operator+(int n) const;
  Date  operator-(int n) const;
  Date& operator=(const Date& d);

  unsigned Day() const { return day; }
  unsigned Month() const { return month; }
  unsigned Year() const { return year; }

private:
  bool           Valid() const;
  unsigned       day;
  unsigned       month;
  unsigned       year;
  const unsigned REF_YEAR;
};
