#include <stdio.h>
#include <math.h>

int decodifica(int interi[], int lunghezza){
	int decimale;
	int esponente;
	int j;
	j=lunghezza-1;
	for(int i=0; i<lunghezza; i++){
		esponente=pow(2,i);
		decimale+=((interi[j])*((esponente)));
		j--;
	}
	return decimale;
}

int main(){
	int lunghezza;
	printf("Inserire la lunghezza della sequenza di numeri\n");
	scanf("%d", &lunghezza);
	int interi[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("Inserire l'elemento di posto %d della sequenza\n", i+1);
		scanf("%d", &interi[i]);
			if(interi[i]!=1 && interi[i]!=0){
				printf("Il numero inserito non %c binario!\n", 138);
				printf("Inserire di nuovo il numero\n\n");
				i--;
			}
	}
	
	printf("Il numero binario ");
	for(int i=0; i<lunghezza; i++){
		printf("%d", interi[i]);
	}
	printf(" %c uguale a %d in forma decimale\n", 138, decodifica(interi, lunghezza));
	return 0;
}