CC=g++
FLAGS=-g -O0 -Wall -Wextra -Wpedantic -Wfatal-errors -stdlib=libc++

main: poli.o driver_poli.o
	$(CC) -o $@ $^ $(FLAGS)

poli.o: Poli.cpp
	$(CC) -c $^ -o $@ $(FLAGS)

driver_poli.o: DriverPoli.cpp
	$(CC) -c $^ -o $@ $(FLAGS)

clean:
	rm -f *.o main
