/**************************************************************************
 * File: setInterface.c										  		  	  *
 * Author: Mr.A.S.M. Thasneem                          				      *
 * ID : 20535155														  *
 * Date Created: 01/11/2021                            				      *
 * Date Modified: 07/11/2021                              				  * 
 * Purpose: Set the Interface of Calculator			  					  *
 **************************************************************************/
 
  #include <stdlib.h>
  #include "setInterface.h"
  #include "randomeness.h"
  
 void setTheInterface(char*** pArray, int row, int column, 
					 int rowOfPointer, int colOfPointer)
 {
	int i, j, number;
	int k = 0;
	char space = ' ';
	char** array = NULL;
	
	/* Keypad Structures */
	
	char keypadStruct1[] = {'+', '0', '=', '7', '8', '9', 
							'4', '5', '6', '1', '2', '3'};
							
	char keypadStruct2[] = {'1', '2', '3', '4', '5', '6',
							'7', '8', '9', '+', '0', '='};
	 
	array = (char**)malloc(sizeof(char*) * row);
	
	/* get random number(1 or 2) to select the keypad structures */
	
	number = getRandom(); 
	
	for( i = 0; i < row; i++)
	{
		array[i] = (char*)malloc(sizeof(char) * column );
	}
	
	for( i = 0; i < row; i++ )
	{
		for( j = 0; j < column; j++)
		{
			if( i % 2 == 0 )
			{
				/* select structures randomely with equal probability */
				
				if(number == 1)
				{
					array[i][j] = keypadStruct1[k];
				}
				else /* if number == 2 select keypadStruct2 */
				{
					array[i][j] = keypadStruct2[k];
				}
				
				k++;
			}
			else
			{
				array[i][j] = space;
			}
			
		}
	}
	
	array[rowOfPointer][colOfPointer] = '^';
	
	*pArray = array;
	
 }
