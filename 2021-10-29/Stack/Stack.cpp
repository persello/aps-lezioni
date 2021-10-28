#include "Stack.hpp"

#include <iostream>
using namespace std;

// ----- PUBLIC -----
Stack::Stack() {
  top = -1;
  size = 100;
  vec = new int[size];
}

Stack::Stack(const Stack &s) {
  top = s.top;
  size = s.size;
  vec = new int[size];
  for (int i = 0; i <= top; i++) {
    vec[i] = s.vec[i];
  }
}

Stack::~Stack() { delete[] vec; }

Stack &Stack::operator=(const Stack &s) {
  if (s.top >= size) {
    delete[] vec;
    size = s.size;
    vec = new int[size];
  }

  top = s.top;

  for (int i = 0; i <= top; i++) {
    vec[i] = s.vec[i];
  }
  return *this;
}

Stack &Stack::Push(const int &val) {
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

  return *this;
}

Stack &Stack::Pop() {
  if (top == -1) {
    throw logic_error("Stack is empty");
  }

  top--;
  return *this;
}

int Stack::Top() const {
  if (top == -1) {
    throw logic_error("Stack is empty");
  }

  return vec[top];
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
