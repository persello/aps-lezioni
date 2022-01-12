# Ristorante

Un ristorante ha un nome ed un certo numero di tavoli. Ogni tavolo ha un numero massimo di posti. In un dato istante, in ciascun tavolo sono presenti delle persone, in numero uguale o inferiore al numero di posti del tavolo.

Inoltre sono specificate le seguenti operazioni:

- `AggiungiPersona(p: Persona, i: intero)`: Aggiunge la persona `p` al tavolo `i`-esimo. Se però la persona è già presente nel ristorante, non ci sono modifiche.

- `LiberaTavolo(i: intero)`: Tutte le persone presenti al tavolo `i`-esimo escono dal ristorante.

- `ModificaTavolo(i: intero, d: intero)`: Il tavolo `i`-esimo diventa di dimensione `d`. Il tavolo deve essere vuoto.

Si assuma già disponibile la classe `Persona` di cui però non si conosce la definizione.

Si richiede di:

- Disegnare il diagramma UML delle classi.

- Scrivere la definizione della classe C++ `Ristorante` con le funzioni e i costruttori che si ritengono opportuni, oltre ad altre classi che compongono lo schema.

- Scrivere le definizioni delle funzioni delle classi.

- Considerando già realizzata la classe `Gruppo`
    ```c++
    class Gruppo
         {
          public:
           int QuantePersone(); // restituisce il numero di persone del gruppo
           Persona* QualePersona(int i);
                          // restituisce il puntatore alla i-esima
                          // persona, con 1 <= i <= QuantePersone()
    // ... };
    ```
    Scrivere una funzione esterna che, ricevendo come parametro un puntatore `r` ad un oggetto della classe `Ristorante` (che si sa avere tutti i tavoli vuoti), ed un vettore `g` di puntatori ad oggetti della classe `Gruppo`, assegni ogni persona rappresentata in `g` ad un tavolo di `r` in modo che persone dello stesso gruppo siano possibilmente sedute allo stesso tavolo.