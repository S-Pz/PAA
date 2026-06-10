TARGET = bin/tp2

CC = gcc

CFLAGS = -Wall -Wextra -O2 -Iinclude

SRC = src/main.c \
      src/solver.c \
      src/io.c \
      src/timer.c

OBJ = build/main.o \
      build/solver.o \
      build/io.o \
      build/timer.o


all: directories $(TARGET)

directories:
	mkdir -p bin
	mkdir -p build


$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)


build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@


runD:
	./bin/tp2 D entrada.txt


runA:
	./bin/tp2 A entrada.txt

clean:
	rm -rf build/*
	rm -rf bin/*
	rm -f saida.txt

rebuild: clean all
