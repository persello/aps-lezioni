#pragma once

#include <iostream>
#include <string>

/**
 * @brief Rappresenta un giocatore di squash.
 * 
 */
class Giocatore {
  friend ostream& operator<<(ostream& os, Giocatore* g) { os << g.nome; }

public:

  /**
   * @brief Crea un nuovo oggetto Giocatore.
   * 
   * @param nome Nome del nuovo giocatore.
   */
  Giocatore(std::string nome) { this->nome = nome; }

  /**
   * @brief Getter del nome del giocatore.
   * 
   * @return std::string Nome.
   */
  std::string Nome() const { return nome; }

private:
  std::string nome;
};