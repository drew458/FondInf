#include <stdio.h>
#include <stdlib.h>

struct Reali {
	int intera;
	int decimale;
};

struct Nodo {
	struct Reali reali;
	struct Nodo* next;
};

typedef struct Reali REA;
typedef struct Nodo* NODO;


/*      STAMPE       */

/* per stampare un numero reale */
void stampaNumeroReale(REA reali) {
	printf("%d.%d", reali.intera, reali.decimale);
}

/* per stampare una lista di numeri reali */
void stampaNumeriReali(NODO lista) {
	
	/* lista vuota? */
	if(lista==NULL)
		printf("La lista %c vuota\n\n", 138);
	else{
		printf("Ecco la lista di numeri reali: ");
		while(lista->next != NULL) {
			stampaNumeroReale(lista->reali);
			printf(", ");
			lista = lista->next;
		}
		stampaNumeroReale(lista->reali);
		printf("\n\n");
	}
	
}


/*      INSERIMENTO IN TESTA      */

/* per leggere un numero reale */
REA leggiNumero() {
	REA r;			//da leggere
	printf("Inserisci la parte reale del numero:  ");
	scanf("%d", &r.intera);
	do {
		printf("Inserisci la parte decimale: ");
		scanf("%d", &r.decimale);
		if(r.decimale<0) {
			printf("La parte decimale deve essere non negativa!\n");
		}
	}
	while(r.decimale<0);
	return r;
}


/* funzione che inserisce un nodo in testa alla lista, utilizzando *puntaHead (soluzione numero 2)*/
void inserimentoInTesta(NODO* puntaHead) {
	NODO nuovoNodo;										//il nuovo nodo
	nuovoNodo = malloc(sizeof(struct Nodo));			//allocazione nodo nell'heap
	
	/* riempi il campo dati */
	nuovoNodo->reali = leggiNumero();
	
	/* collega il nuovo nodo al successivo, tramite *puntaHead */
	nuovoNodo->next = *puntaHead;
	
	/* collega il nuovo nodo alla testa */
	*puntaHead = nuovoNodo;
	
	printf("Inserimento effettuato!\n\n");
}


/* inserimento di un numero reale in coda, utilizzando *puntaHead (soluzione numero 2) */
void inserimentoInCoda(NODO* puntaHead) {
	NODO nuovoNodo;			//il nuovo nodo
	nuovoNodo = malloc(sizeof(struct Nodo));
	
	/* riempi il campo dati */
	nuovoNodo->reali = leggiNumero();
	nuovoNodo->next = NULL; 
	
	/* collega il nodo al precedente, uso *puntaHead */
	if(*puntaHead == NULL)			//lista vuota?
		*puntaHead = nuovoNodo;		//il nuovo nodo diventa il primo
	else {
		NODO nodoCorrente = *puntaHead;
		while(nodoCorrente != NULL) 
			nodoCorrente = nodoCorrente->next;
		
		/* ora nodoCorrente è l'indirizzo dell'ultimo nodo della lista */
		nodoCorrente->next = nuovoNodo;
	}
	printf("Inserimento effettuato!\n\n");
}


/*      MAIN      */
int main() {
	int risposta=-1;			// per l'interazione con l'utente
	NODO head = NULL; 			// lista inizialmente vuota
	
	/* ciclo di interazione con l'utente */
	while(risposta!=0){
		printf("Ciao utente, cosa vuoi fare?\n");
		printf("1 = Inserimento di un numero reale in testa alla lista\n");
		printf("2 = Inserimento di un numero reale in coda alla lista\n");
		printf("3 = Stampa la lista\n");
		printf("0 = Termina il programma\n");
		scanf("%d", &risposta);
		
		if(risposta==1)
			inserimentoInTesta(head);
		else if(risposta==2)
			inserimentoInCoda(head);
		else if(risposta==3)
			stampaNumeriReali(head);
		else if(risposta==0)
			printf("Ciao!\n");
		else
			printf("Risposta non valida!\n");
	}
}