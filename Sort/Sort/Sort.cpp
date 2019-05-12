#include "iostream"
#include "stdafx.h"
#include "conio.h"
using namespace std;

void HoanVi(int &a, int &b)
{
	int t;
	t = a;
	a = b;
	b = t;
}
void NhapMang(int a[], int &n)
{
	
	for (int i = 0; i < n; i++)
	{
		cout<<"phan tu thu a["<<i<<"]= ";
		cin >> a[i];
	}

}
void XuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
void SelectionSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		if (i != min)
		{
			HoanVi(a[min], a[i]);
			XuatMang(a, n);
		}
	}
}
void IntersectionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
		for (int j = i; j > 0; j--)
			if (a[j] < a[j - 1])
				HoanVi(a[j], a[j - 1]);
	XuatMang(a, n);

}
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j >= i; j--)
		{
			if (a[j] < a[j - 1])
			{
				HoanVi(a[j - 1], a[j]);
				cout << "Tu phan tu thu " << j << "va thu" << j + 1 << "\n";
				XuatMang(a, n);

			}
		}
	}
}

int main()
{
	int a[50], n;

	NhapMang(a, n);
	XuatMang(a, n);
	//cout << "Selection Sort"<<"\n";
	//SelectionSort(a, n);
	//system("cls");
	//cout << "Bubble Sort"<<"\n";
	//BubbleSort(a, n);
	SelectionSort(a, n);
	return 0;
}
