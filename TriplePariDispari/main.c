 /* SPECIFICA:
  * Input: Una sequenza di interi e la sua lunghezza
  * Pre-condizione: "lunghezza" è la lunghezza della sequenza "interi"
  * Output: Un intero uguale al numero di triple
  * Post-condizione: triple è 1 se ogni tripla di interi consecutivi 
  * 				nella sequenza contiene almeno un intero pari ed uno dispari, altrimenti è 0
  * Tipo di problema: Verifica universale
  */

#include <stdio.h>

/* funzione che prende come parametro un array di interi e la sua lunghezza 
 * e verifica se ogni tripla di interi consecutivi nella sequenza contiene 
 * almeno un numero pari ed un numero dispari */
int triplePariDispari(int interi[], int lunghezza) {
	int triple;				// vale 1 se ogni tripla di interi consecutivi contiene un intero pari ed uno dispari, altrimenti 0 
	int i;					// variabile contatore
	
	/* inizializzazione */
	triple = 1;
	
	/* guarda tutte le triple di elementi, se trova tre elementi consecutivi nessuno
	 * dei quali è pari o nessuno dei quali è dispari interrompi il ciclo */
	i=0;
	while(i<=lunghezza-3 && triple) {
		/* verifica se gli interi con indici i, i+1 e i+2 sono tutti pari o tutti dispari */
		if( (interi[i]%2==0 && interi[i+1]%2==0 && interi[i+2]%2==0) ||
			(interi[i]%2!=0 && interi[i+1]%2!=0 && interi[i+2]%2!=0))
			triple = 0;
		else
			i++;
	}
	return triple;
}

int main() {
	int lunghezza;		//lunghezza della sequenza
	
	printf("Inserisci il numero di elementi della sequenza\n");
	scanf("%d", &lunghezza);
	
	int interi[lunghezza];
	for(int i=0; i<lunghezza; i++) {
		printf("Inserisci l'intero di posto %d della sequenza\n", i);
		scanf("%d", &interi[i]);
	}

	if(triplePariDispari(interi,lunghezza))
		printf("Ogni tripla di interi consecutivi contiene un numero pari ed uno dispari dispari\n");
	else
		printf("Non tutte le triple di interi consecutivi contengono un numero pari o un numero dispari\n");
}
