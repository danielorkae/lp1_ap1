CC = g++

CPPFLAGS = -Wall -std=c++11 -pedantic

output: main.o concessionaria.o automovel.o menu.o
	$(CC) main.o concessionaria.o automovel.o menu.o -o index.out
	mv *.o build/

main.o: src/main.cpp
	$(CC) -c src/main.cpp $(CPPFLAGS) src/concessionaria.cpp src/menu.cpp -I include

concessionaria.o: src/concessionaria.cpp include/automovel.h
	$(CC) -c src/concessionaria.cpp $(CPPFLAGS) -I include

automovel.o: src/automovel.cpp
	$(CC) -c src/automovel.cpp $(CPPFLAGS) -I include

menu.o: src/menu.cpp
	$(CC) -c src/menu.cpp $(CPPFLAGS) -I include

clean:
	rm build/*.o
