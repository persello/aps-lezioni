#include <assert.h>
#include <iostream>

#include "Poli.hpp"

using namespace std;

int main() {
  // ---------- POLINOMIO CON 0 PARAMETRI ----------
  cout << "Test polinomio con 0 parametri: ";

  Poli poli_0;

  cout << poli_0 << endl;

  // ---------- POLINOMIO CON 2 PARAMETRI ----------
  cout << "Test polinomio con 2 parametri. Inserire grado e coefficiente [deg "
          "coeff]: ";
  int deg;
  double coeff;

  cin >> deg >> coeff;

  Poli poli_1(coeff, deg);

  cout << poli_1 << endl;

  cout << "Valutazione del polinomio in [-10, 10]:" << endl;
  for (int i = -10; i <= 10; i++) {
    cout << "(" << i << ", " << poli_1((double)i) << ")" << endl;
  }

  // ---------- SOMMA CON POLINOMIO NULLO ----------
  cout << "Sommo il polinomio inserito con quello nullo:" << endl;
  cout << poli_0 << " + " << poli_1 << " = " << poli_0 + poli_1 << endl;

  // ---------- TEST ISTREAM ----------
  cout << "Inserire un polinomio nel formato di istream: ";
  Poli poli_2;
  cin >> poli_2;

  cout << "Polinomio letto: " << poli_2 << endl;

  // ---------- SOMMA CON POLINOMIO 2 PARAMETRI ----------
  cout << "Sommo il polinomio inserito con quello con 2 parametri:" << endl;
  cout << poli_1 << " + " << poli_2 << " = " << poli_1 + poli_2 << endl;

  // ---------- CONTROLLI DI INTERFERENZA ----------
  cout << "Controllo di interferenza: " << endl;

  Poli poli_3(1, 1);

  cout << "Polinomio 3: " << poli_3 << endl;

  Poli poli_4 = poli_3;

  cout << "Polinomio 4 (copia di 3): " << poli_4 << endl;

  poli_3[1] = 2;

  cout << "Polinomio 3 (modificato): " << poli_3 << endl;
  cout << "Polinomio 4 (non deve subire modifiche): " << poli_4 << endl;


}
