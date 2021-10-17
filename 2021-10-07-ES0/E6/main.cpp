#include <iostream>
using namespace std;

bool Perfetto(unsigned);

int main() {
  for (unsigned i = 1; i <= 10000; i++) {
    if (Perfetto(i)) {
      cout << i << ", ";
    }
  }

  cout << endl;
}

bool Perfetto(unsigned n) {
  unsigned somma_divisori = 0;

  for (unsigned divisore = 1; divisore < n / 2 + 1; divisore++) {
    if (n % divisore == 0) {
      somma_divisori += divisore;
    }
  }

  return somma_divisori == n;
}
