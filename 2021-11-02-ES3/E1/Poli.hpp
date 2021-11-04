#pragma once

#include <iostream>
using namespace std;

class Poli {
  // Operatori friend
  friend Poli operator+(const Poli &a, const Poli &b);
  friend Poli operator-(const Poli &a, const Poli &b);
  friend ostream &operator<<(ostream &os, const Poli &p);
  friend istream &operator>>(istream &is, Poli &p);

public:
  // Costruttori
  Poli();
  Poli(const Poli &p);
  Poli(double coeff, int deg);
  ~Poli();

  // Operatori
  double operator[](int deg) const;
  double &operator[](int deg);
  Poli &operator=(const Poli &p);
  double operator()(double x) const;

private:
  int size;
  double *vec;

  bool ZeroUnderDeg(int deg) const;
};
