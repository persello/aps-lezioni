/*

- Per valore
- Per riferimento

Ogni tanto abbiamo bisogno di passare ad una funzione degli oggetti complessi ma
non vogliamo passarli per valore, perché questo implicherebbe una copia del
valore. Potremmo passarli per riferimento, in questo caso la funzione non creerà
una copia ma farà riferimento all'oggetto passato. Però questo consente alla
funzione di modificare l'oggetto passato. Quindi c'è un trucco per evitare
questo problema: passare l'oggetto per riferimento costante.

- Per riferimento costante

Sarà il metodo per il passaggio di parametri più comune.

*/

class A {
public:
  int x;
};

int F(const A &a) {

  // Non è possibile modificare l'oggetto passato per riferimento.

  // SBAGLIATO: a.x = 10;

  return a.x;
}
