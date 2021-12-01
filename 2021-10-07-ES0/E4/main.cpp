#include <iostream>
using namespace std;

long double RadiceQuadrata(unsigned, long double, unsigned&);

int main() {
  int         n;
  long double result;
  unsigned    iterations;

  do {
    cout << "Inserire un numero intero positivo: ";
    cin >> n;
  } while (n < 0);

  result = RadiceQuadrata(n, 0.000001, iterations);

  cout << "La radice quadrata di " << n << " è " << result << " (" << iterations
       << " iterazioni)." << endl;
}

long double
RadiceQuadrata(unsigned n, long double epsilon, unsigned& iterations) {
  long double result;
  long double result_new = 1;

  iterations = 0;

  do {
    result     = result_new;
    result_new = (result + (n / result)) / 2;
    iterations++;

    // cout << "DEBUG: iter=" << iterations << " result=" << result << "
    // result_new=" << result_new << " delta=" << abs(result - result_new) <<
    // endl;
  } while (abs(result - result_new) > epsilon);

  return result;
}
