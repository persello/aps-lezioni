#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v(5, 1);
  vector<int>::iterator i = v.begin();

  while (i != v.end()) {
    cout << *i << endl;
    i++;
  }
}