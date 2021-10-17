#include "ContoCorrente.hpp"
#include <cmath>
#include <iostream>

ContoCorrente::ContoCorrente() : CENT_LIRE(19.3627) {
  saldo = 0;
  tasso = 0;
}

ContoCorrente::ContoCorrente(double tasso) : CENT_LIRE(19.3627) {
  saldo = 0;
  this->tasso = tasso;
}

void ContoCorrente::DepositaEuro(unsigned euro, unsigned centesimi) {
  saldo += centesimi + (euro * 100);
}

void ContoCorrente::PrelevaEuro(unsigned euro, unsigned centesimi) {
  unsigned prelievo = centesimi + (euro * 100);
  if (prelievo > saldo) {
    std::cout << "Saldo insufficiente." << std::endl << std::endl;
  } else {
    saldo -= prelievo;
  }
}

void ContoCorrente::AggiornaSaldo() { saldo = saldo + round(saldo * tasso); }
