#include "Stack.hpp"

#include <iostream>
using namespace std;

// ----- PUBLIC -----
Stack::Stack() {
  top = -1;
  size = 100;
  vec = new int[size];
}

Stack::Stack(const Stack& s) {
  top = s.top;
  size = s.size;
  vec = new int[size];
  for (int i = 0; i <= top; i++) {
    vec[i] = s.vec[i];
  }
}

void Stack::Push(const int &val) {
  if (top == size - 1) {
    int *aux_vec = new int[size * 2];
    for (int i = 0; i < size; i++) {
      aux_vec[i] = vec[i];
    }
    delete[] vec;
    vec = aux_vec;
    size *= 2;
  }

  top++;
  vec[top] = val;
}

ostream &operator<<(ostream &os, const Stack &s) {
  for (int i = 0; i <= s.top; i++) {
    os << s.vec[i] << " ";
  }
  return os;
}

istream &operator>>(istream &is, Stack &s) {
  int val;
  while (is >> val) {
    s.Push(val);
  }
  return is;
}
