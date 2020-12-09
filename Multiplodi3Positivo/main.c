/* Scrivere un programma che prende in input una sequenza di interi e verifica se
   nella sequenza esiste un intero positivo e multiplo di 3 utilizzando una funzione ricorsiva. */

#include <stdio.h>

int multiploDi3Positivo(int interi[], int lung){
	int esiste;
	
	if(lung==0)
		esiste=0;
	else
		if(interi[lung-1]>0 && interi[lung-1]%3==0)
			esiste=1;
		else
			esiste = multiploDi3Positivo(interi,lung-1);
	return esiste;
}

int main(){
	int lunghezza;
	printf("Inserire la lunghezza della sequenza di numeri\n");
	scanf("%d", &lunghezza);
	int interi[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("\nInserire un intero ");
		scanf("%d", &interi[i]);
	}
	if(multiploDi3Positivo(interi, lunghezza))
		printf("\nEsiste un intero positivo multiplo di 3 nella sequenza\n");
	else
		printf("\nNon esiste nessun intero positivo multiplo di 3 nella sequenza\n");
}