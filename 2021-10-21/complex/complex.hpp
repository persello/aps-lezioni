#pragma once

class Complex {

  friend Complex operator+(const Complex&, const Complex&);
  friend Complex operator-(const Complex&, const Complex&);
  friend Complex operator*(const Complex&, const Complex&);
  friend Complex operator/(const Complex&, const Complex&);

public:
  Complex(double real, double imag);
  Complex(double real);
  Complex();

  double Real() const;
  double Imag() const;

  double Abs() const;
  double Arg() const;

  Complex operator-() const;

private:
  double real;
  double imag;
};