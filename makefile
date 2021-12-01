shop.out: inventory.o main.o cart.o history.o
	g++ inventory.o main.o cart.o history.o -o shop.out

history.o: history.h history.cpp
	g++ -c history.cpp

cart.o: cart.h cart.cpp history.h history.cpp
	g++ -c cart.cpp

inventory.o: inventory.cpp inventory.h
	g++ -c inventory.cpp

main.o: main.cc cart.h cart.cpp history.h history.cpp inventory.h inventory.cpp user.h user.cpp
	g++ -c main.cc

clean:
	rm *.o shop.out
