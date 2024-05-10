/**************************************************************************
 * File: randomeness.c										  		  	  *
 * Author: Mr.A.S.M. Thasneem                          				      *
 * ID : 20535155														  *
 * Date Created: 01/11/2021                            				      *
 * Date Modified: 07/11/2021                              				  * 
 * Purpose: Get a Random Number between 1 and 2	inclusively with 		  *
 *			equal probability.											  *
 **************************************************************************/
 
#include <stdlib.h>
#include <time.h>
#include "randomeness.h"

int getRandom()
{
	int number;
	
	srand(time(NULL));
	
	number = rand() % 2 + 1;
	
	return number;
}