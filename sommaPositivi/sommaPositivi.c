int sommaPositivi(int interi[], int lunghezza){
	int somma=0
	for(int i=0; i<lunghezza; i++){
		if(interi[i]>0){
			somma+=interi[i];
		}
		printf("La somma nel ciclo numero %d %c pari a %d", i, 138, somma);
	}
	return somma;
}