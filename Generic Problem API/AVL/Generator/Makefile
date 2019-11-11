CC = g++
CFLAGS = -Wall -Wextra -O2
LDLIBS = -lm

generator:
	@g++ generator.cpp -o generator
	@./generator

.PHONY: clean
clean:
	rm -rf *.o test