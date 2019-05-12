#include "stdio.h"
#include "conio.h"
#include "iostream"
#include "time.h"
#include "stdlib.h"
using namespace std;
#define MAX 100
int NhapMang(int a[], int &n)
{
	cout<<"Vui long nhap vao so luong phan tu: ";
	cin >>n;
	if(n<0||n>MAX) 
		return -1;
	else 
	{
		srand(time(0));
		
		for(int i=0;i<n;i++)
			a[i]=rand()%100;
	}
}
void XuatMang(int a[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<endl;
}
void Swap(int &a, int &b)
{
	int t=a;
	a=b;
	b=t;
}
void SelectionSort(int a[], int n)
{
	for(int i=0; i<n-1;i++)
	{
		int min =i;
		for(int j = i+1;j<n;j++)
		{
			if(a[j]>a[min])
				min = j;
			if(min!=j)
				Swap(a[j],a[min]);
		}
	}
}
void BubbleSort(int a[], int n)
{
	for(int i=0; i<n-1;i++)
	{
		for(int j=n-1;j>=i+1;j--)
		{
			if(a[j]<a[j-1])
				Swap(a[j-1],a[j]);
		}
	}
}
int BinarySearch(int a[],int fr, int to, int x)
{
	if(fr>0) 
		return -1;
	int mid = (fr+to)/2;
	if(x==a[mid]) 
		return mid;
	if(x>a[mid]) 
		return BinarySearch(a,mid+1,to,x);
	else 
		return BinarySearch(a,fr,mid-1,x);
}
void ShellSort(int a[], int &n)
{
	int tmp;
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
			}
		}
	}
}

void main()
{
	int a[MAX];
	int n;
	NhapMang(a,n);
	XuatMang(a,n);
	cout<<"Sap xep theo chieu tang dan cua cac phan tu"<<endl;
	//SelectionSort(a,n);
	//BubbleSort(a,n);
	ShellSort(a,n);
	XuatMang(a,n);
	int x;
	cout<<"Nhap vi tri x can tim: ";
	cin>>x;
	cout<<"Binary Search"<<endl;
	cout<<BinarySearch(a,0,n-1,x)<<endl;
	_getch();
}