CC = clang
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
EXEC = bfi

$(EXEC): $(OBJ)
	$(CC) -o $@ $(OBJ)

$(OBJ): $(SRC)

