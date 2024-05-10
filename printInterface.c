/**************************************************************************
 * File: printInterface.c										  		  *
 * Author: Mr.A.S.M. Thasneem                          				      *
 * ID : 20535155														  *
 * Date Created: 01/11/2021                          				      *
 * Date Modified: 07/11/2021                               				  *               
 * Purpose: Print the visual interface of the Calculator		  		  *
 **************************************************************************/
 
 #include <stdio.h>
 #include "printInterface.h"
 
 void printTheInterface(char** array, int row, int column,
						int* value, int* total)
 {
	int i, j;
	 
	printf("\n---------");
	printf("\n|%7d|", *value);
	printf("\n---------\n\n");
	 
	 
	for( i = 0; i < row; i++ )
	{
		for( j = 0; j < column; j++)
		{
			printf("%c ", array[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\ncurrent total : %d\n\n", *total);
	
 }