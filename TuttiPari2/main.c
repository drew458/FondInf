#include <stdio.h>

/* funzione per decidere se la sequenza, a partire dall'indice parametro, 
 * contiene tutti numeri pari */

int tuttiPariRic(int sequenza[], int lunghezza, int indice) {
	// pre: lunghezza è la lunghezza di sequenza, indice è compreso fra 0 e lunghezza 
	int risultato;			// valore da restituire
	
	/* CASO BASE */
	if(indice==lunghezza)
		risultato = 1;
	/* PASSO RICORSIVO */
	else 
		/* verifica se l'elemento con l'indice dato dal parametro è pari e se il problema ha soluzione 
		 * positiva sulla sequenza a partire dall'elemento successivo */	
		risultato = (sequenza[indice]%2==0) && tuttiPariRic(sequenza,lunghezza,indice+1);
	
	return risultato;
} 

/* algoritmo ricorsivo per decidere se una sequenza contiene 
 * tutti numeri pari, realizzazione 2 */
int tuttiPari(int sequenza[], int lunghezza) {
	tuttiPariRic(sequenza,lunghezza,0);
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
