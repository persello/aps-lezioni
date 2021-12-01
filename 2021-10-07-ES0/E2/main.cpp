#include <iostream>
using namespace std;

void     StampaPiramide(unsigned);
unsigned LarghezzaRiga(unsigned);

int main() {

  int n;

  do {
    cout << "Inserire altezza piramide (tra 1 e 9): ";
    cin >> n;
  } while (n < 1 || n > 9);

  StampaPiramide(n);
}

// Calcola la larghezza della riga (visibile).
// Le righe cominciano dall'indice 1.
unsigned LarghezzaRiga(unsigned riga) { return 2 * (riga - 1) + 1; }

void StampaPiramide(unsigned altezza) {
  // Calcolo la larghezza massima di una riga (ultima).
  const unsigned larghezza_massima = LarghezzaRiga(altezza);

  // Serve per calcolare la distanza dal centro
  const unsigned centro_riga = altezza - 1;

  // Indici
  unsigned riga;
  unsigned colonna;

  for (riga = 1; riga <= altezza; riga++) {

    // Calcolo la larghezza visibile di ogni riga
    unsigned larghezza_riga = LarghezzaRiga(riga);

    for (colonna = 0; colonna < larghezza_massima; colonna++) {

      // Distanza dal centro riga (il centro ha distanza 0)
      unsigned distanza = abs((int)colonna - (int)centro_riga);
      if (distanza > larghezza_riga / 2) {
        // Fuori dalla piramide si usano gli spazi
        cout << " ";
      } else {
        // All'interno si stampa il duale della distanza più 1 (il bordo deve
        // mostrare 1, non 0)
        cout << (larghezza_riga / 2 - distanza) + 1;
      }
    }

    cout << endl;
  }
}
