CC=clang
ifeq ($(CC), clang)
	CFLAGS=-Wall
else
	CFLAGS=
endif

test: 
	$(CC) geometry.c test.c -o test.o $(CFLAGS)

test_memcheck:
	$(CC) geometry.c test.c -o test.o $(CFLAGS)
	valgrind ./test.o

.PHONY: clean
clean:
	rm -f *.o *.gch *.out

