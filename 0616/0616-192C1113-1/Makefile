kion-htmlreport: kion-htmlreport.o kion-htmlreport2.o kion-htmlreport3.o readfile.o html-report.o kionstat.o
	gcc -o kion-htmlreport kion-htmlreport.o kion-htmlreport2.o kion-htmlreport3.o readfile.o html-report.o kionstat.o

kion-htmlreport.o: kion-htmlreport.c kion-htmlreport.h
	gcc -c kion-htmlreport.c

kion-htmlreport2.o: kion-htmlreport2.c kion-htmlreport2.h
	gcc -c kion-htmlreport2.c

kion-htmlreport3.o: kion-htmlreport3.c kion-htmlreport3.h
	gcc -c kion-htmlreport3.c

readfile.o: readfile.c kion-htmlreport.h
	gcc -c readfile.c

html-report.o: html-report.c kion-htmlreport.h kion-htmlreport2.h kion-htmlreport3.h kionstat.h
	gcc -c html-report.c

kionstat.o: kionstat.c kionstat.h
	gcc -c kionstat.c


