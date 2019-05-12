#include <stdio.h>
#include <conio.h>
void HoanVi(int *x, int *y)
{
	int t =*x; *x = *y; *y=t;
}
void main()
{
	int a =3;
	int b=6;
	HoanVi(&a,&b);
	printf("a: %d, b: %d",a,b);
}