#include <stdio.h>

/* Funzione che restituisce 0 o 1 se un numero intero è primo oppure no */
int isPrimo(int numero)
{
	// Precodizioni: "numero" è un intero positivo
	int nessunDivisore;        // vale 1 fintanto che non hai trovato nessun divisore di un numero
	                           // vale 0 quando hai trovato un numero divisore del numero
	int i;                     // variabile contatore
	nessunDivisore=0;          // inizializzazione della variabile
	i=2;                       // il primo possibile divisore di un numero è 2
	while(i<=numero-1 && nessunDivisore)
		if(numero%i==0){
			nessunDivisore=0;
		}
		else
			i++;
	return nessunDivisore;     // restituisce il valore calcolato dalla funzione (ultima istruzione del corpo)
}
