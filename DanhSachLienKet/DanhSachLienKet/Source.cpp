#include "stdio.h"
#include "iostream"
#include "conio.h"
#include "stddef.h"
#include "stdlib.h"
using namespace std;
typedef struct Xe
{
	char BienSo[10];
	char Tu[10];
	char Den[10];
	int GiaThanh;
};
typedef struct Node
{
	Xe info;
	Node* pNext;
};
typedef struct List
{
	Node* pHead;
};
void Initialize (List &l)
{
	l.pHead = NULL;
}
bool IsEmpty(List l)
{ 
	return l.pHead == NULL;
}
Node* CreateNode(Xe x)
{
	Node* p = new Node;
	if(p!=NULL)
	{
		p->info = x;
		p->pNext = NULL;
	} 
	return p;
}
Node* InsertHead(List &l,Xe x)
{
	Node* p = CreateNode(x);
	if(p!=NULL)
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
	return p;
}
void Nhap1Xe(Xe &x)
{
	cout <<"Nhap vao bien so xe: ";
	cin>>x.BienSo;
	fflush(stdin);
	cout <<"Chuyen xe di tu : ";
	gets_s(x.Tu);
	fflush(stdin);
	cout <<"Chuyen xe di den: ";
	gets_s(x.Den);
	cout <<"Nhap vao gia chuyen: ";
	cin>>x.GiaThanh;

}
void Xuat1Xe(Xe x)
{
	cout<<"Bien so xe la "<<x.BienSo<<endl;
	cout<<"Tuyen xe di tu "<<x.Tu<<" den "<<x.Den<<endl;
	cout<<"Gia tuyen la "<<x.GiaThanh<<endl;
	cout<<"------------------------------------------------------"<<endl;
}
void PrintAll(List l)
{
	for(Node* p =l.pHead;p!=NULL;p=p->pNext)
		Xuat1Xe(p->info);
}
void GhiFile(List l)
{
	FILE *f;
	fopen_s(&f,"xe.txt","ab");
	for(Node* p=l.pHead;p!=NULL;p=p->pNext)
		fwrite(&p->info,sizeof(Xe),1,f);
	fclose(f);
}
void LoadFile(List &l)
{
	Initialize(l);
	FILE *f;
	fopen_s(&f,"xe.txt","rb");
	if(f==NULL)
	{
		cout<<"Khong mo duoc file";
		return;
	}
	Xe x;
	while(!feof(f))
	{
		if(fread(&x,sizeof(Xe),1,f))
			InsertHead(l,x);
	}
	fclose(f);
}
Node* Search(List l,int tien)
{	
	for(Node* p=l.pHead;p!=NULL;p=p->pNext)
		if(p->info.GiaThanh == tien)
			return p;
	return NULL;
}
bool DeleteHead(List &l)
{
	if(IsEmpty(l))
		return false;
	Node* p = l.pHead;
	l.pHead = l.pHead ->pNext;
	delete p;
	return true;
}
void main()
{
	List l; 
	Initialize(l);
	int n; Xe x;
	//cout<<"Nhap vao so luong xe: ";
	//cin>>n;
	//for(int i =0; i<n;i++)
	//{
	//	Nhap1Xe(x);
	//	InsertHead(l,x);
	//}
	//system("cls");
	//PrintAll(l);
	//GhiFile(l);

	LoadFile(l);
	PrintAll(l);
	DeleteHead(l);
	//int tien;
	////char bs[10];
	////cout<<"Nhap vao bien so xe can tim: ";
	////gets_s(x.BienSo);
	////fflush(stdin);
	//cout<<"Nhap vao gia tien cua xe can tim: ";
	//cin>>tien;

	//Node* kq=Search(l,tien);
	//if(kq==NULL)
	//	cout<<"Khong tim thay "<<endl;
	//else
	//	Xuat1Xe(kq->info);
	///*LoadFile(l);
	//PrintAll(l);*/
	_getch();
}