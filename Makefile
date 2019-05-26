#Makefile to compile MENU program
CFLAGS = -Wall -Iinclude -g -Isrc
CC = g++
INCLUDE = include
SRC = src
BUILD = build
BIN = bin

$(BIN)/TEST: $(BUILD)/Tests.o $(BUILD)/Keyboard.o $(BUILD)/Window.o $(BUILD)/Functions.o $(BUILD)/Exceptions.o $(BUILD)/Menu.o $(BUILD)/Screen.o
	$(CC) $(CFLAGS)  $(BUILD)/Tests.o $(BUILD)/Keyboard.o $(BUILD)/Window.o $(BUILD)/Functions.o $(BUILD)/Exceptions.o $(BUILD)/Menu.o $(BUILD)/Screen.o -o $(BIN)/TEST

$(BUILD)/Tests.o: $(SRC)/Tests.cpp $(INCLUDE)/Main.hpp $(INCLUDE)/Keyboard.hpp $(INCLUDE)/Window.hpp $(INCLUDE)/Functions.hpp
	$(CC) $(CFLAGS)  -c $(SRC)/Tests.cpp -o $(BUILD)/Tests.o

$(BUILD)/Keyboard.o: $(SRC)/Keyboard.cpp $(INCLUDE)/Keyboard.hpp $(INCLUDE)/Main.hpp $(INCLUDE)/Menu.hpp
	$(CC) $(CFLAGS) -c $(SRC)/Keyboard.cpp -o $(BUILD)/Keyboard.o

$(BUILD)/Window.o: $(SRC)/Window.cpp $(INCLUDE)/Window.hpp $(INCLUDE)/Functions.hpp $(INCLUDE)/Menu.hpp $(INCLUDE)/Main.hpp $(INCLUDE)/Basic_window.hpp
	$(CC) $(CFLAGS) -c $(SRC)/Window.cpp -o $(BUILD)/Window.o

$(BUILD)/Functions.o: $(SRC)/Functions.cpp $(INCLUDE)/Main.hpp $(INCLUDE)/Functions.hpp
	$(CC) $(CFLAGS) -c $(SRC)/Functions.cpp -o $(BUILD)/Functions.o

$(BUILD)/Exceptions.o: $(SRC)/Exceptions.cpp $(INCLUDE)/Main.hpp $(INCLUDE)/Exceptions.hpp
	$(CC) $(CFLAGS) -c $(SRC)/Exceptions.cpp -o $(BUILD)/Exceptions.o

$(BUILD)/Menu.o: $(SRC)/Menu.cpp $(INCLUDE)/Main.hpp $(INCLUDE)/Menu.hpp $(INCLUDE)/Window.hpp $(INCLUDE)/Functions.hpp $(INCLUDE)/Exceptions.hpp $(INCLUDE)/Keyboard.hpp
	$(CC) $(CFLAGS) -c $(SRC)/Menu.cpp -o $(BUILD)/Menu.o

$(BUILD)/Screen.o: $(SRC)/Screen.cpp $(INCLUDE)/Main.hpp $(INCLUDE)/Menu.hpp $(INCLUDE)/Keyboard.hpp
	$(CC) $(CFLAGS) -c $(SRC)/Screen.cpp -o $(BUILD)/Screen.o

clean:
	rm -f $(BUILD)/*.o
	rm -f $(BIN)/TEST

