// ShellSprt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
void xuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%2d", a[i]);
	}
}
void ShellSort(int a[], int &n)
{
	int tmp;
	n = 12;
	for (int i = n / 2; i > 0; i = i / 2)
	{
		for (int j = i; j < n; j++)
		{
			for (int k = j - i; k >= 0; k = k - i)
			{
				if (a[k + i] >= a[k])
				{
				}
				else
				{
					tmp = a[k];
					a[k] = a[k + i];
					a[k + i] = tmp;
					
				}
				xuatMang(a, n);
				printf("\n");
			}
		}
	}
}

int main()
{
	int n = 12, left, mid, right;
	int a[12] = { 61,109,149,111,34,2,24,119,122,125,27,145};

	// GOI SHELLSORT

	ShellSort(a,n);
	printf("\n");
	printf("Da ShellSort : ");
	xuatMang(a, n);
	printf("\n");
    return 0;
}

