#include <stdio.h>

int ugualeSommaPrecedenti(int interi[], int lunghezza){
	int i;
	int sommaprecedenti;
	int somma;
	sommaprecedenti=0;
	while(i<lunghezza-1 && !sommaprecedenti){
		for(int j=0; j<i; j++){
			somma+=interi[j];
		}
		if (somma==interi[i]){
			sommaprecedenti=1;
		}
		else{
			somma=0;
			i++;
		}
	}
	return sommaprecedenti;
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
	int sommaprecedenti;
	sommaprecedenti=ugualeSommaPrecedenti(interi, lunghezza);
	if(sommaprecedenti==0){
		printf("Non esiste nessun elemento uguale alla somma dei suoi elementi precedenti\n");
	}
	else{
		printf("Esiste un elemento uguale alla somma dei sui elementi precedenti\n");
	}
	return 0;
}
