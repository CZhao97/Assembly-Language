
all:	x

x:	main.o p1.o p2.o
	gcc -o x main.o p1.o p2.o

main.o:	main.s
	gcc -g -c main.s

p1.o:	p1.s
	gcc -g -c p1.s

p2.o:	p2.s
	gcc -g -c p2.s

main.s:	main.c
	gcc -O2 -S main.c

p1.s:	p1.c
	gcc -O2 -S p1.c

p2.s:	p2.c
	gcc -O2 -S p2.c

clean:	
	rm -f x *.o *.s

