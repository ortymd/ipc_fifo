CFLAGS=-ggdb3 -Wall
LDLIBS=-l:func.o -lpthread
LDFLAGS=-L./

.PHONY: clean 

all: user0 user1

user0: func.o user0.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ user0.c $(LDLIBS)

user1: func.o user1.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ user1.c $(LDLIBS)

clean:
	rm *.o user0 user1
