exe: tp8.o testtp8.o
	gcc tp8.o testtp8.o -o exe
tp8.o: tp8.h tp8.c
	gcc -c tp8.c
testtp8.o: tp8.h testtp8.c
	gcc -c testtp8.c
clean:
	rm -Rf *.o exe
