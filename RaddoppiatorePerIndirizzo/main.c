#include <stdio.h>

void raddoppiatore(int *x){
	*x = *x *2;
}

int main(){
	int x = 7;
	raddoppiatore(&x);
	printf("Ecco il doppio di 7: %d\n", x);
}
