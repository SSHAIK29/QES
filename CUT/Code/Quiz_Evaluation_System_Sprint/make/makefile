CC = gcc
INC = ../inc
OBJ = ../obj
SRC = ../src
BIN = ../bin
FILES = ../files
LDFLAGS = -o
CFLAGS = -c -g -Wall

all: $(BIN)/QES

$(BIN)/QES: $(OBJ)/main.o $(OBJ)/evaluate.o $(OBJ)/output_csv.o $(OBJ)/trimwhitespace.o
	$(CC) $(LDFLAGS) $(BIN)/QES $(OBJ)/main.o $(OBJ)/evaluate.o $(OBJ)/output_csv.o $(OBJ)/trimwhitespace.o

$(OBJ)/main.o: $(SRC)/main.c
	$(CC) $(CFLAGS) $(SRC)/main.c -I $(INC)/
	mv *.o $(OBJ)/

$(OBJ)/evaluate.o: $(SRC)/evaluate.c 
	$(CC) $(CFLAGS) $(SRC)/evaluate.c -I $(INC)/
	mv *.o $(OBJ)/

$(OBJ)/output_csv.o: $(SRC)/output_csv.c 
	$(CC) $(CFLAGS) $(SRC)/output_csv.c -I $(INC)/
	mv *.o $(OBJ)/

$(OBJ)/trimwhitespace.o: $(SRC)/trimwhitespace.c
	$(CC) $(CFLAGS) $(SRC)/trimwhitespace.c -I $(INC)/
	mv *.o $(OBJ)/

run:
	$(BIN)/QES $(FILES)/$(ARGV1) $(FILES)/$(ARGV2)


clean:
	rm -f a.out *.o
	rm -f $(BIN)/*
	rm -f $(OBJ)/*.o
	@echo "Cleaning Done!"




	
