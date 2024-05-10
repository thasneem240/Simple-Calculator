/**************************************************************************
 * File: writeFile.c										  		  	  *
 * Author: Mr.A.S.M. Thasneem                          				      *
 * ID : 20535155														  *
 * Date Created: 01/11/2021                            				      *
 * Date Modified: 07/11/2021                              				  *               
 * Purpose: Write the result in to Output file.	  						  *
 **************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include "writeFile.h"
#include "input.h"

 void write( FILE* ptrW, LinkedList** list, int* totalValue )
 {
	void* data;
	calculation* calc; /* Struct pointer */
	int val;
	
	if(ptrW == NULL)
	{
		perror("Error opening the File");
	}
	else
	{
		if( (*list)->count == 0 || (*list)->count == 1 )
		{
			fprintf(ptrW, "%d\n", *totalValue);
		}
		else
		{
			do
			{
				/* Remove the first node in the LinkedList and get the data */
									
				data = removeStart(*list); 
									
				/* typecast void pointer to proper type */
									
				calc = (calculation*)data; 
									
				/* Get Entered Value */
				
				val = calc->valueEntered;
				
				if( (*list)->count >= 1 )
				{
					fprintf(ptrW, "%d + ", val);
				}
				else
				{
					/* When (*list)->count == 0 */
					
					fprintf(ptrW, "%d = %d\n", val, *totalValue);
				}
					
				/* free the malloc coordinate Struct from heap memory */
									
				free(calc);
			
			}while( (*list)->count != 0 );
								
		}
		
		if( ferror(ptrW) )
		{
			perror("Error Writing to file\n");
		}
		
		fclose(ptrW);
		ptrW = NULL;
		
	}
	
 }