shop.out: main.o cart.o
	g++ main.o cart.o -o shop.out

cart.o: cart.h cart.cpp
	g++ -c cart.cpp

main.o: main.cpp cart.h
	g++ -c main.cpp

clean:
	rm *.o shop.out
