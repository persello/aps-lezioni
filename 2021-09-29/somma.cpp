/* Questo programma stampa la somma di 10 numeri letti da tastiera. */

#include <iostream>
const int NUMERI = 10;

using namespace std;

int main() {
  int numero, somma = 0;
  unsigned i;

  // printf("Inserisci %d numeri interi: ", NUMERI);
  cout << "Inserisci " << NUMERI << " numeri interi: ";

  for (i = 0; i < NUMERI; i++) {
    
    // scanf("%d", &numero);
    cin >> numero;
    somma += numero;
  }

  // endl svuota il buffer nell'istante in cui viene eseguito.
  cout << "La somma vale " << somma << endl;

  return 0;
}
