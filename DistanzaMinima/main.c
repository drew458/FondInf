#include <stdio.h>

int distanzaMinima(int interi[], int lunghezza){
	int distanza=0;
	int distanzalocale=0;
	if(interi[0]>interi[1]){
		distanza=interi[0]-interi[1];
	}
	else{
		distanza=interi[1]-interi[0];
	}
	for(int i=0; i<lunghezza; i++){
		if(interi[i]>interi[i+1]){
		distanzalocale=interi[i]-interi[i+1];
		}
		else{
			distanzalocale=interi[i+1]-interi[i];
		}
		if(distanzalocale<distanza){
			distanza=distanzalocale;
		}
	}
	return distanza;
}

int main(){
	int lunghezza;
	printf("Inserire il numero di elementi della sequenza \n");
	scanf("%d", &lunghezza);
	int interi[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("Inserire il %d%c elemento della sequenza\n", i+1, 167);
		scanf("%d", &interi[i]);
	}
	printf("La distanza minima %c pari a: %d\n", 138, distanzaMinima(interi,lunghezza));
	return 0;
}
