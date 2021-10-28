#pragma once

#include <iostream>
using namespace std;

class Stack {
  friend ostream &operator<<(ostream &, const Stack &);
  friend istream &operator>>(istream &, Stack &);

public:
  Stack();
  Stack(const Stack &);
  // ~Stack();
  void Push(const int &);
  void Pop() { top--; }
  int Top() const { return vec[top]; }
  bool IsEmpty() const { return top == -1; }

private:
  int *vec;
  int size;
  int top;
};
