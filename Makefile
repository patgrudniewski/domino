CC=g++
CFLAGS=-I./src

DEPS=
OBJ=main.o src/Domino/Field.o

all: make

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

make: $(OBJ)
	$(CC) -o main.out $^ $(CFLAGS)

clean:
	find . -type f -name '*.o' -delete

.PHONY: clean make
