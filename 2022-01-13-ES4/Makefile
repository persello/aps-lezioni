CC=g++
FLAGS=-O0 -Wall -Wextra -Wpedantic -Wfatal-errors -stdlib=libc++ -std=c++20

.PHONY: clean

main: main.cpp torneo.o partita.o
	$(CC) -o $@ $^ $(FLAGS)

torneo.o: torneo.cpp
	$(CC) -c $< -o $@ $(FLAGS)

partita.o: partita.cpp
	$(CC) -c $< -o $@ $(FLAGS)

clean:
	rm -f *.o main
