#define _CRT_SECURE_NO_WARNINGS  

#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>

#include "MathUtilities.h"

struct TTimeBsdCodeLogicValues {int unsigned highValue; int unsigned lowValue;};
struct TTimeBsdCode{bool stTeached; int hz; int size; TTimeBsdCodeLogicValues *pulses; };

TTimeBsdCode myIR;
int *abc ;

void main()
{
	//-------------------------------------------------------------------------------------
	//printf("A melhor sequencia é: ");
	//int array0[10] = {500,1000,1500,0,0,0,0,0,69,69};
	//int array1[10] = {69,69,1,1,1,1,1,550,1100,1650};
	//int arrayBest[10] = {0,0,0,0,0,0,0,0,0,0};

	//int result = findBestSeqFrom2Lsts(10,10/*%*/,true,3,array0, array1, arrayBest);
	//_getch();
	//------------------------------------------------------------------------------------

	myIR.stTeached = 0;
	//myIR.pulses[0][0] = (unsigned int*)::malloc(sizeof(unsigned int)*100);
	//myIR.pulses[0][0] = (unsigned int*)::malloc(sizeof(unsigned int)*100);

	//(myIR.pulses[0].highValue) = 0;
	//myIR.pulses[0][1] = 1;
	//myIR.pulses[1][0] = 2;
	//myIR.pulses[1][1] = 3;
	//myIR.pulses[2][0] = 4;
	//myIR.pulses[2][1] = 5;
	//printf("%i\n",(myIR.pulses[0][0]) );
	//printf("%i\n",(myIR.pulses[0][1]) );
	//printf("%i\n",(myIR.pulses[1][0]) );
	//printf("%i\n",(myIR.pulses[1][1]) );
	//printf("%i\n",(myIR.pulses[2][0]) );
	//printf("%i\n",(myIR.pulses[2][1]) );
	//printf("%i\n",(myIR.pulses[3][0]) );

	//printf("%i\n",&(myIR.pulses[0][0]) );
	//printf("%i\n",&(myIR.pulses[0][1]) );
	//printf("%i\n",&(myIR.pulses[1][0]) );
	//printf("%i\n",&(myIR.pulses[1][1]) );
	//printf("%i\n",&(myIR.pulses[2][0]) );
	//printf("%i\n",&(myIR.pulses[2][1]) );
	//printf("%i\n",&(myIR.pulses[2][2]) );
	//printf("%i\n",&(myIR.pulses[3][0]) );
	/*_getch();*/

	myIR.pulses = (TTimeBsdCodeLogicValues*)::malloc(sizeof(TTimeBsdCodeLogicValues)*10);
	myIR.pulses[30].highValue = 15;
	_getch();
	//*abc = 0;

	//printf("%i\n",(abc) );
	//printf("%i\n",(abc + 1) );
	//printf("%i\n",*(abc + 2) );
	//printf("%i\n",*(abc + 3) );
	//_getch();
}

//void PerguntaNumeros(int *_lpiNumeros, int _iQtd);
//void OrganizaNumeros(int *_lpiNumeros, int _iQtd);
//
//void main()
//{
//	int iQtdade=0, *pt=NULL;
//	printf("Quantos numeros você deseja digitar?");
//	fflush(stdin);
//	scanf("%i", &iQtdade);
//	pt=(int*)::malloc(sizeof(int)*iQtdade);
//	PerguntaNumeros(pt,iQtdade);
//	OrganizaNumeros(pt,iQtdade);
//
//	for (int i=0; i<iQtdade; i++)
//	{
//		printf("%i\n",*(pt+i));
//	}
//	free(pt);
//	pt=NULL;
//
//	_getch();
//}
//
//void PerguntaNumeros(int *_lpiNumeros, int _iQtd)
//{
//
//	printf("Digite os numeros:\n");
//	for(int i=0; i < _iQtd; i++)
//	{
//		fflush(stdin);
//		scanf("%i", &(_lpiNumeros[i]));
//	}
//}
//
//void OrganizaNumeros(int *_lpiNumeros, int _iQtd)
//{
//	int aux;
//	for(int i=_iQtd-1; i > 0; i--)
//	{
//		for(int j=0; j < i; j++)
//		{
//			if(_lpiNumeros[j] > _lpiNumeros[j+1])
//			{
//				aux = *(_lpiNumeros+j); // is the same think that this = _lpiNumeros[j]
//				_lpiNumeros[j] = _lpiNumeros[j+1];
//				_lpiNumeros[j+1] = aux;
//				//printf("%i\n", aux);
//				//printf("%i\n", aux);
//			}
//		
//		}
//	}
//
//}