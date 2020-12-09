#include <stdio.h>

/* funzione che implementa insertion sort */
void insertionSort(int *array, int n) {
	int temp;					// per salvare dati temporaneamente
	int indice;					// indice prossimo elemento da ordinare
	int posto;					// l'indice al quale disporre un elemento 
	/* riordina gli elementi dal secondo all'ultimo */
	for(indice = 1; indice<=n-1; indice++) {
		/* salva l'elemento non ordinato */
		temp = array[indice];
		/* vai alla ricerca del posto dove metterlo */
		posto = indice;		// il primo posto candidato è quello dove sta
		/* prosegui fintanto che non sei arrivato all'inizio dell'array oppure 
		 * hai trovato un elemento minore o uguale al corrente */
		while(posto>0 && array[posto-1]>temp) {
			array[posto]=array[posto-1];			// scorrimento
			posto--;
		}
		/* copia il contenuto di temp nella giusta posizione dell'array */
		array[posto]=temp;
	}
}

/* funzione principale */
int main() {
	int *array= malloc(100000* sizeof(int));
	for(int i = 0; i<100000;i++)
		array[i] = 100000-i;
	insertionSort(array, 100000);
	for(int i=99900; i<100000; i++)
		printf("%d\n ",array[i]);
}