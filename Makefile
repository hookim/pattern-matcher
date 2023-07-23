match : main ds tokeneizer pattern
	gcc -w -o match main.o ds.o tokeneizer.o pattern.o
debug : main-d ds-d tokeneizer-d pattern-d
	gcc -w -g -o debug main.o ds.o tokeneizer.o pattern.o
main:
	gcc -w -c main.c	
main-d:
	gcc -w -g -c main.c
test:
	gcc -w -c test.c
test-d:
	gcc -w -g -c test.c
ds:
	gcc -w -c ds.c
ds-d:
	gcc -w -g -c ds.c
tokeneizer:
	gcc -w -c tokeneizer.c
tokeneizer-d:
	gcc -w -g -c tokeneizer.c
pattern:
	gcc -w -c pattern.c
pattern-d:
	gcc -w -g -c pattern.c
clean:
	rm *.o match debug