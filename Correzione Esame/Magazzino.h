//
// Created by Riccardo Persello on 29/01/22.
//

#ifndef CORREZIONE_ESAME_MAGAZZINO_H
#define CORREZIONE_ESAME_MAGAZZINO_H


#include <ostream>

class Magazzino {
    friend std::ostream &operator<<(std::ostream &os, const Magazzino &magazzino);

public:

    /**
     * Costruttore di default.
     *
     * @param c Capacità del magazzino.
     * @param a Apertura del magazzino.
     * @param x Posizione X del magazzino.
     * @param y Posizione Y del magazzino.
     */
    Magazzino(int c, bool a, double x, double y);

    /**
     * Selettore capacità.
     *
     * @return La capacità del magazzino.
     */
    [[nodiscard]] int Capacita() const;

    /**
     * Selettore apertura.
     *
     * @return L'apertura del magazzino.
     */
    [[nodiscard]] bool Aperto() const;

    /**
     * Selettore posizione X.
     *
     * @return La posizione X del magazzino.
     */
    [[nodiscard]] double X() const;

    /**
     * Selettore posizione Y.
     *
     * @return La posizione Y del magazzino.
     */
    [[nodiscard]] double Y() const;

    /**
     * Apre il magazzino.
     */
    void Apri();

    /**
     * Chiude il magazzino.
     */
    void Chiudi();

private:
    int capacita;
    bool aperto;
    double x;
    double y;
};


#endif //CORREZIONE_ESAME_MAGAZZINO_H
