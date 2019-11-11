CC = g++
CFLAGS = -Wall -Wextra -O2
LDLIBS = -lm

build: algo_test.o

algo.o: algo.cpp
	g++ algo.cpp -c $(CFLAGS)

algo_test.o: algo_test.cpp algo.o
	g++ algo_test.cpp -o test $(CFLAGS)

.PHONY: clean
clean:
	rm -rf *.o test
