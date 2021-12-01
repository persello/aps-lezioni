#pragma once

#include <iostream>
using namespace std;

class Stack {
  friend ostream& operator<<(ostream&, const Stack&);
  friend istream& operator>>(istream&, Stack&);

public:
  Stack();
  Stack(const Stack&);
  ~Stack();
  Stack& operator=(const Stack&);
  Stack& Push(const int&);
  Stack& Pop();
  int    Top() const;
  bool   IsEmpty() const { return top == -1; }

private:
  int* vec;
  int  size;
  int  top;
};
