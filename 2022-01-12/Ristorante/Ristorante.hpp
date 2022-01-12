#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Persona.hpp"
#include "Tavolo.hpp"

class Ristorante {
  friend std::ostream& operator<<(std::ostream& os, const Ristorante& r);

public:
  Ristorante(std::string n, unsigned t);
  void        AggiungiPersona(Persona* p, unsigned i);
  void        LiberaTavolo(unsigned i);
  void        ModificaTavolo(unsigned i, unsigned d);
  unsigned    NumTavoli() const { return tavoli.size(); }
  std::string Nome() const { return nome; }
  unsigned    PostiTavolo(unsigned i) const { return tavoli[i].NumPosti(); }
  unsigned    SedutiTavolo(unsigned i) const { return tavoli[i].NumSeduti(); }

private:
  bool                PersonaPresente(Persona* p);
  std::vector<Tavolo> tavoli;
  std::string         nome;
};