#include <stdio.h>
#include <stdlib.h>

int main(){
	int risposta;
	/* creazione di un'area di memoria per contenere 3 interi */
	int *interi = (int *) malloc(3*sizeof(int));

	if(interi==NULL)	printf("Niente memoria :(");
	else { 
		/* leggi 3 interi */
		printf("Inserisci tre interi!\n");
		for(int i=0; i<3; i++) scanf("%d", interi+i);

		/* altri 3 interi? */
		printf("vuoi introdurre altri tre interi? 1-->SI 0-->NO\n");
		scanf("%d",&risposta);
		if(risposta){
			interi = (int *)realloc(interi, 6*sizeof(int));
			if(interi==NULL)	printf("Niente memoria :(");
			else {
				/* leggi 3 interi */
				printf("Inserisci tre interi!\n");
				for(int i=0; i<3; i++) scanf("%d", interi+i+3);

				/* stampa tutto */
				printf("Ecco tutti gli interi: ");
				for(int i=0; i<6; i++) printf("%d ", *(interi+i));
			}
		}
		/* libera l'area di memoria */
		free(interi);
	}
}
