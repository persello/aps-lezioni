//
// Created by Riccardo Persello on 29/01/22.
//

#include "Azienda.h"
#include "OutputTemplates.h"

void Azienda::InserisciMagazzino(const Magazzino *m) {
    if (TrovaMagazzino(m) == -1) {
        magazzini.push_back(m);
    }
}

void Azienda::InserisciNegozio(const Negozio *n) {
    if (TrovaNegozio(n) == -1) {
        negozi.push_back(n);
    }
}

void Azienda::ChiudiMagazzino(Magazzino *m) const {
    if (TrovaMagazzino(m) == -1)
        throw std::invalid_argument("Non è possibile chiudere un magazzino non disponibile.");
    if (!TrovaForniture(m).empty())
        throw std::invalid_argument("Non è possibile chiudere un magazzino con forniture attive.");

    m->Chiudi();
}

void Azienda::AssegnaFornitura(const Magazzino *m, const Negozio *n, int q) {
    if (TrovaMagazzino(m) == -1)
        throw std::invalid_argument("Non è possibile assegnare una fornitura da un magazzino non disponibile.");
    if (TrovaNegozio(n) == -1)
        throw std::invalid_argument("Non è possibile assegnare una fornitura ad un negozio non disponibile.");
    if (!m->Aperto())
        throw std::invalid_argument("Non è possibile assegnare una fornitura da un magazzino chiuso.");
    if (RichiestaResidua(n) < q) {
        throw std::invalid_argument(
                "Non è possibile assegnare una fornitura ad un negozio con una richiesta residua troppo bassa.");
    }
    if (CapacitaResidua(m) < 1)
        throw std::invalid_argument(
                "Non è possibile assegnare una fornitura da un magazzino con una capacità residua troppo bassa.");
    if (!n->EstCompatibile(m))
        throw std::invalid_argument("Non è possibile assegnare una fornitura tra negozi e magazzini incompatibili.");

    int indice_fornitura = TrovaFornitura(m, n);
    if (indice_fornitura == -1) {
        this->forniture.emplace_back(n, m, q);
    } else {
        this->forniture[indice_fornitura].quantita += q;
    }
}

bool Azienda::AssegnaResiduo(const Negozio *n) {
    if (TrovaNegozio(n) == -1) {
        throw std::invalid_argument("Non è possibile assegnare un residuo ad un negozio non disponibile.");
    } else if (RichiestaResidua(n) <= 0) {
        throw std::invalid_argument("Non è possibile assegnare un residuo ad un negozio con q residua nulla.");
    }

    int q = RichiestaResidua(n);
    std::pair<int, double> migliore = std::make_pair(-1, std::numeric_limits<double>::infinity());

    for (int i = 0; i < this->magazzini.size(); i++) {
        const Magazzino *m = this->magazzini[i];
        double distanza = Distanza(m, n);
        if (m->Aperto() && CapacitaResidua(m) >= q && distanza < migliore.second) {
            migliore = std::make_pair(i, distanza);
        }
    }

    if (migliore.first == -1) {
        return false;
    } else {
        AssegnaFornitura(this->magazzini[migliore.first], n, q);
        return true;
    }
}

const std::vector<const Magazzino *> &Azienda::Magazzini() const {
    return magazzini;
}

const std::vector<const Negozio *> &Azienda::Negozi() const {
    return negozi;
}

const std::vector<Fornitura> &Azienda::Forniture() const {
    return forniture;
}

int Azienda::TrovaMagazzino(const Magazzino *m) const {
    for (int i = 0; i < this->magazzini.size(); i++) {
        if (this->magazzini[i] == m)
            return i;
    }

    return -1;
}

int Azienda::TrovaNegozio(const Negozio *n) const {
    for (int i = 0; i < this->negozi.size(); i++) {
        if (this->negozi[i] == n)
            return i;
    }

    return -1;
}

int Azienda::TrovaFornitura(const Magazzino *m, const Negozio *n) const {
    for (int i = 0; i < this->forniture.size(); i++) {
        if (this->forniture[i].magazzino == m && this->forniture[i].negozio == n)
            return i;
    }

    return -1;
}

std::vector<Fornitura> Azienda::TrovaForniture(const Negozio *n) const {
    std::vector<Fornitura> result;
    for (const Fornitura &i: this->forniture) {
        if (i.negozio == n)
            result.push_back(i);
    }

    return result;
}

std::vector<Fornitura> Azienda::TrovaForniture(const Magazzino *m) const {
    std::vector<Fornitura> result;
    for (const Fornitura &i: this->forniture) {
        if (i.magazzino == m)
            result.push_back(i);
    }

    return result;
}

int Azienda::RichiestaResidua(const Negozio *n) const {
    int residuo = n->Richiesta();
    std::vector<Fornitura> forniture_negozio = TrovaForniture(n);
    for (const Fornitura &i: forniture_negozio) {
        residuo -= i.quantita;
    }

    return residuo;
}

int Azienda::CapacitaResidua(const Magazzino *m) const {
    int residuo = m->Capacita();
    std::vector<Fornitura> forniture_magazzino = TrovaForniture(m);
    for (const Fornitura &i: forniture_magazzino) {
        residuo -= i.quantita;
    }

    return residuo;
}

std::ostream &operator<<(std::ostream &os, const Azienda &azienda) {
    os << std::endl << "Azienda:" << std::endl;
    os << "\tmagazzini: " << azienda.magazzini << std::endl;
    os << "\tnegozi: " << azienda.negozi << std::endl;
    os << "\tforniture: " << azienda.forniture << std::endl;
    return os;
}

double Distanza(const Magazzino *m, const Negozio *n) {
    return sqrt(pow(m->X() - n->X(), 2) + pow(m->Y() - n->Y(), 2));
}
