#pragma once

#include <iostream>
using namespace std;

class Vector {

  friend Vector operator+(const Vector &a, const Vector &b);
  friend Vector operator&(const Vector &a, const Vector &b);
  friend double operator*(const Vector &a, const Vector &b);
  friend ostream &operator<<(ostream &os, const Vector &v);
  friend istream &operator>>(istream &is, Vector &v);

public:
  Vector(double x, double y, double z = 0);
  Vector();

  double X() const { return x; };
  double Y() const { return y; };
  double Z() const { return z; };

private:
  double x, y, z;
};
