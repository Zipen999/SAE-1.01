exe: sae.o testsae.o
	gcc sae.o testsae.o -o exe
tp8.o: sae.h sae.c
	gcc -c sae.c
testtp8.o: sae.h testsae.c
	gcc -c testsae.c
clean:
	rm -Rf *.o exe
