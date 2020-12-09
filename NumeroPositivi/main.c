/* Scrivere un programma che prende in input una sequenza di interi e calcola e restituisce il numero di valori positivi nella sequenza. 
 * Definire una funzione ricorsiva per il calcolo del numero di elementi positivi in una sequenza. */

#include <stdio.h>

int numeroPositivi(int interi[], int lung){
	int pos;
	if(lung==0)
		/* Caso Base */
		pos=0;
	else
	/* Passo Ricorsivo */
		if(interi[lung-1]>0)
			pos = 1+numeroPositivi(interi, lung-1);
		else
			pos=numeroPositivi(interi, lung-1);
			
	return pos;
}

int main(){
	int lunghezza;
	printf("Inserire la lunghezza della sequenza di numeri\n");
	scanf("%d", &lunghezza);
	int interi[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("Inserire un intero\n");
		scanf("%d", &interi[i]);
	}
	printf("Ci sono %d numeri postivi all'interno della sequenza\n", numeroPositivi(interi, lunghezza));
} 