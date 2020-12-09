#include <stdio.h>

/* algoritmo ricorsivo per decidere se una sequenza contiene 
 * tutti numeri pari, realizzazione 1 */

int tuttiPari(int sequenza[], int lunghezza) {
	// pre: lunghezza è la lunghezza di sequenza 
	int risultato;			// valore da restituire
	
	/* CASO BASE */
	if(lunghezza==0)
		risultato = 1;
	/* PASSO RICORSIVO */
	else 
		/* verifica se l'ultimo elemento è pari e se il problema ha soluzione positiva
		 * sulla sequenza meno l'ultimo elemento */	
		risultato = (sequenza[lunghezza-1]%2==0) && tuttiPari(sequenza,lunghezza-1);
	
	return risultato;
} 

/* funzione principale */
int main(int argc, char **argv) {
	int lunghezza;			// lunghezza della sequenza
	printf("Introduci la lunghezza della tua sequenza: ");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];
	for(int i=0; i<lunghezza; i++) {
		printf("Introduci un intero: ");
		scanf("%d", &sequenza[i]);
	}
	if(tuttiPari(sequenza,lunghezza))
		printf("Tutti pari!");
	else
		printf("Non tutti pari!");
}
