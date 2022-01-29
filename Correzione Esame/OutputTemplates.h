//
// Created by Riccardo Persello on 29/01/22.
//

#ifndef CORREZIONE_ESAME_OUTPUTTEMPLATES_H
#define CORREZIONE_ESAME_OUTPUTTEMPLATES_H

#include <ostream>

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
    os << "[";

    for (int i = 0; i < v.size(); i++) {
        os << v[i] << " ";
    }

    os << "]";

    return os;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<const T> &v) {
    os << "[";

    for (int i = 0; i < v.size(); i++) {
        os << v[i] << " ";
    }

    os << "]";

    return os;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<const T *> &v) {
    os << "[";

    for (int i = 0; i < v.size(); i++) {
        os << *(v[i]) << " ";
    }

    os << "]";

    return os;
}

#endif //CORREZIONE_ESAME_OUTPUTTEMPLATES_H
