#include <stdio.h>

int tripleSomma6(int interi[], int lunghezza){
	int i=0;				//Contatore
	int terna=0;			//Variabile booleana
	while(i<lunghezza-2){
		/* Controlla se nella terna esistono due elementi che sommati danno 6 */
		if(interi[i+1]+interi[i+2]==6 || interi[i]+interi[i+2]==6 || interi[i]+interi[i+1]==6){
			terna=1;
			i=lunghezza;
		}
		/* Se non esistono due elementi che sommati danno 6, azzera la variabile booleana e termina il ciclo */
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
	
	if(tripleSomma6(interi,lunghezza)==1){
		printf("Tutte le triple nella sequenza contengono due interi la cui somma %c 6\n", 138);
	}
	if(tripleSomma6(interi,lunghezza)==0){
		printf("Non tutte le triple nella sequenza contengono due interi la cui somma %c 6\n", 138);
	}
	return 0;
}
