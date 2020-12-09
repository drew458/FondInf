#include <stdio.h>
#include <stdlib.h>

int main() {
	/* creazione di un'area di memoria per contenere 10 interi */
	int *interi = (int *)malloc(10 * sizeof(int));

	if(interi==NULL) 	// creazione andata male
		printf("Niente memoria :(");
	else {
		/* memorizzazione interi da 1 a 10 */
		for(int i=0; i<10; i++)
			*(interi + i) = i+1;
		
		/* stampa interi da 1 a 10 */
		for(int i=0; i<10; i++)
			printf("%d ", *(interi+i));
			
		free(interi);
	}
}
