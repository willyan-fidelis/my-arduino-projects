#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>

#include "MathUtilities.h"

void main()
{
	printf("A melhor sequencia é: ");
	//int array0[10] = {0,0,2,3,4,0,0,0,0,0};
	//int array1[10] = {2,3,4,1,1,1,1,1,1,1};
	int array0[10] = {500,1000,1500,0,0,0,0,0,69,69};
	int array1[10] = {69,69,1,1,1,1,1,550,1100,1650};
	int arrayBest[10] = {0,0,0,0,0,0,0,0,0,0};

	int result = findBestSeqFrom2Lsts(10,10/*%*/,true,3,array0, array1, arrayBest);
	_getch();
}