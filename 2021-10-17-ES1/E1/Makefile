CC=g++
FLAGS=-Wall -Wextra -Wpedantic -Wfatal-errors

main: conto_corrente.o driver_conto.o
	$(CC) -o $@ $^ $(FLAGS)

conto_corrente.o: ContoCorrente.cpp
	$(CC) -c $^ -o $@ $(FLAGS)

driver_conto.o: DriverConto.cpp
	$(CC) -c $^ -o $@ $(FLAGS)

clean:
	rm -f *.o main
