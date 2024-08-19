void foo(char *x){
	USED(x);
}

void main(void)
{
	char xx[64*1024-8];

	foo(xx);
}
