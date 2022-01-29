//
// Created by Riccardo Persello on 29/01/22.
//

#include "Negozio.h"
#include "OutputTemplates.h"

Negozio::Negozio(int r, double x, double y, const std::vector<const Magazzino *> &i) : incompatibili(i) {
    this->richiesta = r;
    this->x = x;
    this->y = y;
}

int Negozio::Richiesta() const {
    return this->richiesta;
}

double Negozio::X() const {
    return this->x;
}

double Negozio::Y() const {
    return this->y;
}

int Negozio::Incompatibili() const {
    return static_cast<int>(this->incompatibili.size());
}

const Magazzino *Negozio::Incompatibile(int i) const {
    return incompatibili.at(i);
}

bool Negozio::EstCompatibile(const Magazzino *m) const {
    for (const Magazzino *i: incompatibili) {
        if (i == m) {
            return false;
        }
    }
    return true;
}

std::ostream &operator<<(std::ostream &os, const Negozio &negozio) {
    os << "\tNegozio:" << std::endl;
    os << "\t\trichiesta: " << negozio.richiesta << std::endl;
    os << "\t\tposizione: (" << negozio.x << ", " << negozio.y << ")" << std::endl;
    os << "\t\tincompatibili: " << negozio.incompatibili << std::endl;

    return os;
}
