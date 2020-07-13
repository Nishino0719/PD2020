kaibun: kaibun.o arraystack.o
	gcc -o kaibun kaibun.o arraystack.o

kaibun.o: kaibun.c arraystack.h
	gcc -c kaibun.c

arraystack.o: arraystack.c arraystack.h
	gcc -c arraystack.c

test:kaibun
	./kaibun
