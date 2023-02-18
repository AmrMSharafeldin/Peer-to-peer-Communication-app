all: exec

exec: screen.o keyboard.o receiver.o sender.o 
	gcc -Wall -o exec screen.o keyboard.o receiver.o sender.o main.c

screen.o: screen.h screen.c
	gcc -Wall -c screen.c

keyboard.o: keyboard.h keyboard.c
	gcc -Wall -c keyboard.c

receiver.o: receiver.h receiver.c
	gcc -Wall -c receiver.c

sender.o: sender.h sender.c
	gcc -Wall -c sender.c

clean: 
	rm -f *.o