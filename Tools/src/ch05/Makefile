DEBUG:= -O0 -g

default:
	@echo "making with DEBUG=$(DEBUG)"
		make buggy

buggy: buggy.c buggy_fn.o 
	gcc $(DEBUG) buggy.c buggy_fn.o -o buggy

buggy_fn.o: buggy_fn.c
	gcc $(DEBUG) -c buggy_fn.c

clean:
	rm -f buggy_fn.o buggy