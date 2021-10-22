#include "date.hpp"
#include <iostream>

using namespace std;

int main() {
  unsigned g, m, a;
  cout << "Inserire data (g m a): ";
  cin >> g >> m >> a;

  Date d(g, m, a);

  cout << "Data inserita: " << d.Day() << "/" << d.Month() << "/" << d.Year()
       << endl;

  ++d;

  cout << "Data successiva: " << d.Day() << "/" << d.Month() << "/" << d.Year()
       << endl;

  --d;
  --d;

  cout << "Data precedente: " << d.Day() << "/" << d.Month() << "/" << d.Year()
       << endl;

  ++d;
  d += 10;

  cout << "Data successiva di 10 giorni: " << d.Day() << "/" << d.Month() << "/"
       << d.Year() << endl;

  d += -10;
  Date d2 = d + 10;

  cout << "Nuova data: " << d2.Day() << "/"
       << d2.Month() << "/" << d2.Year() << endl;

  cout << "d e d2 " << (d == d2 ? "" : "non ") << "sono uguali" << endl;

  cout << "Sottraggo 10 giorni a d2." << endl;
  
  d2 += -10;

  cout << "d e d2 " << (d == d2 ? "" : "non ") << "sono uguali" << endl;
}
