kion-htmlreport: kion-htmlreport.o readfile.o html-report4.o kionstat.o
	gcc -o kion-htmlreport kion-htmlreport.o readfile.o html-report4.o kionstat.o

kion-htmlreport.o: kion-htmlreport.c kion-htmlreport.h
	gcc -c kion-htmlreport.c

readfile.o: readfile.c kion-htmlreport.h
	gcc -c readfile.c

html-report4.o: html-report4.c kion-htmlreport.h kionstat.h
	gcc -c html-report4.c

kionstat.o: kionstat.c kionstat.h
	gcc -c kionstat.c

clean: 
	rm -f kion-htmlreport *.o a.out