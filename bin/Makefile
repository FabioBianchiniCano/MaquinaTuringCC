_INC = ../include
_OBJ = ../obj/
_SRC = ../src/

CC = g++
CFLAGS = -Wall -g -c -I$(_INC)
OBJ = belt.o main.o
BINARY = turing


OBJFULL = $(patsubst %,$(_OBJ)%,$(OBJ))

all: $(BINARY)

$(BINARY): $(OBJ)
	$(CC) -Wsign-compare -o $(BINARY) $(OBJFULL)
	@clear


# $@ main.o
# $< main.cpp
%.o: $(_SRC)%.cpp
	$(CC) $(CFLAGS) $< -o $(_OBJ)$@


# execute:
# 	@echo "Ejecutando el programa...\n-----------------------------"
# 	@./$(BINARY)


.PHONY: clean # Por si alguna vez existe un fichero clean en esta carpeta
clean: 
	@clear
	rm -rf $(BINARY) 
	rm -rf $(_OBJ)*.o *.o