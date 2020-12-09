#include <stdio.h>
#include <string.h>

void asteriscoNonAlfabetico(char *stringa){
	int i=0;
	while(stringa[i]!='\0'){
		if((stringa[i]>='a' && stringa[i]<='z') || (stringa[i]>='A' && stringa[i]<='Z')){
			i++;
		}
		else{
			stringa[i]='*';
			i++;
		}
	}
}

void testAsteriscoNonAlfabetico(){
	/* stringa con tutte lettere */
	char stringa1[]="ciao";
	asteriscoNonAlfabetico(stringa1);
	printf("TestAlfabeticoNonMaiuscolo (\"ciao\") Atteso: \"ciao\" Calcolato: \"%s\" \n", stringa1);
	
	/* stringa con  uno spazio tra lettere*/
	char stringa2[]="ciao come va";
	asteriscoNonAlfabetico(stringa2);
	printf("TestAlfabeticoNonMaiuscolo (\"ciao come va\") Atteso: \"ciao*come*va\" Calcolato: \"%s\" \n", stringa2);
	
	/* stringa con  numeri, spazi e lettere*/
	char stringa3[]="Il 25 dicembre è natale";
	asteriscoNonAlfabetico(stringa3);
	printf("TestAlfabeticoNonMaiuscolo (\"Il 25 dicembre %c natale\") Atteso: \"il****dicembre****natale\" Calcolato: \"%s\" \n",138, stringa3);
}

int main(){
	char stringa[50];
	printf("Inserire una stringa\n");
	fgets(stringa, 50, stdin);
	stringa[strlen(stringa)-1]='\0';
	asteriscoNonAlfabetico(stringa);
	printf("La stringa modificata %c: %s\n", 138, stringa);
	testAsteriscoNonAlfabetico();
}

