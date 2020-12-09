#include <stdio.h>
#include <stdlib.h>

/*      STRUTTURE     */

struct Intervallo {
	int a;
	int b;
};

typedef struct Intervallo INTER;

struct Nodo {
	struct Intervallo intervallo;
	struct Nodo* next;
};

typedef struct Nodo* NODO;


/*     STAMPE     */

/* per stampare un intervallo */
void stampaIntervallo(INTER intervallo) {
	for(int i=0; i<intervallo.a; i++){
		printf(" ");
	}
	
	for(int i=0; i<intervallo.b; i++){
		printf("-");
	}
}

/* per stampare una lista di intervalli */
void stampaIntervalli(NODO lista) {
	NODO nodo;
	nodo = lista->next;			//supero il primo nodo fittizio
	
	/* lista vuota? */
	if(lista==NULL) 
		printf("La lista %c vuota\n", 138);
	else {
		printf("**************\n");
		printf("Ecco gli intervalli nella lista: \n");
		printf("**************\n");
		while(lista  != NULL) {
			stampaIntervallo(lista->intervallo);
			nodo = nodo->next;
		}
		printf("**************\n\n");
	}
}


/*      INSERIMENTO IN TESTA       */

/* per leggere un intervallo */
INTER leggiIntervallo() {
	INTER i;			//da leggere
	do {
		printf("Introduci l'estremo sinistro dell' intervallo: ");
		scanf("%d", &i.a);
		if(i.a<0)
			printf("L'estremo introdotto %c negativo!", 138);
	}
	while(i.a<0);
	do {
		printf("Introduci l'estremo destro dell'intervallo: ");
		scanf("%d", &i.b);
		if(i.b<i.a)
			printf("L'estremo destro deve essere maggiore o uguale all'estremo sinistro!");
	}
	while(i.b<i.a);
	return i;
}


/* funzione che inserisce un nodo in testa alla lista */
void inserimento(NODO head) {
	NODO nuovoNodo;										//nuovo nodo
	nuovoNodo = malloc(sizeof(struct Nodo));			//allocazione memoria nuovo nodo
	
	/* riempi il campo dati */
	nuovoNodo->intervallo = leggiIntervallo();
	nuovoNodo->next = NULL; 
	
	/* collega il nuovo nodo al successivo */
	nuovoNodo->next = head->next;
	
	/* collega il nuovo nodo al nodo fittizio */
	head->next = nuovoNodo;
	
	printf("Inserimento effettuato!\n\n");
}


/*      CANCELLAZIONE      */

/* funzione che cancella l'ultimo intervallo dalla lista */
void cancellazione(NODO lista) {
	
	/* c'è un intervallo da cancellare? */
	if(lista->next == NULL)
		printf("Niente da cancellare!\n\n");
	else {
		/* arriva in fondo alla lista */
		while(lista->next->next!=NULL){
			lista = lista->next;
		}
		/* OK sei in fondo: dealloca l'ultimo nodo ed il penultimo diventa ultimo */
		free(lista->next);
		lista->next = NULL;
		/* stampa messaggio e termina */
		printf("Intervallo cancellato!\n\n");
	}
}


/*      ORDINAMENTO       */

/* funzione che determina se un intervallo precede un altro */
int precede(INTER in1, INTER in2) {
	int prima;			// valore da restituire
	if(in1.a<in2.a || (in1.a==in2.a && in1.b<in2.b))
		prima = 1;
	else 
		prima = 0;
	return prima;
}

/* funzione che ordina gli elementi di una lista; implementa selection sort */
void ordina(NODO lista) {
	NODO primo;				// primo nodo parte non ordinata
	NODO minimo;			// minimo corrente
	NODO nodo;				// nodo corrente
	INTER inter;			// variabile ausiliaria (temp)
	
	/* se la lista è vuota niente da fare */
	if(lista->next != NULL) {
		/* il primo nodo non ordinato è il primo nodo non fittizio della lista */
		primo = lista->next;
		
		/* prosegui fino a che la parte ordinata ha almeno due nodi */
		while(primo->next != NULL) {
			/* inizializza il minimo a primo */
			minimo = primo;
			/* guarda tutti i nodi a partire dal successivo a primo e prosegui fino a 
			 * che non li hai visti tutti */
			for(nodo = primo->next; nodo!=NULL; nodo = nodo -> next) 
				/* minore del minimo ? */
				if(precede(nodo->intervallo, minimo->intervallo)) 
					minimo = nodo;

			/* adesso scambia i campi dati del minimo e del primo elemento non ordinato */
			inter = primo->intervallo;
			primo->intervallo = minimo->intervallo;
			minimo->intervallo = inter;
			
			/* fai scorrere il primo elemento non ordinato */
			primo = primo->next;
		}
		printf("Lista ordinata!\n\n");
	}
	else 
		printf("Non c'%c molto da ordinare!\n\n", 138);
}


/*     INTERSEZIONE     */

