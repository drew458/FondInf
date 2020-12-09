#include <stdio.h>

/* funzione che scambia le posizioni di due elementi */
void scambia(int *array, int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;		
}

/* funzione che partiziona una sequenza in due sequenze; la funzione restituisce
 * l'indice dell'ultimo elemento della prima sequenza */
int partition(int *a, int n){
	int i =0;				// per scandire la sequenza da sinistra
	int j =n-1;			// per scandire la sequenza da destra
	/* prosegui fino a che gli indici non si incontrano */
	while(i<j) {
		/* scorri da destra sugli elementi > a[0] */
		if(a[j]>a[0])
			j--;
		else 
			/* scorri da sinistra sugli elementi <= a[0] */
			if(a[i]<=a[0])
				i++;
			else 
				/* hai trovato un elemento a sinistra che dovrebbe
				 * stare a destra e viceversa: scambiali */
				 scambia(a,i,j);
	}
	return i;
}

/* funzione che implementa quick sort */
void quickSort(int *array, int n) {
	/* Se n<=1 l'array è ordinato */
	if(n>1) {
		/* partiziona l'array in due sequenze, una con indici 0, 1, ..., index contenente
		 * tutti gli elementi minori o uguali di array[0], una con indici index+1,...,n-1
		 * contenente tutti gli elementi maggiori di array[0] */
		int index = partition(array, n);
		
		/* metti il primo elemento al posto giusto */
		scambia(array,0,index);
		/* adesso l'elemento con indice index sta bene dove sta */
		
		/* ricorri sulla sottosequenza degli elementi fino a index-1 */
		quickSort(array,index); 
		
		/* ricorri sulla sottosequenza degli elementi da index+1 fino ad n-1*/
		quickSort(array+index+1,n-index-1);
	}
}

/* funzione principale */
int main() {
	int array[] = {-1,2,3,-4,5,-6,7,-8,9};
	quickSort(array, 9);
	for(int i=0; i<9; i++)
		printf("%d ",array[i]);
}
