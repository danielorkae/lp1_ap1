CC=g++

LIB=./lib
INCLUDE=./include
SRC=./src
BUILD=./build
BIN=./bin

FLAGS = -Wall -pedantic -std=c++11

main: projeto.a
	$(CC) $(SRC)/main.cpp $(FLAGS) -I$(INCLUDE) -L$(LIB) -o $(BIN)/$@

projeto.a:
	$(CC) -c $(SRC)/Automovel.cpp $(FLAGS) -I$(INCLUDE) -o $(BUILD)/automovel.o 
	$(CC) -c $(SRC)/Concessionaria.cpp $(FLAGS) -I$(INCLUDE) -o $(BUILD)/concessionaria.o
	$(CC) -c $(SRC)/menu.cpp $(FLAGS) -I$(INCLUDE) -o $(BUILD)/menu.o
	ar -cru $(LIB)/projeto.a $(BUILD)/automovel.o $(BUILD)/concessionaria.o $(BUILD)/menu.o 

clean:
	rm $(BIN)/main $(SRC)/*~ $(BUILD)/*o $(LIB)/*a