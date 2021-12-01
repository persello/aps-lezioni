#pragma once

#include "../date/date.hpp"
#include <string>

using namespace std;

class Person {
  friend ostream& operator<<(ostream& os, const Person& p);
  friend istream& operator>>(istream& is, Person& p);

public:
  Person(string n, string s, Date d, string p);
  Person(const Person& p);
  Person() {};
  bool    operator<(const Person& p) const;
  Person& operator=(const Person& p);

  // Getters
  string Name() const { return name; }
  string Surname() const { return surname; }
  Date   BirthDate() const { return birthDate; }
  string BirthPlace() const { return birthPlace; }

private:
  string name;
  string surname;
  Date   birthDate;
  string birthPlace;
};
