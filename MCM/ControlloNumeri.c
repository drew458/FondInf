int controlloNumeri(int n1,int n2,int n3,int n4,int r)
{
	if(n2>n1){
		r=n1;
		n1=n2;
		n2=r;
	}
	n3=n1;
	n4=n2;
	r=n3%n4;
	return n1,n2,n3,n4,r;
}