#include "manipola_date.hpp"
#include <iostream>

using namespace std;

int main() {
  unsigned giorno, mese, anno;
  cout << "Inserire data (gg mm aaaa): ";
  cin >> giorno >> mese >> anno;

  cout << (DataValida(giorno, mese, anno) ? "Valida" : "Non valida") << endl;
  DataPrecedente(giorno, mese, anno);
  cout << "La data precedente è " << giorno << "/" << mese << "/" << anno
       << endl;
}

bool DataValida(unsigned giorno, unsigned mese, unsigned anno) {
  return anno >= 1 && mese >= 1 && mese <= 12 && giorno >= 1 &&
         giorno <= GiorniDelMese(mese, anno);
}
