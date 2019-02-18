FLAGS=-Wall -g -std=c99

check: test
	./test

test: test.o numberrep.o
	@gcc $(FLAGS) -o test test.o numberrep.o

numberrep.o: numberrep.c numberrep.h
	@gcc $(FLAGS) -c numberrep.c

test.o: test.c
	@gcc $(FLAGS) -c test.c

clean:
	@rm -f *.o
	@rm -f test

.PHONY: clean
