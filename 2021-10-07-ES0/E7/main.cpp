#include <iostream>
using namespace std;

const LENGTH 100;

int main() {
  char input[LENGTH];

  cout << "Inserire un numero romano [IVXLCDM]: ";
  cin >> input;

  cout << RomanoDecimale(input, LENGTH);
}

unsigned ValoreLettera(char l) {
  switch (l) {
    case 'I':
      return 1;
    case 'V':
      return 5;
    case 'X':
      return 10;
    case 'L':
      return 50;
    case 'C':
      return 100;
    case 'D':
      return 500;
    case 'M':
      return 1000;
    default:
      return -1;
  }
}

bool RomanoValido(char romano[], int n) {
  for (int i = 0; i < n; i++) {
    if (ValoreLettera(romano[i]) == -1) {
      return false;
    }
  }

  return true;
}

unsigned RomanoDecimale(char romano[], int n) {
  unsigned length = strlen(romano);
  unsigned romano_grezzo[length];
  unsigned result = 0;

  if (!RomanoValido(romano, length)) {
    return -1;
  }

  // Converti array di caratteri in array di numeri
  for (int i = 0; i < length; i++) {
    romano_grezzo[i] = ValoreLettera(romano[i]);
  }

  // Calcola sottrazioni e risultato
  for (int i = 0; i < length; i++) {
  }
}