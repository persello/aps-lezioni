#include "Vettori3D.hpp"

Vector::Vector() {
  x = 0;
  y = 0;
  z = 0;
}

Vector::Vector(double x, double y, double z) {
  this->x = x;
  this->y = y;
  this->z = z;
}

Vector operator+(const Vector &a, const Vector &b) {
  return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector operator&(const Vector &a, const Vector &b) {
  return Vector(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
                a.x * b.y - a.y * b.x);
}

double operator*(const Vector &a, const Vector &b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

ostream &operator<<(ostream &os, const Vector &v) {
  os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
  return os;
}

istream &operator>>(istream &is, Vector &v) {
  char c;
  double x, y, z;
  //    (    x    ,    y    ,    z    )
  is >> c >> x >> c >> y >> c >> z >> c;
  v = Vector(x, y, z);
  return is;
}
