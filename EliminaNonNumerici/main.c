#include <stdio.h>
#include <string.h>

void eliminaNonNumerici(char *stringa){
	int i=0;			//variabile contatore
	int j=0;			//variabile contatore
	char temp;			//variabile ausiliaria
	int fermati=0;		//se vale 1, il ciclo si ferma
	
	/* scorro tutta la stringa */
	while(stringa[i]!='\0'){
		
		/* se è un carattere numerico, passa all'elemento successivo */
		if(stringa[i]>='0' && stringa[i]<='9'){
			i++;
		}
		
		/* se è un carattere non numerico, eliminalo */
		else{
			j=i;
			
			/* partendo dal carattere non numerico, fallo diventare ultimo elemento della stringa e poi eliminalo */
			while(stringa[i]!='\0' && !fermati){
				temp=stringa[j];
				stringa[j]=stringa[j+1];
				stringa[j+1]=temp;
				j++;
				
				/* quando l'indice supera la lunghezza della sequenza, fermati */
				if(j>strlen(stringa)){
					fermati=1;
				}
			}
			j=0;
			
			fermati=0;
		}
	}
}

void testEliminaNonNumerici(){
	/* stringa senza caratteri numerici */ 
	char stringa1[] = "ashgdj,;.)(mfndkf"; 
	eliminaNonNumerici(stringa1); 
	printf("Test eliminaNonNumerici(\"ashgdj,;.)(mfndkf\"): Atteso = \"\", Calcolato = \"%s\" \n",  stringa1);
	
	/* stringa con un solo carattere numerico alla fine */ 
	char stringa2[] = "ashgdj,;.)(mfndkf2"; 
	eliminaNonNumerici(stringa2); 
	printf("Test eliminaNonNumerici(\"2\"): Atteso = \"\", Calcolato = \"%s\" \n",  stringa2);
	
	/* stringa con un solo carattere numerico all'inizio */ 
	char stringa3[] = "3ashgdj,;.)(mfndkf"; 
	eliminaNonNumerici(stringa3); 
	printf("Test eliminaNonNumerici(\"3\"): Atteso = \"\", Calcolato = \"%s\" \n",  stringa3);
}

int main(){
	char stringa[50];
	printf("Inserire una stringa\n");
	fgets(stringa, 50, stdin);
	stringa[strlen(stringa)-1]='\0';
	eliminaNonNumerici(stringa);
	printf("La stringa modificata %c %s\n",138, stringa);
	testEliminaNonNumerici();
}