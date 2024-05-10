/**************************************************************************
 * File: main.c										  		  			  *
 * Author: Mr.A.S.M. Thasneem                          				      *
 * ID : 20535155														  *
 * Date Created: 01/11/2021                            				      *
 * Date Modified: 07/11/2021                              				  *               
 * Purpose: Implement a simple Calculator Simulation				  	  *
 **************************************************************************/
 
 #include <stdio.h>
 #include <stdlib.h>
 #include "setInterface.h"
 #include "printInterface.h"
 #include "input.h"
 #include "linkedlist.h"
 #include "writeFile.h"
 #include "freeLinkedList.h"
 
 int main( int argc, char* argv[] )
 {
	/* Variable Declaration */
	
	int curValue = 0, curTotal = 0, digit = 0;
	char** array = NULL;
	char pressedKey = ' ';
	int row = 8, column = 3;
	int rowOfPointer = 1, colOfPointer = 0;
	FILE* ptrW;
	LinkedList* list;
	int i;
	 
	 
	if( argc != 2 )
	{
		printf( "\n Please provide argument correctly: %s " 
		        "<file_name> \n\n", argv[0] );
	}
	else
	{
		
		/* Create a Generic Linked list */
		
		list = createLinkedList(); 
		
		setTheInterface(&array, row, column, rowOfPointer, colOfPointer);
		
		/* clear the terminal */
			
		system("clear");
		
		printTheInterface(array, row, column, &curValue, &curTotal);
		
		/* loop until user enter = */
		do
		{
			getInput(array, &row, &column, &rowOfPointer, &colOfPointer,
					&pressedKey, &curValue, &curTotal, &digit, &list);
			system("clear");
			printTheInterface(array, row, column, &curValue, &curTotal);
			
		}while(pressedKey != '=');
		

		/* Open the File to Write the result */
		
		ptrW = fopen(argv[1], "w");
		
		write( ptrW, &list, &curTotal );
		
		
		/* free malloc 2d Array from heap memory */
	
		for( i = 0 ; i < row ; i++)
		{
			free( array[i] );
		}
		
		free( array );
			
		/* Assign the pointer to NULL */
		
		array = NULL;
		
		
		/* Free the data(Struct) and LinkedList by passing Function pointer */
			
		freeLinkedList(list, &freeStruct);
		
		
	}
	 
	 return 0;
 }