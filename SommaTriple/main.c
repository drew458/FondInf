#include <stdio.h>

int sommaTriple(int interi[], int lunghezza){
	int adiacenti;
	adiacenti=0;
	int i=0;
	while(i<lunghezza-1){
		if(interi[i]==interi[i+1]+interi[i+2]){
			i=i+2;
			adiacenti++;
		}
		if(interi[i]==interi[i-1]+interi[i+1]){
			i=i+2;
			adiacenti++;
		}
		if(interi[i]==interi[i-1]+interi[i-2]){
			i=i+2;
			adiacenti++;
		}
	}
	return adiacenti;
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
	int adiacenti;
	adiacenti=sommaTriple(interi, lunghezza);
	if(adiacenti>=3){
		printf("Esistono terne di elementi adiacenti nella sequenza sono tali che uno dei\ntre elementi %c pari alla somma degli altri due\n",138);
	}
	else{
		printf("Non esistono terne di elementi adiacenti nella sequenza sono tali che uno dei\ntre elementi %c pari alla somma degli altri due\n",138);
	}
	return 0;
}
