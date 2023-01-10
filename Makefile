debug : test ds tokeneizer pattern
	gcc -w -g -o debug test.o ds.o tokeneizer.o pattern.o
test:
	gcc -w -g -c test.c
ds:
	gcc -w -g -c ds.c
tokeneizer:
	gcc -w -g -c tokeneizer.c
pattern:
	gcc -w -g -c pattern.c
clean:
	rm *.o