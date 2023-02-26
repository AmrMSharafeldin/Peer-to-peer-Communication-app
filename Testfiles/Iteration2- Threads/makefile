all: listener sender

listener: screen.o receiver.o list.o
	gcc -Wall -o lisnter screen.o  receiver.o list.o -pthread S_talkReceive.c 

	
sender: keyboard.o sender.o list.o
	gcc -Wall -o sender keyboard.o  sender.o list.o -pthread S_talkSend.c


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
