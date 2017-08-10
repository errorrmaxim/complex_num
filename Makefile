all: complex_numbers

complex_numbers: main.o complex_num.o
		g++ main.o complex_num.o -o complex_numbers


main.o: main.cpp
		g++ -c main.cpp

complex_num.o: complex_num.cpp
		g++ -c complex_num.cpp
clean:
		rm -rf *.o complex_numbers
 
	
