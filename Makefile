##
 # File: Makefile
 # File Created: 01, November 2021
 # Author: A.S.M. Thasneem
 # -----
 # Last Modified: 07, November 2021
 # Modified By: A.S.M. Thasneem
 # -----
 # Purpose: A make file to compile multiple files and get an Execute file
##


# Makefile Variables
CC		 = gcc
EXEC	 = calculator
CFLAGS = -Wall -ansi -pedantic -g
OBJ 	 = main.o setInterface.o printInterface.o terminal.o input.o linkedlist.o writeFile.o freeLinkedList.o randomeness.o


$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)
	
main.o : main.c setInterface.h printInterface.h input.h linkedlist.h writeFile.h freeLinkedList.h
	$(CC) -c main.c $(CFLAGS)

setInterface.o : setInterface.c setInterface.h randomeness.h
	$(CC) -c setInterface.c $(CFLAGS)
	
printInterface.o : printInterface.c printInterface.h
	$(CC) -c printInterface.c $(CFLAGS)

terminal.o : terminal.c terminal.h
	$(CC) -c terminal.c $(CFLAGS)
	
input.o : input.c input.h terminal.h
	$(CC) -c input.c $(CFLAGS)
	
linkedlist.o : linkedlist.c linkedlist.h
	$(CC) -c linkedlist.c $(CFLAGS)

writeFile.o : writeFile.c writeFile.h input.h
	$(CC) -c writeFile.c $(CFLAGS)
	
freeLinkedList.o : freeLinkedList.c freeLinkedList.h input.h
	$(CC) -c freeLinkedList.c $(CFLAGS)
	
randomeness.o : randomeness.c randomeness.h
	$(CC) -c randomeness.c $(CFLAGS)

clean :
	rm -f $(EXEC) $(OBJ)