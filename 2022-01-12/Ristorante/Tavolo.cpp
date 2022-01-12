#include "Tavolo.hpp"
#include <stdexcept>

Tavolo::Tavolo(unsigned posti) : capienza(posti) {}

bool Tavolo::Presente(Persona* p) const {
  for (unsigned i = 0; i < seduti.size(); ++i)
    if (seduti[i] == p)
      return true;
  return false;
}

void Tavolo::Libera() { seduti.clear(); }

void Tavolo::CambiaCapienza(unsigned capienza) {
  if (seduti.size() > 0) {
    throw std::logic_error(
        "Non puoi cambiare la capienza se ci sono clienti seduti.");
  }
  this->capienza = capienza;
}

void Tavolo::AggiungiPersona(Persona* p) {
    if (seduti.size() == capienza) {
        throw std::logic_error("Tavolo pieno.");
    }
    seduti.push_back(p);
}