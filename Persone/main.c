#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*      STRUTTURE      */

struct Data {
	int giorno;
	int mese;
	int anno;
}

struct Persona {
	char nome[20];
	char cognome[20];
	struct Data DataNascita;
}

struct Nodo {
	struct Persona p;
	struct Nodo* next;
}

typedef struct Data DATA;
typedef struct Persona PERSONA;
typedef struct Nodo NODO;


/*       STAMPE       */

/* visualizzazione di una persona */
void stampaPersona(PERSONA p); {
	printf("Nome: %c\n", p.nome);
	printf("Cognome: %c\n", p.cognome);
	printf("Anno di nascita: %c / %c / %c\n", p.DataNascita.giorno, p.DataNascita.mese, p.DataNascita.anno);
}

/* visualizzazione di una lista di persone */
void stampaPersone(NODO lista) {
	/* lista vuota? */
	if(lista == NULL)
		printf("Lista vuota!\n\n");
	else {
		printf("Ecco la lista di persone: \n\n");
		while(lista != NULL) {
			stampaPersona(lista->p);
			lista = lista->next;
		}
	}
	printf("\n");
}


/*        INSERIMENTO        */

/* leggi i campi di una persona */
PERSONA insersciDati() {
	PERSONA per;
	printf("Inserire il nome: \n");
	scanf("%c", &per.nome);
	printf("Inserire il cognome: \n");
	scanf("%c", &per.cognome);
	printf("Inserire il giorno di nascita: \n");
	scanf("%d", &per.DataNascita.giorno);
	printf("Inserire il mese di nascita: \n");
	scanf("%d", &per.DataNascita.mese);
	printf("Inserire l'anno di nascita: \n");
	scanf("%d", &per.DataNascita.anno);
	
	return per;
}

/* inserimento in coda alla lista */
void inserisciCoda(NODO* puntaHead) {
	NODO nuovoNodo;
	nuovoNodo = malloc(sizeof(struct Nodo));
	
	/* riempi i campi del nuovo nodo */
	nuovoNodo->p = inserisciDati();
	nuovoNodo->next = NULL;
	
	/* collega il nuovo nodo al precedente, usa *puntaHead */
	if(*puntaHead==NULL)
		*puntaHead=nuovoNodo;
	else {
		NODO nodoCorrente = *puntaHead;
		while(nodoCorrente != NULL) 
			nodoCorrente = nodoCorrente->next;
		
		/* ora nodoCorrente è l'indirizzo dell'ultimo nodo della lista */
		nodoCorrente->next = nuovoNodo;
	}
	printf("Inserimento effettuato!\n\n");
}
