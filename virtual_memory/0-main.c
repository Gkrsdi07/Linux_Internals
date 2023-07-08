void swap(int *x,int*y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}



int main()
{

	int a=10,b=20;
	swap(&a,&b);
	return 0;
}
