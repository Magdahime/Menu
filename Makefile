#Makefile to compile MENU program
CFLAGS = -Wall -Iinclude -g -Isrc
CC = g++
INCLUDE = include
SRC = src
BUILD = build
BIN = bin

$(BIN)/TEST: $(BUILD)/Tests.o $(BUILD)/Keyboard.o
	$(CC) $(CFLAGS)  $(BUILD)/Tests.o $(BUILD)/Keyboard.o -o $(BIN)/TEST

$(BUILD)/Test.o: $(SRC)/Tests.cpp $(INCLUDE)/Main.hpp $(INCLUDE)/Keyboard.hpp
	$(CC) $(CFLAGS)  -c $(SRC)/Tests.cpp -o $(BUILD)/Tests.o

$(BUILD)/Keyboard.o: $(SRC)/Keyboard.cpp $(INLCUDE)/Keyboard.hpp $(INCLUDE)/Main.hpp
	$(CC) $(CFLAGS) -c $(SRC)/Keyboard.cpp -o $(BUILD)/Keyboard.o


clean:
	rm -f $(BUILD)/*.o
	rm -f $(BIN)/TEST

