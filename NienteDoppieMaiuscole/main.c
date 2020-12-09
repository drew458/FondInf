#include <stdio.h>
#include <string.h>

void nienteDoppieMaiuscole(char *stringa){
	int i=0;
	int j;
	char temp;
	int fermati=0;
	while(stringa[i]!='\0'){
		if(stringa[i]>='A' && stringa[i]<='Z'){
			if(stringa[i]==stringa[i+1]){
				j=i;
				while(stringa[j]!='\0' && !fermati){
					temp=stringa[j];
					stringa[j]=stringa[j+1];
					stringa[j+1]=temp;
					j++;
					if(j>strlen(stringa)-1){
						fermati=1;
					}
				}
				fermati=0;	
			}
			else{
				i++;
			}
		}
		else{
			i++;
		}
	}
}

void testNienteDoppieMaiuscole(){
	/* stringa con una sola lettera maiuscola ripetuta */
	char stringa1[]="AAAAA";
	nienteDoppieMaiuscole(stringa1);
	printf("TestNienteDoppieMaiuscole (\"AAAA\") Atteso: \"A\" Calcolato: \"%s\"\n", stringa1);
	
	/* stringa con una lettera maiuscola ripetuta in mezzo ad altre lettere uguali */
	char stringa2[]="AabcAAAabcAA";
	nienteDoppieMaiuscole(stringa2);
	printf("TestNienteDoppieMaiuscole (\"AabcAAAabcAA\") Atteso: \"AabcAabcA\" Calcolato: \"%s\"\n", stringa2);
	
	/* stringa con nessuna lettera maiuscola */
	char stringa3[]="abcabcabc";
	nienteDoppieMaiuscole(stringa3);
	printf("TestNienteDoppieMaiuscole (\"abcabcabc\") Atteso: \"abcabcabc\" Calcolato: \"%s\"\n", stringa3);
}


int main(){
	char stringa[50];
	printf("Inserire una stringa\n");
	fgets(stringa, 50, stdin);
	stringa[strlen(stringa)-1]='\0';
	nienteDoppieMaiuscole(stringa);
	printf("La stringa modificata %c: %s\n", 138, stringa);
	testNienteDoppieMaiuscole();
}
