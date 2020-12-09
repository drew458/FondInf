#include <stdio.h>

/* funzione per il calcolo del fattoriale di un numero */
int recFatt(int n) {
	// pre: n>=1
	printf("Sto iniziando un'esecuzione con input %d\n", n);
	int fatt;		// il risultato
    if (n==1)
		fatt = 1; 
    else 
		fatt = n * recFatt(n-1);
	printf("Sto terminando l'esecuzione con input %d e output %d\n", n, fatt);
    return fatt;
}

/* programma per il calcolo del fattoriale */
int main()
{
	int numero;
/*	printf("Io calcolo fattoriali. Di che numero vuoi il fattoriale?\n");
	scanf("%d", &numero);
	printf("Il fattoriale vale %d", recFatt(numero));*/

	printf("\nIl fattoriale di 4 vale %d\n", recFatt(4));
}

