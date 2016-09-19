CC=gcc
CCFLAGS=-Wall -W -std=99 -pedantic -I.header

SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)

EXEC=MSSQ

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o  $(EXEC) $^ 

$.o: %.c
	$(CC) -o $@ -c $< $(CCFLAGS)

clean:
	@echo "Remove .o file"
	rm -r src/*.o

cm: clean | $(EXEC)
	
