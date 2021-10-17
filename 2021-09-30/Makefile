data_valida: data_valida.o manipola_date.o
	g++ -o data_valida data_valida.o manipola_date.o

data_valida.o: data_valida.cpp manipola_date.hpp
	g++ -c data_valida.cpp -Wall -Wextra

manipola_date.o: manipola_date.cpp manipola_date.hpp
	g++ -c manipola_date.cpp -Wall -Wextra