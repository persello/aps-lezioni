#pragma once

#include "Giocatore.hpp"

/**
 * @brief Rappresenta lo stato di una partita di squash.
 *
 */
enum StatoPartita {
  /**
   * @brief Il giocatore 1 ha vinto.
   *
   */
  Vinto1,
  /**
   * @brief Il giocatore 2 ha vinto.
   *
   */
  Vinto2,
  /**
   * @brief La partita è in corso.
   *
   */
  InCorso,
  /**
   * @brief La partita è in programma.
   *
   */
  InProgramma,
  /**
   * @brief Nessuna delle altre opzioni.
   *
   */
  Inesistente
}

/**
 * @brief Rappresenta una partita di squash.
 *
 */
class Partita {
public:
  /**
   * @brief Crea una nuova partita coi giocatori specificati.
   *
   * @param g1 Primo giocatore.
   * @param g2 Secondo giocatore.
   */
  Partita(Giocatore* g1, Giocatore* g2);

  /**
   * @brief Segna un punto.
   *
   * @param g Il giocatore che ha segnato.
   * @attention La partita deve essere in corso.
   */
  void SegnaPunto(Giocatore* g);

  /**
   * @brief Ottiene lo stato della partita.
   *
   * @return StatoPartita Stato della partita.
   */
  StatoPartita Stato() const;

  /**
   * @brief La partita inizia.
   * @attention La partita deve essere in programma.
   */
  void Inizia();

  /**
   * @brief Un giocatore ha abbandonato la partita, facendo vincere l'altro.
   *
   * @param g Il giocatore che ha abbandonato la partita.
   * @attention La partita deve essere in corso.
   */
  void Abbandona(Giocatore* g);

private:
  void SegnaSet(Giocatore* g);

  Giocatore*                    g1;
  Giocatore*                    g2;
  StatoPartita                  stato;
  std::pair<unsigned, unsigned> set;
  std::pair<unsigned, unsigned> punti;
};