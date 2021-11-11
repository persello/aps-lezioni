CC=g++
FLAGS=-O0 -Wall -Wextra -Wpedantic -Wfatal-errors -stdlib=libc++ -std=c++20

.PHONY: clean

main: main.cpp date.o person.o
	$(CC) -o $@ $^ $(FLAGS)

date.o: date/date.cpp date/date.hpp
	$(CC) -c $< -o $@ $(FLAGS)

person.o: person/person.cpp person/person.hpp
	$(CC) -c $< -o $@ $(FLAGS)

clean:
	rm -f *.o main
