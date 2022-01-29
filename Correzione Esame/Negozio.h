//
// Created by Riccardo Persello on 29/01/22.
//

#ifndef CORREZIONE_ESAME_NEGOZIO_H
#define CORREZIONE_ESAME_NEGOZIO_H


#include <vector>
#include <ostream>
#include "Magazzino.h"

class Negozio {
    friend std::ostream &operator<<(std::ostream &os, const Negozio &negozio);

public:

    /**
     * Costruttore di default.
     *
     * @param r Richiesta del negozio.
     * @param x Posizione X del negozio.
     * @param y Posizione Y del negozio.
     * @param i Vettore di puntatori ai magazzini incompatibili.
     */
    Negozio(int r, double x, double y, const std::vector<const Magazzino *> &i);

    /**
     * Selettore richiesta.
     *
     * @return La richiesta del negozio.
     */
    [[nodiscard]] int Richiesta() const;

    /**
     * Selettore posizione X.
     *
     * @return La posizione X del negozio.
     */
    [[nodiscard]] double X() const;

    /**
     * Selettore posizione Y.
     *
     * @return La posizione Y del negozio.
     */
    [[nodiscard]] double Y() const;

    /**
     * Numero di magazzini incompatibili.
     *
     * @return Il numero di magazzini incompatibili.
     */
    [[nodiscard]] int Incompatibili() const;

    /**
     * Trova un magazzino incompatibile.
     *
     * @param i Indice del magazzino.
     * @return Puntatore all'i-esimo magazzino incompatibile.
     */
    [[nodiscard]] const Magazzino *Incompatibile(int i) const;

    /**
     * Verifica la compatibilità con un magazzino.
     *
     * @param m Magazzino da verificare.
     * @return true se il magazzino è compatibile, false altrimenti.
     */
    bool EstCompatibile(const Magazzino *m) const;

private:
    int richiesta;
    double x;
    double y;
    std::vector<const Magazzino *> incompatibili;
};


#endif //CORREZIONE_ESAME_NEGOZIO_H
