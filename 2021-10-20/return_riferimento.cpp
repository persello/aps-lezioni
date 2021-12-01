int Max(int v[], unsigned n) {
  unsigned i, m = 0;

  for (i = 1; i < n; i++)
    if (v[i] > v[m])
      m = i;

  return v[m];
}

// Identica a Max, ma restituisce un riferimento.
int& MaxP(int v[], unsigned n) {
  unsigned i, m = 0;

  for (i = 1; i < n; i++)
    if (v[i] > v[m])
      m = i;

  // Attenzione: Funziona perché v non è una variabile locale.
  return v[m];
}

int main() {
  int w[7] = {2, 5, 7, -2, 8, 4, 7};
  int x;

  x = Max(w, 7);
  // SBAGLIATO Max(w, 7) = 22;
  // Max(w, 7) non ha lvalue.

  x          = MaxP(w, 7);
  MaxP(w, 7) = 22;
  // Sono entrambi corretti.
  // v[m] vale 22.
}
