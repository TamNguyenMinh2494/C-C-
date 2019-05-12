// Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
typedef struct SinhVien
{
	int MSSV;
	char HoTen[30];
	float dtb;
};
typedef struct Node
{
	SinhVien info;
	Node* pNext;
};
typedef struct Queue
{
	Node* pHead;
	Node* pTail;
};
void Initialize(Queue &q)
{
	q.pHead = NULL;
	q.pTail = NULL;
}
bool IsEmpty(Queue q)
{
	return q.pHead == NULL;
}
Node* CreateNode(SinhVien x)
{
	Node* p = new Node;
	if (p != NULL)
	{
		p->info = x;
		p->pNext = NULL;
	} return p;
}
void NhapSV(SinhVien &x)
{
	cout << "Nhap vao ma so sinh vien: ";
	cin >> x.MSSV;
	rewind(stdin);
	cout << "Nhap vao ho ten sinh vien: ";
	gets_s(x.HoTen);
	cout << "Nhap vao diem trung binh cua sinh vien: ";
	cin >> x.dtb;
}
void XuatSV(SinhVien x)
{
	cout << "MSSV: " << x.MSSV << "\t" << "Ho Ten: " << x.HoTen << "\t" << "Diem trung binh: " << x.dtb << endl;
}
void PrintAll(Queue q)
{
	for(Node* p = q.pHead; p!=NULL; p= p->pNext)
	{
		XuatSV(p->info);
	}
}
bool Push(Queue &q, SinhVien x)
{
	Node* p = CreateNode(x);
	if (IsEmpty(q)) {
		q.pHead = p;
		q.pTail = p;
	}
	else {
		q.pTail->pNext = p;
		q.pTail = p;
	}return true;
}
bool Delete(Queue &q)
{
	if (IsEmpty(q)) return false;
	Node* p = q.pHead;
	q.pHead = q.pHead->pNext;
	delete(p);
	return true;
}
//SinhVien* Pop(Queue &q)
//{
//	SinhVien *x = new SinhVien;
//	if (IsEmpty(q)) return NULL;
//	*x = q.pHead->info;
//	delete(q);
//	return x;
//}
SinhVien *getTop(Queue q)
{
	SinhVien *x = new SinhVien;
	if (IsEmpty(q)) return NULL;
	*x = q.pHead->info;
	return x;
}
SinhVien *getTail(Queue q)
{
	SinhVien *x = new SinhVien;
	if (IsEmpty(q)) return NULL;
	*x = q.pTail->info;
	return x;
}
void main()
{
	Queue q;
	Initialize(q);
	SinhVien x;
	int ans;
	int n;
	cout << "1.Nhap sinh vien"<<endl;
	cout << "2. Get Top"<<endl;
	cout << "3. Get Tail"<<endl;
	cout << "0.Exit"<<endl;
	cout << "Nhap vao so ban muon thao tac: ";
	cin >> ans;
	do {
		switch (ans)
		{
		case 1: {
			cout << "Nhap so sinh vien can them ";
			cin >> n;
			for(int i=0;i<n;i++)
				NhapSV(x);
			cout << "----------------------------"<<endl;
			Push(q, x);
		}
		case 2: {
			if (getTop(q) != NULL)
			{
				x = *(getTop(q));
				XuatSV(x);
			}
		}
		case 3: {
			if (getTail(q) != NULL)
			{
				x = *(getTail(q));
				XuatSV(x);
			}
		}
		default:
			break;
		}
	} while (1);
	
	
	_getch();
}

