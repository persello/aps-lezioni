#pragma once

class Orario {
public:
  Orario();
  Orario(unsigned ore, unsigned minuti, unsigned secondi = 0);

  unsigned Ore() const { return secondi / 3600; };
  unsigned Minuti() const { return (secondi % 3600) / 60; };
  unsigned Secondi() const { return secondi % 60; };

  void SommaSecondi(int s);

private:
  int            secondi;
  const unsigned SECONDI_GIORNO;
};
