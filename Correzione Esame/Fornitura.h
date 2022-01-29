//
// Created by Riccardo Persello on 29/01/22.
//

#ifndef CORREZIONE_ESAME_FORNITURA_H
#define CORREZIONE_ESAME_FORNITURA_H

#include <ostream>
#include "Magazzino.h"
#include "Negozio.h"

/**
 * Classe che rappresenta una fornitura.
 */
class Fornitura {
public:
    friend std::ostream &operator<<(std::ostream &os, const Fornitura &fornitura) {
        os << "Fornitura:" << std::endl;
        os << "" << *(fornitura.negozio) << std::endl;
        os << "" << *(fornitura.magazzino) << std::endl;
        os << "\tquantità: " << fornitura.quantita << std::endl;
        return os;
    }

public:
    /**
     * Costruttore della classe Fornitura.
     * @param negozio Il ricevente della fornitura.
     * @param magazzino Il fornitore.
     * @param quantita Dimensione della fornitura.
     */
    Fornitura(const Negozio *negozio, const Magazzino *magazzino, int quantita) {
        this->negozio = negozio;
        this->magazzino = magazzino;
        this->quantita = quantita;
    }

    /**
     * Il ricevente della fornitura.
     */
    const Negozio *negozio;

    /**
     * Il fornitore.
     */
    const Magazzino *magazzino;

    /**
     * Dimensione della fornitura.
     */
    int quantita;
};

#endif //CORREZIONE_ESAME_FORNITURA_H
