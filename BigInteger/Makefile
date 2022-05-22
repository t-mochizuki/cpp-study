make: main.cpp BigInteger.o
	g++ main.cpp BigInteger.o -std=c++17 -D DEV=1 -I .

BigInteger.o: BigInteger.cpp
	g++ -c BigInteger.cpp -std=c++17

test: a.out
	./a.out

clean: a.out BigInteger.o
	rm a.out BigInteger.o
