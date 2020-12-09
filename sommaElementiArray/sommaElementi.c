int sommaElementi(int numeri[], int lunghezza){
	int somma=0;
	for(int i=0; i<lunghezza; i++){
		somma+=numeri[i];
	}
	return somma;
}