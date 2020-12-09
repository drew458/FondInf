void triplicaElementi(int numeri[], int lunghezza){
	int triplicati[lunghezza];
	for(int i=0; i<lunghezza; i++){
		triplicati[i]=numeri[i]*3;
	}
	printf("La sequenza di numeri triplicata %c: ", 138);
	for(int i=0; i<lunghezza; i++){
		printf(" %d ", triplicati[i]);
	}
}