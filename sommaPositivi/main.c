#include <stdio.h>
#include "HeaderSommaPositivi.h"

int main()
{
	int dimensione; 
	int somma=0;
	printf("Inserire il numero di elementi della sequenza di numeri di cui si vuole calcolare la somma\n");
	scanf("%d", &dimensione);
	int numeri[dimensione];
	for(int i=0; i<dimensione; i++){
		printf("Inserire il %d%c elemento della sequenza\n", i+1, 167);
		scanf("%d", &numeri[i]);
	}
	somma=sommaPositivi(numeri, lunghezza);
	printf("La somma tra gli elementi positivi dell'array %c pari a: \n", 138);
	return 0;
}
