shop.out: main.o cart.o history.o
	g++ main.o cart.o history.o -o shop.out

history.o: history.h history.cpp
	g++ -c history.cpp

cart.o: cart.h cart.cpp history.h history.cpp
	g++ -c cart.cpp

main.o: main.cpp cart.h
	g++ -c main.cpp

clean:
	rm *.o shop.out
