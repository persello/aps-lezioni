CC=g++
FLAGS=-Wall -Wextra -Wpedantic -Wfatal-errors

main: vettori.o driver_vettori.o
	$(CC) -o $@ $^ $(FLAGS)

vettori.o: Vettori3D.cpp
	$(CC) -c $^ -o $@ $(FLAGS)

driver_vettori.o: driver_vettori.cpp
	$(CC) -c $^ -o $@ $(FLAGS)

clean:
	rm -f *.o main
