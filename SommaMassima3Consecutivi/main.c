#include <stdio.h>

int sommaMassima(int interi[], int lunghezza){
	int somma;
	somma=interi[0]+interi[1]+interi[2];
	for(int i=3; i<lunghezza; i++) {
		/* la tripla attuale ha somma maggiore del massimo corrente? */
		if(interi[i-2]+interi[i-1]+interi[i]>somma)
			somma = interi[i-2]+interi[i-1]+interi[i];
	}
	return somma;
}

int main(){
	int lunghezza;
	printf("Inserire il numero di elementi della sequenza di numeri di cui si vuole calcolare la somma massima di 3 elementi consecutivi\n");
	scanf("%d", &lunghezza);
	int interi[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("Inserire il %d%c elemento della sequenza\n", i+1, 167);
		scanf("%d", &interi[i]);
	}
	printf("La somma massima di tre elementi consecutivi nella sequenza %c %d\n", 138, sommaMassima(interi, lunghezza));
	return 0;
}
