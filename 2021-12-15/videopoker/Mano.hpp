#pragma once

#include "Mazzo.hpp"
#include <iostream>
#include <vector>

enum class Punto {
  niente,
  coppia,
  doppia,
  tris,
  scala,
  colore,
  full,
  poker,
  scala_reale
};

class Mano {
  friend ostream& operator<<(ostream& os, const Mano& mano);

public:
  Mano(Mazzo* mazzo);
  void   Distribuisci();
  void   CambiaCarta(unsigned i);
  Punto  Valuta() const;
  string NomePunto(Punto p) const;

private:
  std::vector<Carta> carte;
  Mazzo*             mazzo_utilizzato;

  void Conta(vector<unsigned>& semi, vector<unsigned>& valori) const;
  pair<unsigned, unsigned> CercaMassimi(const vector<unsigned>& valori) const;
  bool                     Scala(vector<unsigned>& valori) const;
  bool                     Colore(vector<unsigned>& semi) const;
}