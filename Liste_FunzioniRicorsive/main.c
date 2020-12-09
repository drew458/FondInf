#include <stdio.h>
#include <stdlib.h>

struct Nodo {
	int numero;
	struct Nodo *next;
};

/* funzione che legge una lista */
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

/*********************************************************
 ************************ STAMPA **************************
 *********************************************************/ 

/* stampa ricorsiva di una lista */
void stampaLista(struct Nodo *nodo) {
	/* CASO BASE */
	if(nodo == NULL)
		printf("\n");
	/* PASSO RICORSIVO */
	else {
		printf("%d ", nodo->numero);
		stampaLista(nodo->next);
	}
}

/*********************************************************
 ************************ LUNGHEZZA **********************
 *********************************************************/ 

/* funzione che calcola il numero di elementi di una lista ricorsivamente */
int lunghezza(struct Nodo* nodo) {
	int length;
	
	/* CASO BASE */
	if(nodo == NULL)
		length = 0;
	/* PASSO RICORSIVO */
	else 
		length=1+lunghezza(nodo->next);
	return length;
}

/*********************************************************
 ************************ OCCORRENZE *********************
 *********************************************************/ 

/* funzione che calcola il numero di occorrenze di un elemento ricorsivamente */
int numeroOccorrenze(struct Nodo* nodo, int valore) {
	int numero;
	
	/* CASO BASE */
	if(nodo == NULL)
		numero = 0;
	/* PASSO RICORSIVO */
	else 
		numero=(nodo->numero == valore)+numeroOccorrenze(nodo->next, valore);
	return numero;
}

/*********************************************************
 ************************ COPIA ***************************
 *********************************************************/ 

/* funzione che copia una lista e restituisce l'indirizzo della nuova lista */
struct Nodo *copia(struct Nodo* nodo) {
	struct Nodo *ris;			// valore da restituire
	/* CASO BASE */
	if(nodo==NULL)
		ris = NULL;
	/* PASSO RICORSIVO */
	else {
		/* alloca memoria e poi copia il nodo corrente dentro al nuovo */
		ris = malloc(sizeof(struct Nodo));
		ris -> numero = nodo -> numero;
		ris -> next = copia(nodo->next);
	}
	return ris;
}

/*********************************************************
 ************************ CANCELLAZIONE ******************
 *********************************************************/ 

/* funzione dealloca una lista dalla memoria */
void dealloca(struct Nodo** puntaNodo) {
	/* nel caso base *puntaNodo == NULL e non deve essere fatto niente */
	
	/* PASSO RICORSIVO */
	if(*puntaNodo != NULL) {
		dealloca(&((*puntaNodo)->next));
		free(*puntaNodo);
		*puntaNodo = NULL;
	}
}		

/*********************************************************
 ************************ CONCATENAZIONE ******************
 *********************************************************/ 

/* funzione che concatena due liste e restituisce un puntatore al primo elemento  */
struct Nodo *concatena(struct Nodo *head1, struct Nodo *head2) {
	/* se la seconda lista è vuota non deve essere fatto nulla */
	if(head2 != NULL) {
		/* se la prima lista è vuota, la concatenazione è pari alla seconda lista */
		if(head1 == NULL) 
			head1 = head2;
		/* se la prima lista non è vuota elimina il primo elemento e ricorri */
		else 
			head1->next = concatena(head1->next, head2);
	}
	return head1;								
}

/*********************************************************
 ************************ MAIN ****************************
 *********************************************************/ 

int main() { 
	struct Nodo *head = leggiLista();
	printf("Ecco la lista : ");
	stampaLista(head);
	printf("La lista contiene %d elementi!\n", lunghezza(head));
	printf("La lista contiene %d elementi uguali a 7!\n", numeroOccorrenze(head, 7));
	struct Nodo *head2 = copia(head);
	printf("Ecco una copia della lista : ");
	stampaLista(head2);
	dealloca(&head2);
	printf("La lista contiene ora %d elementi!\n", lunghezza(head2));
	head2 = leggiLista();
	head = concatena(head, head2);
	printf("Ecco la lista : ");
	stampaLista(head);
}	