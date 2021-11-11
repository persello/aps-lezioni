CC=g++
FLAGS=-Wall -Wextra -Wpedantic -Wfatal-errors

main: date.o driver_date.o
	$(CC) -o $@ $^ $(FLAGS)

date.o: date.cpp
	$(CC) -c $^ -o $@ $(FLAGS)

driver_date.o: driver_date.cpp
	$(CC) -c $^ -o $@ $(FLAGS)

clean:
	rm -f *.o main
