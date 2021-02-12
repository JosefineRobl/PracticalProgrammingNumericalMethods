CC = gcc
CFLAGS = -std=gnu11 -O -Wall -fwrapv
LDLIBS = -lm

default: out.txt
	cat out.txt

out.txt: epsilon
	./$< > $@

epsilon.o: epsilon.c
	$(CC) $(CFLAGS) -c $< -o $@

epsilon: epsilon.o
	$(CC) $(LDFLAGS) $< -o $@ $(LDLIBS)

clean:
	$(RM) *.o out* epsilon
