#include <stdio.h>

int tripleSomma10(int interi[], int lunghezza){
	int i=0;				//Contatore
	int terna=0;			//Variabile booleana
	while(i<lunghezza-2){
		/* Controlla se nella terna esistono due elementi che sommati danno 10 */
		if(interi[i+1]+interi[i+2]==10 || interi[i]+interi[i+2]==10 || interi[i]+interi[i+1]==10){
			terna=1;
			i++;
		}
		/* Se non esistono due elementi che sommati danno 10, azzera la variabile booleana e termina il ciclo */
		else{
			i=lunghezza;
			terna=0;
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
	
	if(tripleSomma10(interi,lunghezza)==1){
		printf("Tutte le triple nella sequenza contengono due interi la cui somma %c 10\n", 138);
	}
	if(tripleSomma10(interi,lunghezza)==0){
		printf("Non tutte le triple nella sequenza contengono due interi la cui somma %c 10\n", 138);
	}
	return 0;
}
