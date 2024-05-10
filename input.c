/**************************************************************************
 * File: input.c										  		  		  *
 * Author: Mr.A.S.M. Thasneem                          				      *
 * ID : 20535155														  *
 * Date Created: 01/11/2021                            				      *
 * Date Modified: 07/11/2021                              				  *               
 * Purpose: Get input from user without pressing "enter key" everytime.	  *
 **************************************************************************/
 
 #include <stdio.h>
 #include <stdlib.h>
 #include "input.h"
 #include "terminal.h"
 
 void getInput(char** array, int* row, int* column, int* rowOfPointer, 
		int* colOfPointer, char* pressedKey, int* value, int* total,
		int* digit, LinkedList** list)
 {
	char ch;
	char space = ' ';
	int x;
	calculation* calc; /* Struct pointer */
	void* data;
	
	do
	{
		/* disable the terminal buffer temporarily */
		
		disableBuffer(); 
		
		/* get the input from user */
		
		scanf(" %c", &ch); 
		
		/* enable the terminal buffer */
		
		enableBuffer();
		
		switch (ch)
		{
			case 'w':
			
				if( (*rowOfPointer - 2) > 0 )
				{
					array[*rowOfPointer][*colOfPointer] = space; 
					*rowOfPointer = *(rowOfPointer) - 2; 
				}
				
			break;
			
			case 's':
			
				if( (*rowOfPointer + 2) < *row )
				{
					array[*rowOfPointer][*colOfPointer] = space; 
					*rowOfPointer = *(rowOfPointer) + 2; 
				}
			
			break;
			
			case 'a':
			
				if( (*colOfPointer - 1) >= 0 )
				{
					array[*rowOfPointer][*colOfPointer] = space; 
					*colOfPointer = *(colOfPointer) - 1; 
				}
			
			break;
			
			case 'd':
			
				if( (*colOfPointer + 1) < *column )
				{
					array[*rowOfPointer][*colOfPointer] = space; 
					*colOfPointer = *(colOfPointer) + 1; 
				}
			
			break;
			
			case 'e':
			
				*pressedKey = array[*(rowOfPointer)-1][*colOfPointer];
				
				if(*pressedKey == '+')
				{
					if(*value != 0)
					{
						*total = *total + *value;
						
						
						/* Create a New calculation struct */
						
						calc = (calculation*)malloc( sizeof(calculation) );
						
						/* Save Current value to calculation struct */
			
						calc->valueEntered = *value;
						
						/* Typecast calc into void pointer */
						
						data = (void*)calc; 
						
						/* Add the details into linkedList */
						
						insertStart(*list, data);
						
					}
					
					
					/* Reset the digit and the value */
					
					*value = 0;
					*digit = 0;
				}
				else
				{
					/* Check the digit */
						
					if( *digit < 7 && (*pressedKey != '=') )
					{
						if( !(*digit == 0 && *pressedKey == '0') )
						{
							/* Get the equivalent int value of character : 
								for example '2' will become integer 2 */
							
							x = *pressedKey - '0';
							
							*value = ( *value * 10 ) + x ;
							*digit = *digit + 1;
						}
					}
				}
				
			break;
			
			default:
			
				/* Output the warning message */
				
				printf("\n Please input w,s,a,d or e to"
						" control the Pointer !!\n" );
			break;
		}
		
		/* Assign Pointer current position */
		
		array[*rowOfPointer][*colOfPointer] = '^';
		
		
		
		/* loop until get the correct input */
	
	
	}while( !(ch == 'w' || ch == 's' || ch == 'a' || ch == 'd' || ch == 'e') ); 
	
	
	
 }