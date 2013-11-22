CC      = clang++
CFLAGS  = -g -Wall -Werror -std=c++11 -stdlib=libc++
LDFLAGS = -std=c++11 -stdlib=libc++

all: main

main: main.o token.o
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: main.cc
	$(CC) -c $(CFLAGS) $^

token.o: token.cc
	$(CC) -c $(CFLAGS) $^

.PHONY: clean

clean:
	rm *.o main
