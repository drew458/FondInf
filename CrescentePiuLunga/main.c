#include <stdio.h>

int crescentePiuLunga(int interi[], int lunghezza){
	int sottosequenza;
	int i,j;
	j=1;
	i=0;
	sottosequenza=0;
	while(i<lunghezza-1){
		while(j<lunghezza){
			if(interi[j]>interi[i]){
				sottosequenza++;
				i++;
				j++;
			}
			else{
				i++;
				j++;
				sottosequenza=0;
			}
		}
	}
	if(sottosequenza>0){
		sottosequenza++;
	}
	return sottosequenza;
}

int main(){
	int lunghezza;
	printf("Inserire la lunghezza della sequenza di numeri\n");
	scanf("%d", &lunghezza);
	int interi[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("Inserire l'elemento di posto %d della sequenza\n", i+1);
		scanf("%d", &interi[i]);
	}
	printf("La sotto-sequenza massima di numeri crescenti nella sequenza inserita ha %d elementi\n", crescentePiuLunga(interi, lunghezza));
	return 0;
}