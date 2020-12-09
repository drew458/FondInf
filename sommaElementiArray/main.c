#include <stdio.h>
#include "headerSommaElementiArray.h"
int main()
{
	int dimensione; 
	int somma;
	printf("Inserire il numero di elementi della sequenza di numeri di cui si vuole calcolare la somma\n");
	scanf("%d", &dimensione);
	int numeri[dimensione];
	for(int i=0; i<dimensione; i++){
		printf("Inserire il %d%c elemento della sequenza\n", i+1, 167);
		scanf("%d", &numeri[i]);
	}
	somma=sommaElementi(numeri, dimensione);
	printf("\nLa somma dei numeri inseriti %c %d\n", 138, somma);
	return 0;
}
