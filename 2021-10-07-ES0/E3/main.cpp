#include <iostream>

#include "manipola_date.hpp"

using namespace std;

int main() {
  unsigned giorno, mese, anno;

  do {
    cout << "Inserire una data (gg mm aaaa): ";
    cin >> giorno >> mese >> anno;
  } while (!DataValida(giorno, mese, anno));

  DataPrecedente(giorno, mese, anno);

  cout << "La data precedente è " << giorno << "/" << mese << "/" << anno << "."
       << endl;
}
