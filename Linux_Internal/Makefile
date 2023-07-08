CC=gcc
CFLAGS=-std=c99 -g3 -Wall -pedantic

all: treeTest speedTest

test: all
	echo "" | valgrind -q ./treeTest
	time ./speedTest 1000000

treeTest: tree.c tree.h
	$(CC) $(CFLAGS) -DTEST_MAIN -DTEST_REBALANCE -DPRINT_AFTER_OPERATIONS -DTEST_USE_STDIN -o $@ $<

speedTest: speedTest.o tree.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) *.o treeTest speedTest
