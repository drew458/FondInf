#include <stdio.h>

/* funzione che conta i caratteri numerici in un file */
int numeroCaratteri(FILE *fp) {
	int numero=0;	// il numero di caratteri
 	char carattere;	// un carattere del file
	
	/* guarda i caratteri del file */
	do{
		carattere = fgetc(fp);
		/* carattere numerico? */
		if(carattere>='0' && carattere<='9')
			numero++;
	}
	/* fermati quando arrivi alla fine del file */
	while(carattere!=EOF);
	return numero;
}

int main() {
	FILE *fp1, *fp2;
	fp1 = fopen("numeroCaratteri.txt", "w");
	fputs("12345conto67890",fp1);
	fclose(fp1);
	fp2 = fopen("numeroCaratteri.txt", "r");
	printf("Il file contiene %d caratteri numerici", numeroCaratteri(fp2));
	fclose(fp2);
}
