CC=gcc
EXEC=chauffageUSB.exe
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
LDFLAGS= ./ftd2xx.lib
CFLAGS=-Wall

all: $(EXEC)

$(EXEC):$(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o:%.c
	@$(CC) -o  $@ -c $< $(CFLAGS)

.PHONY: clean

clean:
	@rm -rf *.o
	@rm -rf $(EXEC)
