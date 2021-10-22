#include "Vettori3D.hpp"

#include <iostream>
using namespace std;

int main() {
  Vector a, b;

  cout << "Inserire vettore \"a\" (x, y, z): ";
  cin >> a;

  cout << "Inserire vettore \"b\" (x, y, z): ";
  cin >> b;

  cout << "Hai inserito i vettori seguenti: a = " << a << ", b = " << b << endl;

  cout << "a + b = " << (a + b) << endl;
  cout << "a & b = " << (a & b) << endl;
  cout << "a * b = " << (a * b) << endl;
}
