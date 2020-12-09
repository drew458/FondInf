#include <stdio.h>
#include <string.h>

struct Persona {
	char nome[50];
	char cognome[50];
	int eta;
};

int main(){
	FILE *fp = fopen("archivioDati", "wb");
	int fine = -1;
	struct Persona p;
	while(fine!=0) {
		/* acquisisci il nome */
		printf("Introduci il nome: ");
		fgets(p.nome, 50, stdin);
		(p.nome)[strlen(p.nome)-1] = '\0';
		
		/* acquisisci il cognome */
		printf("Introduci il cognome: ");
		fgets(p.cognome, 50, stdin);
		(p.cognome)[strlen(p.cognome)-1] = '\0';

		/* acquisisci l'età */
		printf("Quanti anni ha? ");
		scanf("%d%*c", &(p.eta));
		
		/* scrivi su file */
		fwrite(&p, sizeof(p), 1, fp);

		/* continuare? */
		printf("Altre persone (1=SI, 0=NO)? ");
		scanf("%d%*c", &fine);
	}
	fclose(fp);
}
