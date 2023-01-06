debug : test ds tokeneizer
	gcc -w -g -o debug test.o ds.o tokeneizer.o
test:
	gcc -w -g -c test.c
ds:
	gcc -w -g -c ds.c
tokeneizer:
	gcc -w -g -c tokeneizer.c
clean:
	rm *.o