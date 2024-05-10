#ifndef INPUT_H
#define INPUT_H

#include "linkedlist.h"

void getInput(char** array, int* row, int* column, int* rowOfPointer,
		int* colOfPointer, char* pressedKey, int* value, int* total,
		int* digit, LinkedList** list);


typedef struct
{
	int valueEntered;
	
}calculation;

#endif