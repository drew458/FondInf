#include <stdio.h>
#include <stdlib.h>

/* Funzione che calcola la potenza in maniera ricorsiva */
float potenza(float base, int esponente){
	float risultato;
	
	/* Caso Base */
	if(esponente==0)
		risultato=1;
	/* Passo Ricorsivo */
	else
		risultato=base * potenza(base, esponente-1);
	return risultato;
}


/* funzione che calcola il valore di un polinomio; i parametri della funzione sono
 * un array coefficienti i cui elementi sono di tipo float, un intero n che rappresenta
 * il grado del polinomio ed un intero x che rappresenta il valore della variabile */
float polinomio(float *coefficienti, int n, int x){
	int risultato;
	
	/* Caso Base */
	if(n==0)
		risultato = coefficienti[0];
	else
		risultato = coefficienti[n] * potenza(x,n) + polinomio(coefficienti, n-1, x);
	return risultato;
}

/* Funzione che stampa il polinomio */
void stampaPolinomio(float *coefficienti, int grado){
	
	/* Stampa i termini in ordine decrescente di grado */
	for(int i=grado; i>=2; i--){
		/* Voglio stampare solo i termini con coefficiente diverso da zero */
		if(coefficienti[i]!=0){
			if(coefficienti[i]>0)
				printf(" +%.2fx^%d", coefficienti[i], i);
			else
				printf(" %.2fx^%d", coefficienti[i], i);
		}
	}
	
	/* per il termine di grado 1 non vuoi stampare ^1 */
	if(coefficienti[1]!=0){
		if(coefficienti[1]>1)	
			printf(" +%.2fx", coefficienti[1]);
		else
			printf(" %.2fx", coefficienti[1]);
	}
	
	/* per il termine noto non vuoi stampare x */
	if(coefficienti[0]!=0){
		if(coefficienti[0]>0)
			printf(" +%.2f", coefficienti[0]);
		else
			printf(" %.2f", coefficienti[0]);
	}
	
	printf("\n");
}

int main(){
	int n=0;				//Grado del polinimio
	int risposta=1;			//risposta dell'utente
	float variabile;		//variabile da cui calcolare il polinomio
	
	/* Allocazione dinamica della memoria */
	float *coefficienti = (float *) malloc(sizeof(float));
	
	/* termine di grado 0 */
	printf("Introduci il termine noto: ");
	scanf("%f", coefficienti);
	
	while(risposta){
		/* Inserire altri monomi? */
		printf("\nVuoi inserire un altro monomio?\nDigitare 1 per SI\t\t\tDigitare 0 per NO\n");
		scanf("%d", &risposta);
		if(risposta){
			/* Ci sono altri monomi */
			n++;			//Aumento il grado del polinomio
			printf("Introduci il termine di grado %d: \n", n);
			
			/* Aumento la memoria */
			coefficienti = (float *) realloc(coefficienti, (n+1)* sizeof(float));
			
			/* Input da tastiera */
			scanf("%f", coefficienti+n);
		}
	}
	stampaPolinomio(coefficienti, n);
	printf("\nPer quale variabile calcolare il polinomio?\n");
	scanf("%f", &variabile);
	printf("\nIl polinomio vale %.2f\n", polinomio(coefficienti, n, variabile));
	free(coefficienti);
}