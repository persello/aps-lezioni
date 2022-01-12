#pragma once

#include "Persona.hpp"

class Tavolo {
public:
  Tavolo(unsigned posti = 4);
  unsigned NumPosti() const { return capienza; }
  unsigned NumSeduti() const { return seduti.size(); }
  bool     Presente(Persona*) const;
  void     AggiungiPersona(Persona*);
  void     Libera();
  void     CambiaCapienza(unsigned);
  Persona* Occupante(unsigned i) const { return seduti[i]; }

private:
  std::vector<Persona*> seduti;
  unsigned              capienza;
};