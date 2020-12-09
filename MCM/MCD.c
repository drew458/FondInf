int MCD(int n1,int n2,int n3,int n4,int r)
{
	int mcd;
	while(r!=0){
		n3 = n4;
		n4 = r;
		r = n3 % n4;
	}
	mcd = n4;
	return mcd;
}