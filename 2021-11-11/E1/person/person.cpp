#include "person.hpp"

Person::Person(string n, string s, Date d, string p)
    : name(n), surname(s), birthDate(d), birthPlace(p) {}

Person::Person(const Person& p)
    : name(p.name),
      surname(p.surname),
      birthDate(p.birthDate),
      birthPlace(p.birthPlace) {}

ostream& operator<<(ostream& os, const Person& p) {
  os << "-" << p.name << ", " << p.surname << endl
     << p.birthDate << " " << p.birthPlace << endl;

  return os;
}

istream& operator>>(istream& is, Person& p) {
  is.ignore(256, '-');
  getline(is, p.name, ',');
  getline(is, p.surname);
  is >> p.birthDate >> p.birthPlace;

  return is;
}

bool Person::operator<(const Person& p) const {
  if (birthDate == p.birthDate) {
    return name < p.name;
  } else {
    return birthDate < p.birthDate;
  }
}

Person& Person::operator=(const Person& p) {
  name       = p.name;
  surname    = p.surname;
  birthDate  = p.birthDate;
  birthPlace = p.birthPlace;
  return *this;
}
