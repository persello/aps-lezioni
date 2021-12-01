#include "Orario.hpp"

#include <iostream>
using namespace std;

int main() {
  // Crea un orario senza parametri
  cout << "Creazione orario senza parametri (ora attuale)" << endl;
  Orario orario1;

  // Stampa l'orario
  cout << orario1.Ore() << ":" << orario1.Minuti() << ":" << orario1.Secondi()
       << endl;

  // Crea un orario con 2 parametri
  cout << "Creazione orario con 2 parametri (2:30:00)" << endl;
  Orario orario2(2, 30);

  // Stampa l'orario
  cout << orario2.Ore() << ":" << orario2.Minuti() << ":" << orario2.Secondi()
       << endl;

  // Crea un orario con 3 parametri
  cout << "Creazione orario con 3 parametri (00:00:30)" << endl;
  Orario orario3(0, 0, 30);

  // Stampa l'orario
  cout << orario3.Ore() << ":" << orario3.Minuti() << ":" << orario3.Secondi()
       << endl;

  // Test di somma secondi (positivi)
  cout << "Test di somma secondi (positivi, 100 secondi)" << endl;
  orario3.SommaSecondi(100);

  // Stampa l'orario
  cout << orario3.Ore() << ":" << orario3.Minuti() << ":" << orario3.Secondi()
       << endl;

  // Test di somma secondi (negativi)
  cout << "Test di somma secondi (negativi, -600 secondi)" << endl;
  orario3.SommaSecondi(-600);

  // Stampa l'orario
  cout << orario3.Ore() << ":" << orario3.Minuti() << ":" << orario3.Secondi()
       << endl;

  // Test di somma secondi (positivi, più di un giorno)
  cout << "Test di somma secondi (positivi, 1 giorno + 10 secondi)" << endl;
  orario3.SommaSecondi(86400 + 10);

  // Stampa l'orario
  cout << orario3.Ore() << ":" << orario3.Minuti() << ":" << orario3.Secondi()
       << endl;
}
