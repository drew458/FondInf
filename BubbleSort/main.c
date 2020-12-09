#include <stdio.h>

/* funzione che scambia le posizioni di due elementi */
void scambia(int *array, int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;		
}

/* funzione che implementa bubble sort */
void bubbleSort(int *array, int n) {
	int valida = 1;				// l'ultima passata ha cambiato qualcosa?
	int nonOrdinato = n-1;	// ultimo elemento non ordinato
	/* prosegui fino a che fai passate valide o non ne hai fatte n-1 */ 
	while(nonOrdinato>0 && valida) {
		valida = 0;
		/* fai una passata */
		for(int j=0; j<=nonOrdinato-1;j++)
			if(array[j+1]<array[j]) {
				scambia(array,j,j+1);
				valida = 1;
			}
		nonOrdinato--;		// hai ordinato almeno un elemento
	}
}

/* funzione principale */
int main() {
	int array[] = {1,2,3,4,5,6,7,8,9};
	bubbleSort(array, 9);
	for(int i=0; i<9; i++)
		printf("%d ",array[i]);
}
