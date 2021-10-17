CC=g++
FLAGS=-Wall -Wextra -Wpedantic -Wfatal-errors

main: orario.o driver_orario.o
	$(CC) -o $@ $^ $(FLAGS)

orario.o: Orario.cpp
	$(CC) -c $^ -o $@ $(FLAGS)

driver_orario.o: DriverOrario.cpp
	$(CC) -c $^ -o $@ $(FLAGS)

clean:
	rm -f *.o main
