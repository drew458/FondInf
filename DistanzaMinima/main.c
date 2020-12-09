/* Scrivere un programma che prende in input una sequenza di interi e determina la minima distanza fra due interi 
consecutivi della sequenza utilizzando una funzione ricorsiva. La distanza fra due interi è data dal massimo meno il minimo fra i due. */

#include <stdio.h>

/* Programma che calcola la distanza tra due interi */
int distanzaInteri(int a, int b){
	int distanza=0;
	
	if(a>b)
		distanza=a-b;
	if(a<b)
		distanza=b-a;
	return distanza;
}

/* Programma che calcola la distanza minima tra due interi consecutivi in una sequenza */
int distanzaMinima(int interi[], int lung){
	int distanzamin;
	int distanzaminass;
	
	if(lung<=1)
		distanzaminass=0;
	else{
		distanzamin = distanzaInteri(interi[0], interi[1]);
		if(distanzamin<distanzaminass)
			distanzaminass=distanzamin;
		distanzaMinima(interi+1, lung-1);
	}
	return distanzaminass;
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
	printf("La distanza minima trovata tra due interi consecutivi all'interno della sequenza %c pari a: %d\n", 138, distanzaMinima(interi, lunghezza));
}
