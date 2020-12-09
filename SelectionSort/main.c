#include <stdio.h>

/* funzione che scambia le posizioni di due elementi */
void scambia(int *array, int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;		
}

/* funzione che implementa selection sort */
void selectionSort(int *array, int n) {
	// pre: n è la lunghezza di array
	int minimo;		// valore minimo
	int indice;	  		// indice del minimo
	/* per tutti gli indici fino al penultimo */
	for(int i=0; i<= n-2; i++) {
		/* trova l'elemento minimo fra quelli con indice  compreso fra i e n-1 */
		indice = i;
		minimo = array[i];
		for(int j=i+1; j<= n-1; j++) {
			if(array[j]< minimo) {
				minimo = array[j];
				indice = j;
			}
		}
		/* hai trovato l'elemento minimo, mettilo nella sua posizione definitiva */ 
		scambia(array,i,indice);
	}	
}

/* funzione principale */
int main() {
	int array[] = {5,3,-2,9,7};
	selectionSort(array, 5);
	for(int i=0; i<5; i++)
		printf("%d ",array[i]);
}
