#pragma once

#include "b.hpp"

class A {
public:
  A() { x = 10; }

  A(int c, int d) : b(d) { x = c; }

  int x;

  // Quando viene chiamato A::A(), b viene inizializzato con il costruttore a
  // zero argomenti.
  B b;
};
