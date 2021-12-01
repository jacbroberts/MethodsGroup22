shop.out: main.o cart.o history.o user.o inventory.o
	g++ main.o cart.o history.o user.o inventory.o -o shop.out

inventory.o: inventory.h inventory.cpp
	g++ -c inventory.cpp

user.o: user.h user.cpp
	g++ -c user.cpp

history.o: history.h history.cpp
	g++ -c history.cpp

cart.o: cart.h cart.cpp history.h history.cpp
	g++ -c cart.cpp

main.o: main.cpp cart.h histroy.h user.h inventory.h 
	g++ -c main.cpp

clean:
	rm *.o shop.out
