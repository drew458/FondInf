#include <stdio.h>

/* funzione per il calcolo dell'elemento con un certo 
 * indice nella sequenza di Fibonacci */
int Fib(int indice) {
	// pre: indice>=0
    int numero;			// il risultato 
	int prec, precprec; 	// due variabili aux
    
	if(indice==0 || indice==1)
		numero = 1; 
    else {
		/* i primi tre numeri sono 1,1,2 */
		precprec=1;
		prec=1;
		numero = 2;
		/* ogni altro numero è la somma dei precedenti */
		for(int i=3; i<=indice;i++) {
			precprec=prec;
			prec=numero;
			numero=prec+precprec;
		}
	}
	return numero;
}

/* programma per il calcolo dell'ennesimo numero di Fibonacci */
int main()
{
	int indice;
	printf("Io calcolo numeri nella sequenza di Fibonacci. Quale indice ti interessa?\n");
	scanf("%d", &indice);
	printf("L'elemento con indice %d vale %d", indice, Fib(indice));
} 

