# Un vieux makefile tout pourri

CC = gcc

SRC = 	main.c \
	sl_strlen.c 

CFLAGS = -Wall -W -I./

OBJ = $(SRC:.c=.o)

EXE = test

all:$(EXE)

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(CFLAGS)

clean:
	rm -rf *.o *~
fclean:clean 
	rm -rf $(EXE)

re:fclean all
