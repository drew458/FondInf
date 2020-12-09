#include <stdio.h>

/* funzione che scambia le posizioni di due elementi */
void scambia(int *array, int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;		
}

/* funzione che dato un array ed un indice base trova l'indice
 * dell'elemento minimo fra quelli il cui indice è almeno base */
 int indiceMinimo(int *array, int base, int n) {
	 // pre: base >=0 e base <=n-1
	 int indice;		// valore da restituire
	 int minimo;	// valore elemento minimo

	 /* inizializzazioni */
	 indice= base;
	 minimo = array[base];
	 for(int i=base+1; i<=n-1; i++)
		if(array[i]<minimo){
			indice =i;
			minimo = array[i];
		}
			
	 return indice;
 }

/* funzione che implementa selection sort */
void selectionSort(int *array, int n) {
	/* per tutti gli indici fino al penultimo */
	for(int i=0; i<= n-2; i++) {
		/* metti l'elemento minimo nella sua posizione definitiva */ 
		scambia(array,i,indiceMinimo(array,i,n));
	}	
}

/* funzione principale */
int main() {
	int array[] = {4,3,5,3,-2,9,-4,10,7};
	selectionSort(array, 9);
	for(int i=0; i<9; i++)
		printf("%d ",array[i]);
}
