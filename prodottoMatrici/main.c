#include <stdio.h>

int main()
{
	int righe1;
	int colonne1;
	printf("Inserire il numero di righe della 1%c matrice\n", 167);
	scanf("%d", &righe1);
	printf("Inserire il numero di colonne della 1%c matrice\n", 167);
	scanf("%d", &colonne1);
	int matrice1[righe1][colonne1];         //Matrice numero 1
	
	/*Inserimento elementi matrice numero 1 */
	for(int i=0; i<righe1; i++){
		for(int j=0; j<colonne1; j++){
			printf("Inserire l'elemento di posto [%d , %d]\n", i+1, j+1);
			scanf("%d", &matrice1[i][j]);
		}
	}
	
	int righe2;
	int colonne2;
	printf("Inserire il numero di righe della 2%c matrice\n", 167);
	scanf("%d", &righe2);
	printf("Inserire il numero di colonne della 2%c matrice\n", 167);
	scanf("%d", &colonne2);
	int matrice2[righe2][colonne2];         //Matrice numero 2
	
	/*Inserimento elementi matrice numero 2 */
	for(int i=0; i<righe2; i++){
		for(int j=0; j<colonne2; j++){
			printf("Inserire l'elemento di posto [%d , %d] della 2%c matrice\n", i+1, j+1, 167);
			scanf("%d", &matrice2[i][j]);
		}
	}
	
	/* Prodotto tra le due matrici */
	int matriceProdotto[righe1][colonne2];
	for(int i=0; i<righe1; i++){
		for(int j=0; j<colonne2; j++){
			matriceProdotto[i][j]=0;
			for(int k=0; k<righe2; k++){
				matriceProdotto[i][j]+=matrice1[i][k]*matrice2[k][j];
			}
		}
	}

	/* Stampo sottoforma di matrice */
	printf("\n");
	printf("\nLa matrice prodotto %c:\n", 138);
	for(int i=0; i<righe1; i++){
		for(int j=0; j<colonne2; j++){
			printf("%5d", matriceProdotto[i][j]);
			printf("\n");
		}
	}
	return 0;
}
