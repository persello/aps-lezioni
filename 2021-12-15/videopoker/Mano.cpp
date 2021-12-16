#include "Mano.hpp"

ostream& operator<<(ostream& os, const Mano& mano) {
  os << endl;
  for (unsigned i = 0; i < mano.carte.size(); i++) {
    os << i << ": " << mano.carte[i] << endl;
  }

  os << "Punto: " << mano.NomePunto(mano.Valuta()) << endl;
}

Mano::Mano(Mazzo* mazzo) : carte(5) { mazzo_utilizzato = mazzo; }

void Mano::Distribuisci() {
  for (unsigned i = 0; i < carte.size(); i++) {
    carte[i] = mazzo_utilizzato->PescaCarta();
  }
}

void Mano::CambiaCarta(unsigned i) {
  carte[i] = mazzo_utilizzato->PescaCarta();
}

Punto Mano::Valuta() const {
  std::vector<unsigned>    conta_valori(mazzo_utilizzato->NUM_VALORI, 0);
  std::vector<unsigned>    conta_semi(mazzo_utilizzato->NUM_SEMI, 0);
  pair<unsigned, unsigned> max;
  Conta(conta_semi, conta_valori);
  max = CercaMassimi(conta_valori);

  switch (max.first) {
    case 4:
      return Punto::poker;

    case 3:
      if (max.second == 2)
        return Punto::full;
      else
        return Punto::tris;

    case 2:
      if (max.second == 2)
        return Punto::doppia;
      else
        return Punto::coppia;

    default:
      if (Scala(conta_valori))
        if (Colore(conta_semi))
          return Punto::scala_reale;
        else
          return Punto::scala;
      else if (Colore(conta_semi))
        return Punto::colore;
      else
        return Punto::niente;
  }
}

string Mano::NomePunto(Punto p) const {
  switch (p) {
    case Punto::niente:
      return "niente";
    case Punto::coppia:
      return "coppia";
    case Punto::doppia:
      return "doppia";
    case Punto::tris:
      return "tris";
    case Punto::scala:
      return "scala";
    case Punto::colore:
      return "colore";
    case Punto::full:
      return "full";
    case Punto::poker:
      return "poker";
    case Punto::scala_reale:
      return "scala reale";
  }
}

void Mano::Conta(vector<unsigned>& semi, vector<unsigned>& valori) const {
  for (unsigned i = 0; i < carte.size(); i++) {
    valori[static_cast<unsigned>(carte[i].ValoreCarta())]++;
    semi[static_cast<unsigned>(carte[i].SemeCarta())]++;
  }
}

pair<unsigned, unsigned>
Mano::CercaMassimi(const vector<unsigned>& valori) const {
  pair<unsigned, unsigned> max = make_pair(0, 0);
  for (unsigned i = 0; i < mazzo_utilizzato->NUM_VALORI; i++) {
    if (valori[i] > max.first) {
      max.second = max.first;
      max.first  = valori[i];
    } else if (valori[i] > max.second) {
      max.second = valori[i];
    }
  }
  return max;
}

bool Mano::Scala(vector<unsigned>& valori) const {
  unsigned v;
  for (v = mazzo_utilizzato->NUM_VALORI - 1; valori[v] == 0; v--)
    ;
  
}

bool Mano::Colore(vector<unsigned>& semi) const {}