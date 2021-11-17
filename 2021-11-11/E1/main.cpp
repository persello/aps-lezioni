#include "person/person.hpp"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

pair<unsigned, unsigned> CalcolaMeseFrequente(string filename);
pair<string, unsigned> CalcolaNomeFrequente(string filename);
vector<Person> LeggiPersone(string filename);

int main(int argc, char *argv[]) {
  string filename;

  if (argc != 2) {
    throw invalid_argument("Wrong number of arguments.");
  }

  filename = argv[1];

  // Frequenza mese
  unsigned mese, frequenza;
  tie(mese, frequenza) = CalcolaMeseFrequente(filename);
  cout << "Il mese più frequente è " << mese << " con " << frequenza
       << " volte." << endl;

  // Frequenza nomi
  string nome;
  tie(nome, frequenza) = CalcolaNomeFrequente(filename);
  cout << "Il nome più frequente è " << nome << " con " << frequenza
       << " volte." << endl;

  // Vettore di persone
  vector<Person> persone = LeggiPersone(filename);
  cout << persone.size() << " persone caricate." << endl;

  sort(persone.begin(), persone.end());

  for (unsigned i = 0; i < persone.size(); i++) {
    cout << persone[i] << endl;
  }
}

vector<Person> LeggiPersone(string filename) {
  vector<Person> persone;
  Person persona;
  ifstream file(filename);

  while (file >> persona) {
    persone.push_back(persona);
  }

  return persone;
}

pair<unsigned, unsigned> CalcolaMeseFrequente(string filename) {
  Person persona;
  vector<unsigned> occorrenze(12, 0);
  ifstream file(filename);
  unsigned maxIndex = 0;

  while (file >> persona) {
    unsigned month = persona.BirthDate().Month() - 1;
    occorrenze[month]++;
    if (occorrenze[month] > occorrenze[maxIndex]) {
      maxIndex = month;
    }
  }

  return make_pair(maxIndex + 1, occorrenze[maxIndex]);
}

pair<string, unsigned> CalcolaNomeFrequente(string filename) {
  Person persona;
  ifstream file(filename);
  vector<pair<string, unsigned>> occorrenze;
  bool trovato;
  unsigned maxIndex = 0;

  while (file >> persona) {
    trovato = false;
    for (unsigned i = 0; i < occorrenze.size(); i++) {
      if (occorrenze[i].first == persona.Name()) {
        occorrenze[i].second++;
        trovato = true;
        break;
      }
    }

    if (!trovato) {
      occorrenze.push_back(make_pair(persona.Name(), 1));
    }
  }

  for (unsigned i = 0; i < occorrenze.size(); i++) {
    if (occorrenze[i].second > occorrenze[maxIndex].second) {
      maxIndex = i;
    }
  }

  return occorrenze[maxIndex];
}
