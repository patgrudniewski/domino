TMPDIR=./tmp
LIBDIR=./lib

TCPLAP_VER=1.2.1

DEPS=https\://sourceforge.net/projects/tclap/files/tclap-$(TCPLAP_VER).tar.gz
DEP_IDIRS=$(LIBDIR)/tclap-$(TCPLAP_VER)/include

CC=g++
CFLAGS=-I./src $(addprefix -I, $(DEP_IDIRS))

OBJ=main.o $(patsubst %.cpp, %.o, $(shell find ./src -name '*\.cpp'))

all: build

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build-dev: CFLAGS += -DDEBUG
build-dev: build

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

.PHONY: clean build all
