#include <iostream>
using namespace std;

void AllicazioneStatica() {
  // Allocazione statica, v è un vettore statico (la dimensione è nota a tempo
  // di compilazione). Non si può usare una variabile come dimensione di un
  // vettore (in C99 sì). Il record di attivazione di questa funzione va nello
  // stack.
  int v[20];
}

void AllocazioneDinamica() {
  int  n;
  int* p;

  cout << "Dimensione array: ";
  cin >> n;

  // La keyword `new` fa la stessa cosa di `malloc`, alloca nell'heap n interi.
  // Il puntatore p punterà allo spazio allocato nell'heap.
  // Il puntatore p si trova nello stack.
  p = new int[n];

  // Ora la memoria precedentemente utilizzata non è più puntata.
  // Gli n interi allocati precedentemente sono persi ma continuano ad occupare
  // memoria.
  p = new int[1000];

  // Per restituire la zona di memoria puntata da p si usa `delete`.
  delete[] p;

  // Ora abbiamo restituito quanto allocato col secondo new. Quanto allocato col
  // primo è memoria sprecata ed irraggiungibile.

  // In C++ non esiste il `realloc`.
}

int main() {
  AllocazioneStatica();
  AllocazioneDinamica();
}
