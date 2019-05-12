#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
typedef struct Day
{
	int ngay;
	int thang;
	int nam;
};
void Nhap(Day &n)
{
	printf("Nhap ngay: ");
	scanf_s("%d",&n.ngay);
	printf("Nhap thang: ");
	scanf_s("%d",&n.thang);
	printf("Nhap nam: ");
	scanf_s("%d",&n.nam);
}
void NhapMangNgay(Day a[], int &n)
{
	printf("Nhap vao so luong ngay thang nam muon them: ");
	scanf_s("%d",&n);
	for(int i=0; i<n;i++)
	{
		printf("Day la lan lap thu %d\n",i+1);
		Nhap(a[n]);
	}
}
void XuatMangNgay(Day a[], int n)
{ 
	for(int i=0;i<n;i++)
		printf("%d/%d/%d\n",a[i].ngay,a[i].thang,a[i].nam);
}
void TestNamNhuan(Day a[],int n)
{
	printf("Nhap nam de kiem tra nam nhuan: ");
	scanf_s("%d",&a[n].nam);
	if((a[n].nam % 4 == 0) && (a[n].nam % 100 !=0 ) || (a[n].nam % 400 ==0))
		printf("Nam %d la mot nam nhuan", a[n].nam);
	else
		printf("Nam %d khong la mot nam nhuan",a[n].nam);
}
void main()
{
	
	Day a[MAX];
	int n;
	
	
	NhapMangNgay(a,n);
	XuatMangNgay(a,n);
	TestNamNhuan(a,n);
	_getch();
}
