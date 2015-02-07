UNAME := $(shell uname)

all: fibonacci

ifeq ($(UNAME), Darwin)
%.h: %.d
	dtrace -h -s $^

fibonacci: fibonacci.c fibonacci.h
	gcc -o $@ fibonacci.c
endif

ifeq ($(UNAME), SunOS)
fibonacci.o:
	dtrace -h -s fibonacci.d
	cc -c fibonacci.c

dtfib.o: fibonacci.d fibonacci.o
	dtrace -64 -G -o $@ -s fibonacci.d fibonacci.o

fibonacci: fibonacci.o dtfib.o
	cc -o fibonacci fibonacci.o dtfib.o
endif

clean:
	-rm -f fibonacci fibonacci.h *~ *.o
