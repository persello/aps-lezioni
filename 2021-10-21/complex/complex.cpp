#include "complex.hpp"

#include <cmath>

// Constructors

Complex::Complex(double real, double imag) {
  this->real = real;
  this->imag = imag;
}

Complex::Complex(double real) {
  this->real = real;
  this->imag = 0;
}

Complex::Complex() {
  this->real = 0;
  this->imag = 0;
}

// Getters

double Complex::Real() const { return this->real; }
double Complex::Imag() const { return this->imag; }
double Complex::Abs() const { return sqrt(real * real + imag * imag); }
double Complex::Arg() const { return atan2(imag, real); }

// Prefix operators

Complex Complex::operator-() const { return Complex(-real, -imag); }

// Infix operators

Complex operator+(const Complex& a, const Complex& b) {
  return Complex(a.Real() + b.Real(), a.Imag() + b.Imag());
}

Complex operator-(const Complex& a, const Complex& b) { return a + (-b); }

Complex operator*(const Complex& a, const Complex& b) {
  return Complex(a.Real() * b.Real() - a.Imag() * b.Imag(),
                 a.Real() * b.Imag() + a.Imag() * b.Real());
}

Complex operator/(const Complex& a, const Complex& b) {}