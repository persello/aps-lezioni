#include "a.hpp"
#include <iostream>

using namespace std;

int main() {
  A a;

  // Stamperà -1. Il costruttore di default di A chiama quello di default di B,
  // che assegna -1 ad y.
  cout << a.b.y << endl;

  // Come faccio ad inizializzare b con un altro costruttore?
  // Vedi il costruttore A::A(int, int). Questo usa la riga di inizializzazione.
  // Stamperà 4 (2 * 2).
  A a2(1, 2);
  cout << a2.b.y << endl;
}
