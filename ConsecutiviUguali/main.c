/* Scrivere un programma che prende in input una sequenza di interi e verifica se 
 * nella sequenza esistono due interi consecutivi uguali utilizzando una funzione ricorsiva. */

#include <stdio.h>

int consecutiviUguali(int interi[], int lung) {
	
	int esistono;
	
	/* CASO BASE */
	if(lung==0)
		esistono = 0;
	/* PASSO RICORSIVO */
	else
		if(interi[lung-1]==interi[lung-2])
			esistono = 1;
		else
			esistono = consecutiviUguali(interi, lung-1);
	
	return esistono;
}

int main(){
	int lunghezza;
	printf("Inserire la lunghezza della sequenza\n");
	scanf("%d", &lunghezza);
	int interi[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("Inserire un intero\n");
		scanf("%d", &interi[i]);
	}
	if(consecutiviUguali(interi, lunghezza))
		printf("Nella sequenza esistono due interi uguali consecutivi\n");
	else
		printf("Nella sequenza non esistono due interi uguali consecutivi\n");
}
