#include <stdio.h>

/* Programma che gestisce una sequenza di numeri reali; il programma
 * fornisce all'utente due funzionalità: la scrittura di una sequenza di numeri
 * reali su un file binario e la lettura di una sequenza di numeri reali da file. 
 * Per la seconda funzionalità il programma deve prima salvare i numeri reali 
 * su un array e quindi stamparli */

/* funzione per la scrittura */
void scriviSuFile() {
	int scelta;				// ancora numeri da scrivere?
	float reale;			// il numero da scrivere
	FILE* fp = fopen("numeriReali", "wb");
	if(fp==NULL)
		printf("Niente da fare!\n");
	else {
		do{
			printf("Vuoi introdurre un numero SI (1) o NO (0)?  ");
			scanf("%d", &scelta);
			if(scelta!=0) {
				printf("Introduci un numero:");
				scanf("%f", &reale);
				fwrite(&reale, sizeof(float), 1, fp);
			}
		}
		while(scelta!=0);
		fclose(fp);
	}
} 

/* la dimensione del file */
int dimensioneFile() {
		int n=0;		// numero di reali
		float numero;	// per memorizzare un numero
		FILE* fp = fopen("numeriReali", "rb");
		if(fp!=NULL) {
			while(fread(&numero,sizeof(float),1,fp)>0)
				n++;
			fclose(fp);
		}
		return n;
}

/* funzione per la lettura */
void leggiDaFile() {
	int n;				// la dimensione dell'array
	float reale;		// un numero
	n = dimensioneFile();
	FILE* fp = fopen("numeriReali", "rb");
	if(fp==NULL) {
		printf("Non ci sono numeri reali da leggere!");
	}
	else {
		if(n==0) 
			printf("Non ci sono numeri reali da leggere!");
		else {
			int i=0;				// contatore
			float reali[n];		// i numeri reali da leggere
			while(fread(&reale, sizeof(float), 1, fp)>0){
				reali[i]=reale;
				i++;
			}
			fclose(fp);
			printf("Ecco i numeri reali: ");
			for(i=0; i<n; i++)
				printf("%.2f  ", reali[i]);
		}
	}		
} 
 
/* funzione principale */
int main(){
	int scelta;				// cosa vuole fare l'utente
	printf("Ciao, che cosa vuoi fare? Digita 1 per scrivere su file e 2 per leggere da file.\n");
	scanf("%d", &scelta);
	/* invoca la funzione giusta */
	if(scelta==1)
		scriviSuFile();
	else
		if(scelta==2)
			leggiDaFile();
		else
			printf("Questa non era un'opzione...");
}
