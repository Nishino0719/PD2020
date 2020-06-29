zipcount: zipcount.o pref.o
	gcc -o zipcount zipcount.o pref.o

zipcount.o: zipcount.c zipcount.h
	gcc -c zipcount.c

pref.o: pref.c zipcount.h
	gcc -c pref.c

clean: 
	rm -f zipcount *.o a.out