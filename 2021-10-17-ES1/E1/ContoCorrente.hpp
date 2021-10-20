#pragma once

class ContoCorrente {
public:
  ContoCorrente();
  ContoCorrente(double tasso);

  double TassoInteresse() const { return tasso; };
  unsigned SaldoInEuro() const { return saldo / 100; };
  unsigned SaldoCentesimi() const { return saldo % 100; };
  unsigned SaldoInLire() const {
    return static_cast<double>(saldo) * CENT_LIRE;
  };
  void FissaTassoInteresse(double tasso) { this->tasso = tasso; };

  void DepositaEuro(unsigned euro, unsigned centesimi);
  void PrelevaEuro(unsigned euro, unsigned centesimi);
  void AggiornaSaldo();

private:
  unsigned saldo;
  double tasso;
  const double CENT_LIRE;
};
