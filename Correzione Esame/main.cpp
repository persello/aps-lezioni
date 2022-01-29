#include <iostream>
#include "Azienda.h"
#include "OutputTemplates.h"

/**
 * Trova tutti i negozi per i quali non vi sono magazzini aperti e compatibili in un determinato raggio.
 *
 * @param a L'azienda da considerare.
 * @param d La distanza massima.
 * @return Lista di negozi senza magazzini vicini.
 */
std::vector<const Negozio> NessunMagazzino(const Azienda &a, double d) {
    std::vector<const Negozio> result;
    for (const Negozio *negozio: a.Negozi()) {
        bool trovato = false;
        for (const Magazzino *magazzino: a.Magazzini()) {
            if (magazzino->Aperto() && Distanza(magazzino, negozio) < d && negozio->EstCompatibile(magazzino)) {
                trovato = true;
                break;
            }
        }

        if (!trovato) {
            result.push_back(*negozio);
        }
    }

    return result;
}

int main() {
    std::cout << "Preparazione lista magazzini." << std::endl;
    std::vector<Magazzino> magazzini = {
            Magazzino(50, true, 10.134, 24.126),
            Magazzino(30, true, 16.512, 49.654),
            Magazzino(140, true, 35.769, 112.876),
            Magazzino(270, true, 45.876, 89.876),
            Magazzino(10, true, 9.876, 19.876),
            Magazzino(20, true, 12.876, 34.876),
            Magazzino(110, true, 30.876, 69.876),
    };

    std::cout << "Preparazione lista negozi." << std::endl;
    std::vector<Negozio> negozi = {
            Negozio(4, 12.254, 15.377, {
                    &magazzini[3],
                    &magazzini[4]
            }),
            Negozio(13, 30.111, 90.664, {
                    &magazzini[0],
                    &magazzini[1]
            }),
            Negozio(22, 11.905, 45.342, {
                    &magazzini[2],
                    &magazzini[5]
            }),
            Negozio(17, 44.345, 18.424, {
                    &magazzini[1],
                    &magazzini[6]
            }),
    };

    std::cout << "Preparazione azienda." << std::endl;

    Azienda azienda;
    for (int i = 0; i < magazzini.size(); i++) {
        azienda.InserisciMagazzino(&(magazzini[i]));
    }
    for (int i = 0; i < negozi.size(); i++) {
        azienda.InserisciNegozio(&(negozi[i]));
    }

    std::cout << "Test funzione NessunMagazzino." << std::endl;
    const std::vector<const Negozio> result = NessunMagazzino(azienda, 10);
    std::cout << "Risultato: " << result << std::endl;

    std::cout << "Test stampa." << std::endl;
    std::cout << azienda;

    std::cout << "Test aggiunta forniture." << std::endl;
    azienda.AssegnaFornitura(&magazzini[3], &negozi[3], 13);
    azienda.AssegnaFornitura(&magazzini[2], &negozi[1], 3);
    std::cout << azienda;

    std::cout << "Test assegnazione residui." << std::endl;
    std::cout << (azienda.AssegnaResiduo(&negozi[2]) ? "Assegnazione avvenuta con successo."
                                                     : "Assegnazione non riuscita.") << std::endl;
    std::cout << azienda;

    std::cout << "Test chiusura magazzino." << std::endl;
    azienda.ChiudiMagazzino(&magazzini[6]);
    std::cout << azienda;

    return 0;
}
