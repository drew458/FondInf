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
	/* PASSO RICORSIVO */
	if(n>1)	{
		scambia(array,0,indiceMinimo(array,0,n));
		selectionSort(array+1,n-1);
	}
	/* NEL CASO BASE n<=1 L'ARRAY E' GIA' ORDINATO */
}

/* funzione principale */
int main() {
	int array[] = {4,3,5,3,-2,9,-4,10,7};
	selectionSort(array, 9);
	for(int i=0; i<9; i++)
		printf("%d ",array[i]);
}
