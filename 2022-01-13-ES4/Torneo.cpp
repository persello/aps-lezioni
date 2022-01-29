#include "Torneo.hpp"

void Torneo::AggiungiPartita(Giocatore* g1, Giocatore* g2) {
  if (CercaPartita(g1, g2).second != -1)
    throw std::logic_error(
        "Non è possibile aggiungere una partita già esistente.");

  partite.push_back(Partita(g1, g2));
}

void Torneo::IniziaPartita(Giocatore* g1, Giocatore* g2) {
  std::pair result = CercaPartita(g1, g2);

  if (result.second == -1)
    throw std::logic_error("La partita specificata per l'inizio non esiste.");

  partite[result.second].Inizia();
}

void Torneo::SegnaPunto(Giocatore* g1, Giocatore* g2) {
  std::pair result = CercaPartita(g1, g2);

  if (result.second == -1)
    throw std::logic_error("La partita specificata per il punto non esiste.");

  partite[result.second].SegnaPunto(g1);
}

