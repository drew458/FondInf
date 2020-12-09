#include <stdio.h>
#include <stdlib.h>

/* programma che legge una sequenza di interi positivi e poi la stampa;
    il programma deve terminare quando l'utente introduce il numero 0  */
int main() {
	int *array = malloc(sizeof(int));	// array
	int numero;								// numero da leggere
	int quanti=0;			// quanti numeri positivi sono stati letti

	printf("Introduci un intero positivo, digita 0 per terminare: ");
	scanf("%d", &numero);

	while(numero) {
		array=realloc(array,(quanti+1)*sizeof(int));
		array[quanti]=numero;
		quanti++;

		/* preparati per il prossimo giro */
		printf("Introduci un intero positivo, digita 0 per terminare: ");
		scanf("%d", &numero);
	}
	printf("\nEcco la sequenza di numeri positivi da te introdotta: ");
	for(int i=0;i<quanti;i++)
		printf("%d ",array[i]);
}
