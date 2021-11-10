#include <vector>
#include <iostream>

using namespace std;

int main() {
  vector<int> v1, v2(10), v3(20, 3), v4{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // v1: vettore vuoto
  // v2: vettore di 10 elementi tutti inizializzati a 0
  // v3: vettore di 20 elementi tutti inizializzati a 3
  // v4: vettore di 10 elementi inizializzato manualmente

  // I vettori conoscono la loro lunghezza
  cout << "v1: " << v1.size() << endl;
  cout << "v2: " << v2.size() << endl;
  cout << "v3: " << v3.size() << endl;
  cout << "v4: " << v4.size() << endl;

  // Aggiunta di elementi ad un vettore
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);
  v1.pop_back();

  // Ridimensionamento di un vettore
  v1.resize(10);

  // Ridimensionamento di un vettore con valori iniziali
  v1.resize(20, 3);

  // Pulizia
  v1.clear(); // Equivale a v1.resize(0)

  // Attenzione: funziona come i vecchi vettori! (per motivi di velocità)
  // v1[100] = 3; // Errore! Potrebbe essere fuori dai limiti
  
  // Un metodo alternativo robusto
  v1.at(100) = 3; // Equivale a v1[100] = 3;

  // Cancelliamo il secondo elemento
  v1.erase(v1.begin() + 1);

  // Inseriamo un elemento
  v1.insert(v1.begin() + 1, 3);
}