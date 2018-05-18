CFLAGS=-ggdb3 -Wall
LDLIBS=-l:func.o -lpthread
LDFLAGS=-L./

.PHONY: clean 

all: u0 u1

u0: func.o u0.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ u0.c $(LDLIBS)

u1: func.o u1.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ u1.c $(LDLIBS)

clean:
	rm *.o u0 u1
