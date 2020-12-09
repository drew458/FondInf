#include <stdio.h>

/* funzione che ordina i contenuti di due variabili intere */
void minMax(int *a, int *b) {
	if(*a>*b) {
		int c=*a;
		*a=*b;
		*b=c;
	}
} 

/* funzione che legge due interi e li stampa in ordine crescente */
int main(){
	int min, max;
	printf("Introduci due interi\n");
	scanf("%d%d",&min,&max);
	minMax(&min,&max);
	printf("Eccoli in ordine: %d, %d", min, max);
}
 