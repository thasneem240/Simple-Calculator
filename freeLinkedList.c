/**************************************************************************
 * File: freeLinkedList.c										  		  *
 * Author: Mr.A.S.M. Thasneem											  *
 * ID : 20535155														  *
 * Date Created: 01/11/2021                            				      *
 * Date Modified: 07/11/2021                              				  *               
 * Purpose: Free the memory of calculation Struct from Linked List	  	  *
 **************************************************************************/
#include <stdlib.h>
#include "freeLinkedList.h"
#include "input.h"

void freeStruct( void* data )
{
	calculation* calc;
	calc = (calculation*)data;
	free(calc);
}