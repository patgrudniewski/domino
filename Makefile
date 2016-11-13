CC=g++
CFLAGS=-I./src
DEPS=https\://sourceforge.net/projects/tclap/files/tclap-1.2.1.tar.gz

TMPDIR=./tmp
LIBDIR=./lib

OBJ=$(patsubst %.cpp, %.o, $(shell find . -name '*\.cpp'))

all: build

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

build: $(OBJ)
	$(CC) -o main.out $^ $(CFLAGS)

clean:
	find . -type f -name '*.o' -delete
	rm -rf ./tmp

$(DEPS):
	mkdir -p $(TMPDIR) $(LIBDIR)
	if [ ! -f $(TMPDIR)/$(notdir $@) ] ; then \
		wget $@ -O $(TMPDIR)/$(notdir $@) ; \
	fi;
	if [[ "$(notdir $@)" =~ [*\.tar\.gz$$] ]] ; then \
		tar -xvzf $(TMPDIR)/$(notdir $@) -C $(LIBDIR)/ ; \
	fi;

.PHONY: clean build all dependencies
