//
// Created by Riccardo Persello on 29/01/22.
//

#ifndef CORREZIONE_ESAME_AZIENDA_H
#define CORREZIONE_ESAME_AZIENDA_H

#include <vector>
#include <cmath>
#include <ostream>
#include "Negozio.h"
#include "Magazzino.h"
#include "Fornitura.h"

class Azienda {
public:
    friend std::ostream &operator<<(std::ostream &os, const Azienda &azienda);

public:

    /**
     * Il magazzino m viene inserito tra quelli disponibili per l'azienda.
     * Se il magazzino è già presente, l'operazione non ha effetti.
     *
     * @param m Il magazzino da aggiungere.
     */
    void InserisciMagazzino(const Magazzino *m);

    /**
     * Il negozio n viene inserito tra quelli disponibili per l'azienda.
     * Se il negozio è già presente, l'operazione non ha effetti.
     *
     * @param n Il negozio da aggiungere.
     */
    void InserisciNegozio(const Negozio *n);

    /**
     * Il magazzino m viene chiuso.
     *
     * @throws invalid_argument Se non sono rispettate le precondizioni.
     * Il magazzino m deve essere tra quelli disponibili per l'azienda.
     * Nessuna fornitura dell'azienda deve partire da m.
     *
     * @param m Il magazzino da chiudere.
     */
    void ChiudiMagazzino(Magazzino *m) const;

    /**
     * La quantità q di beni viene assegnata alla fornitura dal magazzino m al negozio n.
     * Se c'è già una fornitura da m ad n, la quantità q viene aggiunta, altrimenti si crea una nuova fornitura.
     *
     * @throws invalid_argument Se non sono rispettate le precondizioni.
     * Sia il magazzino m che il negozio n devono essere tra quelli disponibili per l'azienda.
     * Il magazzino m deve essere aperto.
     * Sia la richiesta residua di n e la capacità residua di m sono maggiori o uguali a q.
     * Con richiesta (risp. capacità) residua si intende la richiesta (risp. capacità) meno tutte le forniture
     * già assegnate per quel negozio (risp. magazzino).
     *
     * @param m Il magazzino fornitore.
     * @param n Il negozio destinatario.
     * @param q Dimensione della fornitura.
     */
    void AssegnaFornitura(const Magazzino *m, const Negozio *n, int q);

    /**
     * La richiesta residua di n viene assegnata al magazzino compatibile aperto più vicino
     * (usando la distanza euclidea) che abbia capacità residua sufficiente.
     * Se non esiste alcun magazzino in tali condizioni, l'operazione non ha effetto.
     *
     * @throws invalid_argument Se non sono rispettate le precondizioni.
     * Il negozio n deve essere tra quelli disponibili per l'azienda.
     * La sua richiesta residua deve essere maggiore di 0.
     *
     * @param n Negozio da riempire.
     * @return true se l'operazione è andata a buon fine, false altrimenti.
     */
    bool AssegnaResiduo(const Negozio *n);

    /**
     * Selettore magazzini.
     *
     * @return I magazzini dell'azienda.
     */
    [[nodiscard]] const std::vector<const Magazzino *> &Magazzini() const;

    /**
     * Selettore negozi.
     *
     * @return I negozi dell'azienda.
     */
    [[nodiscard]] const std::vector<const Negozio *> &Negozi() const;

    /**
     * Selettore forniture.
     *
     * @return Le forniture dell'azienda.
     */
    [[nodiscard]] const std::vector<Fornitura> &Forniture() const;

private:
    std::vector<const Magazzino *> magazzini;
    std::vector<const Negozio *> negozi;
    std::vector<Fornitura> forniture;

    /**
     * Trova il magazzino specificato.
     *
     * @param m Magazzino da cercare.
     * @return -1 se non è presente, altrimenti l'indice del magazzino.
     */
    int TrovaMagazzino(const Magazzino *m) const;

    /**
     * Trova il negozio specificato.
     *
     * @param n Negozio da cercare.
     * @return -1 se non è presente, altrimenti l'indice del negozio.
     */
    int TrovaNegozio(const Negozio *n) const;

    /**
     * Trova la fornitura specificata.
     *
     * @param m Magazzino fornitore.
     * @param n Negozio destinatario.
     * @return -1 se non è presente, altrimenti l'indice della fornitura.
     */
    int TrovaFornitura(const Magazzino *m, const Negozio *n) const;

    /**
     * Trova tutte le forniture che arrivano in un dato negozio.
     *
     * @param n Negozio di cui cercare le forniture.
     * @return Un vettore di forniture.
     */
    std::vector<Fornitura> TrovaForniture(const Negozio *n) const;

    /**
     * Trova tutte le forniture che partono da un dato magazzino.
     * @param m Magazzino di cui cercare le forniture.
     * @return Un vettore di forniture.
     */
    std::vector<Fornitura> TrovaForniture(const Magazzino *m) const;

    /**
     * Calcola la richiesta residua di un negozio.
     *
     * @param n Negozio di cui calcolare la richiesta residua.
     * @return La richiesta residua.
     */
    int RichiestaResidua(const Negozio *n) const;

    /**
     * Calcola la capacità residua di un magazzino.
     * @param m Magazzino di cui calcolare la capacità residua.
     * @return La capacità residua.
     */
    int CapacitaResidua(const Magazzino *m) const;
};

double Distanza(const Magazzino *m, const Negozio *n);

#endif //CORREZIONE_ESAME_AZIENDA_H
