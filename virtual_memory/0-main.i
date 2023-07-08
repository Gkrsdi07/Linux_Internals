# 1 "0-main.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "0-main.c"
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
