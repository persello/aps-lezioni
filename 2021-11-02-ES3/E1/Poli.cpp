#include "Poli.hpp"

#include <cmath>

// Costruttori
Poli::Poli() {
  size = 0;
  vec = nullptr;
}

Poli::Poli(const Poli &p) {

  if (p.size == 0) {
    size = 0;
    vec = nullptr;
    return;
  }

  // Vado all'indietro così da fare soltanto una singola allocazione.
  for (int i = p.size - 1; i >= 0; i--) {
    this->operator[](i) = p[i];
  }
}

Poli::Poli(double coeff, int deg) { this->operator[](deg) = coeff; }

Poli::~Poli() {
  if (vec != nullptr) {
    delete[] vec;
    vec = nullptr;
  }
}

// Operatori
double Poli::operator[](int deg) const {
  if (deg < size) {
    return vec[deg];
  }

  return 0;
}

double &Poli::operator[](int deg) {
  if (deg >= size) {
    // Vettore ausiliario per nuovi coefficienti.
    int newSize = deg + 1;
    double *aux = new double[newSize];

    // Riempie il vettore coi vecchi coefficienti (o zero altrove).
    // Non è necessario controllare gli indici: per gradi superiori al massimo
    // si ottiene zero.
    for (int i = 0; i < deg; i++) {
      aux[i] = this->operator[](i);
    }

    // Assegno il vettore al polinomio.
    if (size > 0) {
      delete[] vec;
    }
    size = newSize;
    vec = aux;
  }

  return vec[deg];
}

Poli &Poli::operator=(const Poli &p) {

  // Sfrutto l'operatore precedente. Vado all'indietro così da causare una
  // singola allocazione.
  for (int i = p.size - 1; i >= 0; i++) {
    this->operator[](i) = p[i];
  }

  return *this;
}

double Poli::operator()(double x) const {
  double result = 0;
  for (int i = 0; i < size; i++) {
    double coeff = vec[i];
    result += coeff * pow(x, (double)i);
  }

  return result;
}

// Operatori friend
Poli operator+(const Poli &a, const Poli &b) {
  Poli result;
  int size = max(a.size, b.size);
  for (int i = size - 1; i >= 0; i--) {
    result[i] = a[i] + b[i];
  }

  return result;
}

Poli operator-(const Poli &a, const Poli &b) {
  Poli result;
  int size = max(a.size, b.size);
  for (int i = size - 1; i >= 0; i--) {
    result[i] = a[i] - b[i];
  }

  return result;
}

ostream &operator<<(ostream &os, const Poli &p) {

  // Caso speciale: se abbiamo un polinomio nullo,
  // mostriamo il termine di grado zero.
  if (p.ZeroUnderDeg(p.size)) {
    os << "<0x^0>";
    return os;
  }

  // Imposta 3 cifre significative.
  os.precision(3);

  os << "<";

  for (int i = p.size - 1; i >= 0; i--) {
    if (p[i] == 0)
      continue;

    os << p[i] << "x^" << i;

    if (!p.ZeroUnderDeg(i)) {
      os << " + ";
    }
  }

  os << ">";
  return os;
}

istream &operator>>(istream &is, Poli &p) {
  char c;
  double coeff;
  int exp;

  // Leggi fino a '<'.
  do {
    is >> c;
  } while (c != '<');

  // Controlla la presenza di un coefficiente reale.
  while (true) {

    // ATTENZIONE: BUG DI libc++/LLVM: un double immediatamente seguito da una
    // 'x' non viene letto. https://bugs.llvm.org//show_bug.cgi?id=17782.

    // Strategia di conversione alternativa
    char double_string[100];
    is.getline(double_string, 100, 'x');

    if (strlen(double_string) <= 1) {
      break;
    }

    is.putback('x');

    // Converto la stringa in un double.
    coeff = atof(double_string);

    // Controlla la presenza dei caratteri 'x' e '^'.
    is >> c;
    if (c != 'x')
      break;
    is >> c;
    if (c != '^')
      break;

    // Leggi l'esponente.
    if (is >> exp) {
      // Se è presente, carica nel polinomio.
      p[exp] = coeff;
    } else {
      // Se è assente, esci dal ciclo.
      break;
    }

    // Prova a leggere un '+' oppure '>'.
    do {
      is >> c;
      if (c == '>')
        break;
    } while (c != '+');
  }

  return is;
}

// Funzioni private
bool Poli::ZeroUnderDeg(int deg) const {
  for (int i = deg - 1; i >= 0; i--) {
    if (this->operator[](i) != 0) {
      return false;
    }
  }

  return true;
}
