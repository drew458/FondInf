/* Scrivere un programma che prende in input una sequenza di interi e verifica se 
 * la sequenza è crescente utilizzando una funzione ricorsiva. */

#include <stdio.h>

int sequenzaCrescente(int interi[], int lung){
	int cresce;
	
	/* CASO BASE */
	if(lung<=1)
		cresce = 1;
	/* PASSO RICORSIVO */
	else
		if(interi[0]>=interi[1])
			cresce =  0;
		else
			cresce = sequenzaCrescente(interi+1,lung-1);

	return cresce;
}

int main(){
	int lunghezza;
	printf("Inserire la lunghezza della sequenza di numeri\n");
	scanf("%d", &lunghezza);
	int interi[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("\nInserire un intero ");
		scanf("%d", &interi[i]);
	}
	if(sequenzaCrescente(interi,lunghezza))
		printf("\nLa sequenza %c crescente\n\n", 138);
	else
		printf("\nLa sequenza non %c crescente\n\n", 138);
}
