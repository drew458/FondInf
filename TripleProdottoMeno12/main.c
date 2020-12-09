#include <stdio.h>

int tripleProdottoMeno12(int interi[], int lunghezza){
	int i=0;
	int terna=0;
	while(i<lunghezza-2){
		if(interi[i+1]*interi[i+2]==(-12) || interi[i]*interi[i+2]==(-12) || interi[i]*interi[i+1]==(-12)){
			terna=1;
			i=lunghezza;			//Blocca il programma quando trova una terna con le condizioni richieste
		}
		else{
			i++;
		} 
	}
	return terna;
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
	
	if(tripleProdottoMeno12(interi,lunghezza)==1){
		printf("Almeno una tripla nella sequenza contiene due interi il cui prodotto %c -12\n", 138);
	}
	if(tripleProdottoMeno12(interi,lunghezza)==0){
		printf("Nessuna tripla nella sequenza contiene  due interi il cui prodotto %c -12\n", 138);
	}
	return 0;
}
