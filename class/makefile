out:test.c
	gcc -E test.c -o out.i
	gcc -S out.i -o out.s
	gcc -c out.s -o out.o
	gcc out.o -o out

.PHONY:clean
clean:
	rm -f out
	rm -f out.i
	rm -f out.s
	rm -f out.o
