#pragma once

class Date {
public:
  Date(unsigned d, unsigned m, unsigned y);
  Date();

  unsigned MonthDays() const;
  bool     IsLeapYear() const;
  void     Next();
  void     Previous();

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
