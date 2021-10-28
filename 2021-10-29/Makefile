CC=g++
FLAGS=-Wall -Wextra -Wpedantic -Wfatal-errors

main: stack.o driver_stack.o
	$(CC) -o $@ $^ $(FLAGS)

stack.o: Stack.cpp
	$(CC) -c $^ -o $@ $(FLAGS)

driver_stack.o: driver_stack.cpp
	$(CC) -c $^ -o $@ $(FLAGS)

clean:
	rm -f *.o main
