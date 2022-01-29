#pragma once

#include <vector>

#include "Giocatore.hpp"
#include "Partita.hpp"

class Torneo {
public:
  /**
   * @brief Mette in programma la partita tra i giocatori `g1` e `g2`, in questo
   * ordine.
   *
   * @param g1 Primo giocatore.
   * @param g2 Secondo giocatore.
   * @attention Non deve esistere una partita in programma, in corso o terminata
   * tra i due giocatori, neanche in ordine inverso.
   */
  void AggiungiPartita(Giocatore* g1, Giocatore* g2);

  /**
   * @brief Inizia la partita tra `g1` e `g2`.
   * @details Il punteggio della partita è di 0-0 nel primo set.
   *
   * @param g1 Primo giocatore.
   * @param g2 Secondo giocatore.
   * @attention La partita è in programma, non necessariamente coi giocatori
   * nell'ordine espresso.
   */
  void IniziaPartita(Giocatore* g1, Giocatore* g2);

  /**
   * @brief Si aggiunge un punto al giocatore `g1` nel set corrente della sua
   * partita con il giocatore `g2`.
   * @details Se il punto segnato determina la vittoria della partita, questo
   * evento deve essere registrato.
   *
   * @param g1 Giocatore che ha segnato il punto.
   * @param g2 Altro giocatore.
   * @attention Deve esserci una partita in corso tra i giocatori specificati.
   */
  void SegnaPunto(Giocatore* g1, Giocatore* g2);

  /**
   * @brief Il giocatore `g1` si ritira dalla partita con `g2`.
   * @details `g2` vince la partita indipendentemente dal punteggio.
   *
   * @param g1 Giocatore che abbandona la partita.
   * @param g2 Altro giocatore.
   * @attention Deve esserci una partita in corso tra i giocatori specificati.
   */
  void AbbandonaPartita(Giocatore* g1, Giocatore* g2);

  /**
   * @brief Ottieni lo stato della partita specificata.
   *
   * @param g1 Primo giocatore.
   * @param g2 Secondo giocatore.
   * @return StatoPartita Stato della partita.
   */
  StatoPartita StatoPartita(Giocatore* g1, Giocatore* g2);

private:
  /**
   * @brief Cerca una partita.
   *
   * @param g1 Primo giocatore.
   * @param g2 Secondo giocatore.
   *
   * @return std::pair<bool, int> L'indice della partita. Il booleano è
   * true se la partita è memorizzata nell'ordine specificato, false altrimenti.
   * Se la partita non è trovata, si restituisce -1.
   */
  std::pair<bool, int> CercaPartita(Giocatore* g1, Giocatore* g2);

  std::vector<Partita> partite;
}