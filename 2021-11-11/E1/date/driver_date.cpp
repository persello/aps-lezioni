#include "date.hpp"
#include <iostream>

using namespace std;

int main() {
  Date d;
  cout << "Inserire data (g/m/a): ";
  cin >> d;

  cout << "Data inserita: " << d << endl;

  ++d;

  cout << "Data successiva: " << d << endl;

  --d;
  --d;

  cout << "Data precedente: " << d << endl;

  ++d;
  d += 10;

  cout << "Data successiva di 10 giorni: " << d << endl;

  d += -10;
  Date d2 = d + 10;

  cout << "Nuova data: " << d << endl;

  cout << "d e d2 " << (d == d2 ? "" : "non ") << "sono uguali" << endl;

  cout << "Sottraggo 10 giorni a d2." << endl;

  d2 += -10;

  cout << "d e d2 " << (d == d2 ? "" : "non ") << "sono uguali" << endl;
}
