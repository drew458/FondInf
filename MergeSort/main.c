#include <stdio.h>

/* funzione che fonde due array a e b dentro ad un terzo array c */
void merge(int * a, int l, int *b, int m, int *c) {
	// pre: l ed m sono la lunghezza di a e b
	int i=0;			// contatore per a
	int j=0;			// contatore per b
	/* prima fase: ci sono elementi da copiare da entrambi gli array */
	while(i<l && j<m) {
		/* copia da a */
		if(a[i]<=b[j]) {
			c[i+j]=a[i];
			i++;
		}
		/* copia da b */
		else {
			c[i+j]=b[j];
			j++;
		}
	}
	/* seconda fase: una delle due sequenza è stata copiata interamente */
	if(i>=l)	// la prima è finita
		for( ; j<m; j++) c[i+j]=b[j];
	else // la seconda è finita
		for( ; i<l; i++) c[i+j]=a[i];
}

/* funzione che implementa merge sort */
void mergeSort(int *array, int n) {
	// pre: n è la lunghezza di array
	/* PASSO RICORSIVO: n>=2 */
	if(n>=2) {
		/* crea la prima sequenza e ordinala */
		int l = (n+1)/2;
		int a[l];			
		for(int i =0; i<l ; i++) a[i] = array[i];
		mergeSort(a,l);
		/* crea la seconda sequenza e ordinala */
		int m = n/2;
		int b[m];			
		for(int i =0; i<m ; i++) b[i] = array[l+i];
		mergeSort(b,m);
		/* fondi le sequenze */
		merge(a,l,b,m,array);
	}
	/* PASSO BASE: n<=1, la sequenza è ordinata */
}

/* funzione principale */
int main() {
	int *array= malloc(100000* sizeof(int));
	for(int i = 0; i<100000;i++)
		array[i] = 100000-i;
	mergeSort(array, 100000);
	for(int i=99900; i<100000; i++)
		printf("%d\n ",array[i]);
}
