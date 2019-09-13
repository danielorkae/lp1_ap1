output: main.o concessionaria.o automovel.o
	g++ main.o concessionaria.o automovel.o -o index.out

main.o: src/main.cpp
	g++ src/main.cpp -Wall -pedantic

concessionaria.o: concessionaria.cpp concessionaria.h
	g++ src/concessionaria.cpp

automovel.o: automovel.cpp automovel.h
	g++ src/automovel.cpp

clean:
	rm *.o output