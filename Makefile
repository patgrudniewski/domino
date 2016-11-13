CC=g++
CFLAGS=-I./src

DEPS=
OBJ=$(patsubst %.cpp, %.o, $(shell find . -name '*\.cpp'))

all: compile

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

compile: $(OBJ)
	$(CC) -o main.out $^ $(CFLAGS)

clean:
	find . -type f -name '*.o' -delete

.PHONY: clean make
