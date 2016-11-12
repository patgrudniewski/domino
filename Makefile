CC=g++
CFLAGS=

DEPS=
OBJ=main.o

all: make

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

make: $(OBJ)
	$(CC) -o main.out $^ $(CFLAGS)

clean:
	rm -f *.o *~ core

.PHONY: clean make
