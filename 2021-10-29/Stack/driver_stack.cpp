#include "Stack.hpp"

#include <iostream>
using namespace std;

int main() {
  Stack s1;

  s1.Push(25).Push(8).Push(5).Pop();

  Stack s2 = s1;
  cout << s1 << "  " << s2 << endl;

  s2.Pop();
  cout << s1 << "  " << s2 << endl;

  s2.Push(12);
  cout << s1 << "  " << s2 << endl;

  s1 = s2;
  cout << s1 << "  " << s2 << endl;

  return 0;
}
