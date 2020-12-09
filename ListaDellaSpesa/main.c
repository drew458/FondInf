/* Programma per creare una lista della spesa */

#include <stdio.h>

int main(){
	FILE *fp = fopen("Lista della spesa.txt", "w");
	int fine=0;
	char articolo[80]; 
	int numero; 
	while(!fine){
		printf("Che articolo vuoi comprare? ");
		fgets(articolo, 80, stdin);
		articolo[strlen(articolo)-1] = '\0';
		fprintf(fp, "%s", articolo);
		printf("Quanti te ne servono? ");
		scanf("%d%*c", &numero);
		fprintf(fp, "%d\n", numero);
		printf("Finito (1 = SI, 0 = NO) ?");
		scanf("%d%*c", &fine);
	}
	fclose(fp);
}
