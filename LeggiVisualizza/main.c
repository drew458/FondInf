#include <stdio.h>

int main(int argc, char **argv)
{
	int righe;
	int colonne;
	printf("Inserire il numero di righe della matrice\n");
	scanf("%d", &righe);
	printf("Inserire il numero di colonne della matrice\n");
	scanf("%d", &colonne);
	int matrice[righe][colonne];         //Matrice
	int numero;                          //Variabile ausiliaria
	
	/*Inserimento elementi matrice */
	for(int i=0; i<righe; i++){
		for(int j=0; j<colonne; j++){
			printf("Inserire l'elemento di posto [%d , %d]\n", i+1, j+1);
			scanf("%d", &numero);
			
			/* Controllo se il numero inserito ha al massimo 3 cifre */
			if(numero<=999){
				numero=matrice[i][j];
			}
			else{
				printf("Il numero inserito non %c valido\n", 138);
				j--;
			}
		}
	}
	
	/* Stampo sottoforma di matrice */
	printf("\n");
	for(int i=0; i<righe; i++){
		for(int j=0; j<colonne; j++){
			printf("%5d", matrice[i][j]);
			printf("\n");
		}
	}
	return 0;
}
