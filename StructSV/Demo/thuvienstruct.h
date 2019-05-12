#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
#define MAX 100
typedef struct SinhVien
{
	int MSSV;
	char Ten[50];
	int NamSinh;
	char GioiTinh[10];
	float DiemTrungBinh;
};
void Nhap1SV(SinhVien &s); //create a element 

void Xuat1SV(SinhVien s);

void Them1SV(SinhVien a[], int &n);// Add a element to Array a[]

void ThemmSV(SinhVien a[], int &n);// Add m elements to Array a[]

void XuatMang(SinhVien a[], int n);// Add a SinhVien to Array

void LoadFile(SinhVien a[], int &n);

void Swap(SinhVien &a, SinhVien &b);

void BubbleSort(SinhVien a[], int &n);