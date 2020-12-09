#include <stdio.h>

/* funzione che raddoppia gli elementi di un array */
void raddoppiatoreArray(int array[], int lunghezza){
	for(int i=0;i<lunghezza;i++)
		array[i] = array[i] *2;
}

/* funzione principale */
int main(){
	int x[] = {1,2,3,4,5};
	raddoppiatoreArray(x,5);
	printf("Ecco l'array: \n");
	for(int i=0; i<5; i++)
		printf("%d ", x[i]);
}
