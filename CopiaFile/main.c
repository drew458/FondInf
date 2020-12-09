#include <stdio.h>

/* funzione che copia un file di testo in un altro */
void copiaFile(FILE *fileIN, FILE *fileOUT) {
	int carattere;			// un carattere da leggere
	/* leggi un carattere alla volta */
	carattere = fgetc(fileIN);
	while(carattere!=EOF) {
		fputc(carattere, fileOUT);
		carattere = fgetc(fileIN);
	}
}

int main() {
	FILE *fpIN, *fpOUT;
	
	/* leggi i nomi dei file */
	char nomeIN[50];
	char nomeOUT[50];
	printf("Nome del file da copiare? ");
	scanf("%s", nomeIN);
	printf("Nome del file copia? ");
	scanf("%s", nomeOUT);

	/* copia i file */
	fpIN = fopen(nomeIN, "r");
	fpOUT = fopen(nomeOUT, "w");
	copiaFile(fpIN, fpOUT);
	fclose(fpIN);
	fclose(fpOUT);
}
