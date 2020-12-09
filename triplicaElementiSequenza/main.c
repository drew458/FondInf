#include <stdio.h>
#include "headerTriplicaElementiSequenza.h"

int main()
{
	int lunghezza;
	printf("Inserire la lunghezza della sequenza di numeri che si vogliono triplicare\n");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("Inserire il %d%c elemento della sequenza\n", i+1, 167);
		scanf("%d", &sequenza[i]);
	}
	triplicaElementi(sequenza, lunghezza);
	printf("\n");
	return 0;
}
