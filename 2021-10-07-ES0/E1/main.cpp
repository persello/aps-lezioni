#include <iostream>
using namespace std;

bool NumeroPrimo(unsigned);

int main() {
  int  n;
  bool primo;

  do {
    cout << "Inserire un numero intero positivo: ";
    cin >> n;
  } while (n <= 0);

  primo = NumeroPrimo((unsigned)n);

  cout << n << (primo ? " è " : " non è ") << "primo" << endl;
}

bool NumeroPrimo(unsigned n) {
  unsigned i;

  if (n < 2)
    return false;

  for (i = 2; i < n / 2; i++) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}
