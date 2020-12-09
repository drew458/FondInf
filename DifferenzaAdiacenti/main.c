#include <stdio.h>

int differenzaAdiacenti(int interi[], int lunghezza){
	int i;
	i=1;
	int differenza1;
	differenza1=0;
	int differenza2;
	differenza2=0;
	int intermedio;
	intermedio=0;
	while(i<lunghezza-1 && !intermedio){
		differenza1=interi[i-1]-interi[i+1];
		differenza2=interi[i+1]-interi[i-1];
		if(differenza1==interi[i]){
			intermedio=1;
		}
		if(differenza2==interi[i] && !intermedio){
			intermedio=1;
		}
		else{
			differenza1=0;
			differenza2=0;
			i++;
		}
	}
	return intermedio;
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
	adiacenti=differenzaAdiacenti(interi,lunghezza);
	if(adiacenti==1){
		printf("\nEsistono tre numeri adiacenti  tali che il valore dell'elemento intermedio\n%c pari", 138); 
		printf(" alla differenza fra il valore dell'elemento precedente ed il valore\ndell'elemento successivo o alla differenza"); 
		printf(" fra il valore dell'elemento\nsuccessivo ed il valore dell'elemento precedente\n\n");
	}
	if(adiacenti==0){
		printf("\nNon esistono tre numeri adiacenti  tali che il valore dell'elemento intermedio\n%c pari", 138); 
		printf(" alla differenza fra il valore dell'elemento precedente ed il valore\ndell'elemento successivo o alla differenza"); 
		printf(" fra il valore dell'elemento\nsuccessivo ed il valore dell'elemento precedente\n\n");
	}
	return 0;
}