#include <iostream>

using namespace std;

const int DIM_VET = 6;
const int NUM_RIGHE = 2;
const int NUM_COL = 3;

int NumeroDistintiVettore(int v[], int n);
int NumeroDistintiMatrice(int m[][NUM_COL], int righe, int col);

int main() {
  int vett[DIM_VET];
  int mat[NUM_RIGHE][NUM_COL];
  int i, j;

  cout << "Inserisci un vettore di " << DIM_VET << " valori interi : ";
  for (i = 0; i < DIM_VET; i++)
    cin >> vett[i];
  cout << "Il numero di elementi distinti del vettore e' "
       << NumeroDistintiVettore(vett, DIM_VET) << endl;

  cout << "Inserisci una matrice di " << NUM_RIGHE << " righe e " << NUM_COL
       << " colonne" << endl;
  for (i = 0; i < NUM_RIGHE; i++)
    for (j = 0; j < NUM_COL; j++)
      cin >> mat[i][j];

  cout << "Il numero di elementi distinti della matrice e' "
       << NumeroDistintiMatrice(mat, NUM_RIGHE, NUM_COL) << endl;
}

int NumeroDistintiVettore(int v[], int n) {
  int distinti[DIM_VET];
  unsigned num_distinti = 0;

  // Per ogni elemento di v
  for (unsigned v_index = 0; v_index < (unsigned)n; v_index++) {
    bool found = false;

    // Controlla tutti gli elementi distinti
    for (unsigned d_index = 0; d_index < num_distinti; d_index++) {
      if (distinti[d_index] == v[v_index]) {
        found = true;
        break;
      }
    }

    // Se è diverso da tutti gli elementi distinti, è distinto.
    if (!found) {
      distinti[num_distinti] = v[v_index];
      num_distinti++;
    }
  }

  return num_distinti;
}

int NumeroDistintiMatrice(int m[][NUM_COL], int righe, int col) {
  int distinti[DIM_VET];
  unsigned num_distinti = 0;

  // Per ogni elemento di m
  for (unsigned i = 0; i < (unsigned)righe; i++) {
    for (unsigned j = 0; j < (unsigned)col; j++) {
      bool found = false;

      // Controlla tutti gli elementi distinti
      for (unsigned d_index = 0; d_index < num_distinti; d_index++) {
        if (distinti[d_index] == m[i][j]) {
          found = true;
          break;
        }
      }

      // Se è diverso da tutti gli elementi distinti, è distinto.
      if (!found) {
        distinti[num_distinti] = m[i][j];
        num_distinti++;
      }
    }
  }

  return num_distinti;
}
