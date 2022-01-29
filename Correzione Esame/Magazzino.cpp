//
// Created by Riccardo Persello on 29/01/22.
//

#include "Magazzino.h"

Magazzino::Magazzino(int c, bool a, double x, double y) {
    this->capacita = c;
    this->aperto = a;
    this->x = x;
    this->y = y;
}

int Magazzino::Capacita() const {
    return this->capacita;
}

bool Magazzino::Aperto() const {
    return this->aperto;
}

double Magazzino::X() const {
    return this->x;
}

double Magazzino::Y() const {
    return this->y;
}

void Magazzino::Apri() {
    this->aperto = true;
}

void Magazzino::Chiudi() {
    this->aperto = false;
}

std::ostream &operator<<(std::ostream &os, const Magazzino &magazzino) {
    os << std::endl << "\tMagazzino:" << std::endl;
    os << "\t\tcapacita: " << magazzino.capacita << std::endl;
    os << "\t\taperto: " << (magazzino.aperto ? "si" : "no") << std::endl;
    os << "\t\tposizione: (" << magazzino.x << ", " << magazzino.y << ")" << std::endl;
    return os;
}
