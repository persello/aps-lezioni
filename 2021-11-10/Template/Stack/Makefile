CC=g++
FLAGS=-Wall -Wextra -Wpedantic -Wfatal-errors

main: driver_stack.o
	$(CC) -o $@ $^ $(FLAGS)

driver_stack.o: driver_stack.cpp Stack.hpp
	$(CC) -c driver_stack.cpp -o $@ $(FLAGS)

clean:
	rm -f *.o main