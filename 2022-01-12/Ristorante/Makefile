CC=g++
FLAGS=-O0 -Wall -Wextra -Wpedantic -Wfatal-errors -stdlib=libc++ -std=c++20

.PHONY: clean

main: main.cpp ristorante.o tavolo.o
	$(CC) -o $@ $^ $(FLAGS)

tavolo.o: tavolo.cpp
	$(CC) -c $< -o $@ $(FLAGS)

ristorante.o: ristorante.cpp
	$(CC) -c $< -o $@ $(FLAGS)

clean:
	rm -f *.o main
