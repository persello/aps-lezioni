#include <iostream>

using namespace std;

int *LeggiVettore(unsigned n) {
  int *q;
  unsigned i;

  q = new int[n];
  cout << "Inserisci " << n << " interi: ";

  for (i = 0; i < n; i++) {
    cin >> q[i];
  }

  return q;
}

int main() {
  int *p;
  unsigned n, i;

  cout << "Inserisci la lunghezza del vettore: ";
  cin >> n;

  p = LeggiVettore(n);

  for (i = 0; i < n; i++) {
    cout << p[i] << " ";
  }

  cout << endl;

  delete[] p;
  return 0;
}