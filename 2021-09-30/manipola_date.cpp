#include "manipola_date.hpp"

unsigned GiorniDelMese(unsigned mese, unsigned anno) {
  if (mese == 11 || mese == 4 || mese == 6 || mese == 9) {
    return 30;
  } else if (mese == 2) {
    if (Bisestile(anno)) {
      return 29;
    } else {
      return 28;
    }
  } else {
    return 31;
  }
}

bool Bisestile(unsigned anno) {
  return ((anno % 4 == 0) && !(anno % 100 == 0)) || (anno % 400 == 0);
}

void DataSuccessiva(unsigned& giorno, unsigned& mese, unsigned& anno) {
  if (giorno < GiorniDelMese(mese, anno)) {
    giorno++;
  } else {
    if (mese < 12) {
      giorno = 1;
      mese++;
    } else {
      giorno = 1;
      mese   = 1;
      anno++;
    }
  }
}

void DataPrecedente(unsigned& giorno, unsigned& mese, unsigned& anno) {
  if (giorno > 1) {
    giorno--;
  } else {
    if (mese > 1) {
      mese--;
      giorno = GiorniDelMese(mese, anno);
    } else {
      mese = 12;
      anno--;
      giorno = GiorniDelMese(mese, anno);
    }
  }
}