/* programma che verifica se due intervalli hanno intersezione non nulla */
int esisteIntersezioneADue(INTER in1, INTER in2) {
	/* due intervalli hanno intersezione vuota se il lato destro di uno dei due
	 * è a sinistra del lato sinistro dell'altro */
	return !(in1.b <in2.a) && !(in2.b <in1.a);
}


/* funzione che dati due intervalli ne calcola l'intersezione, assumendo che ci sia */
INTER intersezioneADue(INTER in1, INTER in2) {
	// pre: intersezione non vuota 
	INTER in;		// da restituire
	if(in1.a>=in2.a)
		in.a =in1.a;
	else 
		in.a =in2.a;
	if(in1.b<=in2.b)
		in.b =in1.b;
	else 
		in.b =in2.b;
	return in;
}


/* funzione calcola e stampa l'intersezione di una lista di intervalli */
void intersezione(NODO lista) {
	int esiste = 1;							// esiste l'intersezione?
	INTER inter;							// l'intersezione corrente
	NODO nodo = lista;						// per scorrere la lista
	
	if(nodo->next == NULL)		// lista vuota
		printf("Non ci sono intervalli\n\n");
	else {	// almeno un intervallo
		nodo = nodo->next;							// supera il nodo fittizio
		inter = nodo->intervallo;					// inizializza al primo intervallo della lista
		while(esiste && nodo->next!=NULL) {
			/* confronta il prossimo intervallo della lista con l'intersezione attuale */  
			nodo = nodo->next;
			if(esisteIntersezioneADue(nodo->intervallo, inter)) 
				inter = intersezioneADue(nodo->intervallo, inter);
			else
				esiste = 0;
		}
		/* se è sopravvissuto un intervallo, stampalo */
		if(esiste) {
			stampaIntervalli(lista);
			printf("Ecco l'intersezione!\n");
			stampaIntervallo(inter);
			printf("\n");
		} 
		else
			printf("L'intersezione degli intervalli nella lista %c vuota!\n\n", 138);
	}
}


/*       GESTIONE FILE        */

/* funzione per l'acquisizione di una lista su file, soluzione con nodo fittizio */
void acquisizione(NODO head) {
	FILE* fp = fopen("intervalli.dat", "rb");				// per la lettura di un file binario

	/* se non hai aperto il file non devi fare niente */
	if(fp!=NULL) {
		int letto;							// lettura OK o no
		NODO nodo;							// nodo corrente
		INTER inter;						// un intervallo
	
		/* collega la lista al nodo fittizio */
		nodo = head;
		/* adesso leggi gli intervalli */
		do {
			/* leggi un intervallo */
			letto = fread(&inter, sizeof(INTER), 1, fp);
			if(letto) {										// lo hai effettivamente letto?
				/* memorizza nell'heap il nodo corrispondente */ 
				nodo->next = malloc(sizeof(struct Nodo)) ;
				nodo->next->intervallo = inter;
				
				/* aggiorna l'ultimo nodo */
				nodo = nodo->next;
			}
			else // il file è terminato, setta il campo next dell'ultimo nodo 
				nodo -> next = NULL;
		}
		while(letto);
	}
	fclose(fp);
}


/* funzione per il salvataggio di una lista su file */
void salvataggio(NODO lista) {
	FILE* fp = fopen("intervalli.dat", "wb");									// per la scrittura di un file binario
	while(lista!= NULL) {																// procedi fino a che hai nodi 
		fwrite(&(lista->intervallo), sizeof(INTER), 1, fp);					// ciò che scrivi è un intervallo
		lista = lista->next;																// passa al prossimo nodo
	} 
	fclose(fp);
}


/*       MAIN         */

int main() {
	/* crea la lista con nodo fittizio */
	NODO lista = malloc(sizeof(struct Nodo));
	lista->next = NULL;
	/* acquisisci dati da file */
	acquisizione(lista);
	
	int risposta = -1;			// per interazione con utente
	
	while(risposta != 0) {
		/* richiedi un'operazione all'utente */
		printf("Che operazione vuoi svolgere?\n");
		printf("1 -> Inserisci un intervallo in testa alla lista\n");
		printf("2 -> Cancella l'ultimo intervallo della lista\n");
		printf("3 -> Visualizza la lista di intervalli\n");
		printf("4 -> Ordina la lista di intervalli\n");
		printf("5 -> Calcola l'intersezione fra gli intervalli\n");
		printf("0 -> Termina il programma\n");
		scanf("%d", &risposta);
		
		/* gestisci le operazioni dell'utente */
		if(risposta==1) {
			inserimento(lista);
		}
		else if(risposta==2) {
			cancellazione(lista);
		}
		else if(risposta==3) {
			stampaIntervalli(lista);
		}
		else if(risposta==4) {
			ordina(lista);
		}
		else if(risposta==5) {
			intersezione(lista);
		}
		else if(risposta==0) {
			printf("Adios!\n");
		}
		else printf("Selezione non valida!\n\n");
	}
	/* salva la lista sul file, ignorando il nodo fittizio */
	salvataggio(lista->next);
}