#include "stdio.h"
#include "conio.h"
#include "iostream"
using namespace std;
#define MAX 100 
typedef struct SV
{
	int MSSV;
	char HT[30];
	int NamSinh;
	float dtb;
};
typedef struct Clist
{
	SV a[MAX];
	int n;
};
void Initialize(Clist &l)
{
	l.n=0;
}
bool IsEmpty(Clist l)
{
	return l.n==0;
}
bool IsFull(Clist l)
{
	return l.n==MAX;
}
void Nhap1SV(SV &s)
{
	cout<<"Nhap vao ma so sinh vien: ";
	cin>>s.MSSV;
	fflush(stdin);
	cout<<"Nhap vao ho ten sinh vien: ";
	gets_s(s.HT);
	cout<<"Nhap vao nam sinh: ";
	cin>>s.NamSinh;
	cout<<"Nhap vao diem trung binh cua sinh vien: ";
	cin>>s.dtb;
}

void Xuat1SV(SV s)
{
	cout<<"MSSV: "<<s.MSSV<<endl;
	cout<<"Ho Ten: "<<s.HT<<endl;
	cout<<"Nam Sinh: "<<s.NamSinh<<endl;
	cout<<"Diem trung binh: "<<s.dtb<<endl;
	cout<<"------------------------------------"<<endl;
}
void NhapMang(Clist &l)
{
	cin>>l.n;
	if(n==MAX)
	{
		cout<<"Lop da het cho";
		return;
	}
	
	for(int i=0;i<l.n;i++)
	{
		Nhap1SV(l.a[n]);
	}
	l.n++;
}
void XuatAll(Clist l)
{
	for(int i=0;i<l.n;i++)
		Xuat1SV(l.a[i]);
}
void main()
{
	Clist l;
	Initialize(l);
	SV s;
	int n;
	//Nhap1SV(s);
	//Xuat1SV(s);*/
	NhapMang(l);
	XuatAll(l);
	_getch();

}