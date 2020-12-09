#include <stdio.h>
#include <stdlib.h>

/* funzione che alloca memoria per un intero e restituisce l'indirizzo dell'area
	di memoria allocata */
int *allocaMemoria(){
	int *intero = (int *) malloc(sizeof(int));
	return intero;
}

/* funzione che legge un valore introdotto dall'utente */
void leggiValore(int* variabile){
	printf("Introduci un intero: ");
	scanf("%d", variabile); 
}

/* funzione che riordina due valori così che il primo
 * sia più grande del secondo */
void riordina(int* a, int* b){
	int c;			//variabile ausiliaria
	if(*b > *a){
		c = *a;
		*a = *b;
		*b = c;
	}
}

/* funzione che calcola il quoziente della divisione intera */
void calcolaQuoziente(int* dividendo, int*divisore, int* quoziente){
	*quoziente = *dividendo / (*divisore); 
}

void calcolaResto(int* dividendo, int* divisore, int* resto){
	*resto = *dividendo % (*divisore);
}

int main(){
	int* a;	 			//Primo puntatore
	int* b;				//Secondo puntatore
	int* quoziente;		//Terzo puntatore
	int* resto;			//Quarto puntatore
	
	/* alloca memoria per 4 interi */
	a = allocaMemoria();
	b = allocaMemoria();
	quoziente = allocaMemoria();
	resto = allocaMemoria();
	
	/* Input da tastiera tramite funzione */
	leggiValore(a);
	leggiValore(b);
	
	/* Ordina i due valori in ordine di grandezza */
	riordina(a, b);
	
	/* Calcola quoziente e resto */
	calcolaQuoziente(a, b, quoziente);
	calcolaResto(a, b, resto);
	
	/* Stampo i risultati */
	printf("La divisione tra %d e %d ha come quoziente %d e come resto %d\n", *a, *b, *quoziente, *resto);
}