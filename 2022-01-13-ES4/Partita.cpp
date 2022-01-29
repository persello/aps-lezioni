#include "Partita.hpp"

Partita::Partita(Giocatore* g1, Giocatore* g2)
    : g1(g1), g2(g2), punti(std::make_pair(0, 0)), set(std::make_pair(0, 0)) {
  this->stato = StatoPartita::InProgramma;
}

void Partita::SegnaPunto(Giocatore* g) {

  // Controlla lo stato della partita.
  if (stato != StatoPartita::InCorso)
    throw(std::logic_error(
        "Non è possibile segnare un punto se la partita non è in corso."));

  // Assegna i punti.
  if (g == g1) {
    (punti.first)++;
  } else if (g == g2) {
    (punti.second)++;
  } else {
    throw std::logic_error("Il giocatore che ha segnato il punto non è "
                           "presente in questa partita.");
  }

  // Aggiorna lo stato della partita.
  if ((abs(static_cast<long>(punti.first) - static_cast<long>(punti.second)) >=
       2) &&
      (punti.first >= 15 || punti.second >= 15)) {

    // Se abbiamo le condizioni per cui uno dei due partecipandi vince...

    if (punti.first > punti.second) {
      SegnaSet(g1);
    } else {
      SegnaSet(g2);
    }

    punti.first  = 0;
    punti.second = 0;
  }
}

StatoPartita Partita::Stato() const { return stato; }

void Partita::Inizia() {
  if (stato != StatoPartita::InProgramma)
    throw std::logic_error(
        "Non è possibile iniziare una partita che non sia in programma.");

  stato = StatoPartita::InCorso;
}

void Partita::Abbandona(Giocatore* g) {
  if (stato != StatoPartita::InCorso)
    throw std::logic_error(
        "Non è possibile abbandonare una partita che non è in corso.");

  if (g == g1) {
    stato = StatoPartita::Vinto2;
  } else if (g == g1) {
    stato = StatoPartita::Vinto1;
  } else {
    throw std::logic_error(
        "Il giocatore che vuole abbandonare non è presente in questa partita.");
  }
}

void Partita::SegnaSet(Giocatore* g) {
  if (stato != StatoPartita::InCorso)
    throw std::logic_error(
        "Non è possibile segnare un set se la partita non è in corso.");

  // Assegna i punti.
  if (g == g1) {
    set.first++;
  } else if (g == g1) {
    set.second++;
  } else {
    throw std::logic_error("Il giocatore che vuole ha segnato il set non è "
                           "presente in questa partita.");
  }

  // Aggiorna lo stato della partita.
  if (set.first >= 2)
    stato = StatoPartita::Vinto1;
  else if (set.second >= 2)
    stato = StatoPartita::Vinto2;
}