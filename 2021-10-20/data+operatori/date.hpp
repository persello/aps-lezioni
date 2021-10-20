#pragma once

class Date {

  // Sembra che abbia tre operandi ma in realtà, essendo una funzione esterna,
  // ne ha due.
  friend bool operator==(const Date &, const Date &);

public:
  Date(unsigned d, unsigned m, unsigned y);
  Date();

  unsigned MonthDays() const;
  bool IsLeapYear() const;

  void operator++();
  void operator--();

  void operator+=(int n);

  Date operator+(int n) const;
  Date operator-(int n) const;

  unsigned Day() const { return day; }
  unsigned Month() const { return month; }
  unsigned Year() const { return year; }

private:
  bool Valid() const;
  unsigned day;
  unsigned month;
  unsigned year;
  const unsigned REF_YEAR;
};
