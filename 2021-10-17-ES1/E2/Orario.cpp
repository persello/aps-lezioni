#include "Orario.hpp"
#include <ctime>

Orario::Orario() : SECONDI_GIORNO(86400) {
  time_t t = time(0);
  secondi = t % SECONDI_GIORNO;
}

Orario::Orario(unsigned ore, unsigned minuti, unsigned secondi)
    : SECONDI_GIORNO(86400) {
  this->secondi = ore * 3600 + minuti * 60 + secondi;
}

void Orario::SommaSecondi(int s) {
  // Mantieni i secondi normalizzati in [0, SECONDI_GIORNO).
  secondi += s;
  if (secondi > 0) {
    secondi %= SECONDI_GIORNO;
  } else {
    secondi = SECONDI_GIORNO - (-secondi % SECONDI_GIORNO);
  }
}
