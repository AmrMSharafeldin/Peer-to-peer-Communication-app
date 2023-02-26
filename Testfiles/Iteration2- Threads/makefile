all: S_Talk

S_Talk: screen.o receiver.o sender.o keyboard.o list.o
	gcc -Wall -o S_Talk screen.o  receiver.o keyboard.o  sender.o list.o -pthread S_Talk.c 

screen.o: screen.h screen.c list.o
	gcc -Wall -c screen.c list.o -pthread

keyboard.o: keyboard.h keyboard.c list.o
	gcc -Wall -c keyboard.c list.o -pthread

receiver.o: receiver.h receiver.c list.o
	gcc -Wall -c receiver.c list.o -pthread

sender.o: sender.h sender.c list.o
	gcc -Wall -c sender.c list.o -pthread

clean: 
	rm -f *.o
