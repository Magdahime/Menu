#Makefile to compile MENU program
CFLAGS = -Wall -Iinclude -g -Isrc
CC = g++
INCLUDE = include
SRC = src
BUILD = build
BIN = bin

$(BIN)/TEST: $(BUILD)/Tests.o $(BUILD)/Keyboard.o $(BUILD)/Window.o $(BUILD)/Functions.o
	$(CC) $(CFLAGS)  $(BUILD)/Tests.o $(BUILD)/Keyboard.o $(BUILD)/Window.o $(BUILD)/Functions.o -o $(BIN)/TEST

$(BUILD)/Tests.o: $(SRC)/Tests.cpp $(INCLUDE)/Main.hpp $(INCLUDE)/Keyboard.hpp $(INCLUDE)/Window.hpp $(INCLUDE)/Functions.hpp
	$(CC) $(CFLAGS)  -c $(SRC)/Tests.cpp -o $(BUILD)/Tests.o

$(BUILD)/Keyboard.o: $(SRC)/Keyboard.cpp $(INCLUDE)/Keyboard.hpp $(INCLUDE)/Main.hpp
	$(CC) $(CFLAGS) -c $(SRC)/Keyboard.cpp -o $(BUILD)/Keyboard.o

$(BUILD)/Window.o: $(SRC)/Window.cpp $(INCLUDE)/Window.hpp $(INCLUDE)/Functions.hpp $(INCLUDE)/Menu.hpp $(INCLUDE)/Main.hpp $(INCLUDE)/Basic_window.hpp
	$(CC) $(CFLAGS) -c $(SRC)/Window.cpp -o $(BUILD)/Window.o

$(BUILD)/Functions.o: $(SRC)/Functions.cpp $(INCLUDE)/Main.hpp $(INCLUDE)/Functions.hpp
	$(CC) $(CFLAGS) -c $(SRC)/Functions.cpp -o $(BUILD)/Functions.o


clean:
	rm -f $(BUILD)/*.o
	rm -f $(BIN)/TEST

