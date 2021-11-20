Program: main.o
	g++ main.o

main.o: main.cpp 
	g++ -c main.cpp

clean:
	rm *.o a.out

