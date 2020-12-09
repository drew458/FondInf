#include <stdio.h>
#include <stdlib.h>

struct Nodo {
	int numero;
	struct Nodo *next;
};

void stampaLista(struct Nodo* puntaNodo) {
	printf("Ecco la lista: ");
	while(puntaNodo != NULL) {
		printf("%d ", puntaNodo->numero);
		puntaNodo = puntaNodo -> next;
	}
}
		
struct Nodo *leggiLista() {
	int risposta; 
	printf("Ciao utente, leggiamo una bella lista di interi!\n");
	struct Nodo *head = NULL;		 	// testa della lista

	printf("La lista ha almeno un intero? (1=SI, 0=NO): ");
	scanf("%d", &risposta);
	/* lista vuota? */
	if(!risposta)
		printf("E' stato breve ma intenso!\n");
	else {
		
		/* allocazione e inizializzazione primo nodo */
		struct Nodo *puntaNodo = NULL; 					// puntatore ad un nodo generico
		puntaNodo = malloc(sizeof(struct Nodo));		// allocazione nodo nell'heap
		head = puntaNodo;										// il primo nodo è puntato dall'head
		printf("Inserisci il primo intero!\n");
		scanf("%d", &(puntaNodo -> numero)); 							
		
		/* allocazione e inizializzazione nodi successivi al primo */
		printf("La lista ha un altro intero? (1=SI, 0=NO): ");
		scanf("%d", &risposta);
		while(risposta) {
				puntaNodo -> next = malloc(sizeof(struct Nodo)); 		// allocazione nodo nell'heap
				puntaNodo = puntaNodo -> next;								// passa al nodo corrente
				printf("Inserisci l'intero!\n");
				scanf("%d", &(puntaNodo -> numero)); 							
				printf("La lista ha un altro intero? (1=SI, 0=NO): ");
				scanf("%d", &risposta);
		}
		
		/* campo puntatore ultimo nodo */
		puntaNodo -> next = NULL;
	}
	return head;
}


int main() {
	struct Nodo *head = NULL;
	head = leggiLista();
	stampaLista(head);
}	