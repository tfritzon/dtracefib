all: fibonacci

%.h: %.d
	dtrace -h -s $^

fibonacci: fibonacci.c fibonacci.h
	gcc -o $@ fibonacci.c

clean:
	-rm -f fibonacci fibonacci.h *~
