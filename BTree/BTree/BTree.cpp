// BTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <iomanip>
using namespace std;
typedef struct SV
{
	int mssv;
	char ten[50];
	float dtb;
	double hocphi;
};
typedef struct BNode
{
	SV info;
	BNode*left;
	BNode*right;
};
typedef struct BTree
{
	BNode* Root;
};

void Initialize(BTree &t)
{
	t.Root = NULL;
}

bool IsEmpty(BTree t)
{
	return t.Root = NULL;
}
BNode* CreateNode(SV x)
{
	BNode*p = new BNode;
	if (p != NULL)
	{
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	return p;

}

void CreatebTree(BNode* &p)
{
	SV x;
	cout << "Moi nhap gia tri node: ";
	cin >> x.mssv; fflush(stdin);
	if (x.mssv == -1) return;

	cout << "Nhap Hoten: ";
	gets_s(x.ten); fflush(stdin);
	cout << "Nhap Dtb: ";
	cin >> x.dtb; fflush(stdin);
	cout << "Nhap hocphi: ";
	cin >> x.hocphi;
	p = CreateNode(x);
	if (p != NULL)
	{
		cout << "Left: " << x.mssv;
		CreatebTree(p->left);
		cout << "Right: " << x.mssv;
		CreatebTree(p->right);
	}
}
void PrintTree(BNode* p, int d)
{
	if (p == NULL) return;
	PrintTree(p->right, d + 1);
	cout << endl << setw(4 * d) << p->info.mssv;
	PrintTree(p->left, d + 1);
}
void Xuat1sv(SV x)
{
	cout << "**********************" << endl;
	cout << x.mssv << "\t" << x.ten << "\t" << x.dtb << "\t" << x.hocphi << endl;
}
void TimSVLNR(BNode*p)
{
	int ms;
	cout << "Nhap Mssv can tim:";
	cin >> ms;
	if (p == NULL)return;
	if (p->info.mssv == ms);
	Xuat1sv(p->info);

}
void Timmin(BNode*p, int &min)
{
	if (p == NULL)return;
	if (p->info.mssv<min)
		min = p->info.mssv;
	Xuat1sv(p->info);
	Timmin(p->left, min);
	Timmin(p->right, min);
}
void Timmax(BNode*p, int &max)
{
	if (p == NULL)return;
	if (p->info.mssv>max)
		max = p->info.mssv;

	Timmin(p->left, max);
	Timmin(p->right, max);
	Xuat1sv(p->info);
}
void TimSVDau(BNode*p)//loi
{

	if (p == NULL)return;
	if (p->info.dtb >= 5);
	{
		Xuat1sv(p->info);
		cout << "sinh vien nay da dau!" << endl;
	}
	TimSVDau(p->left);
	TimSVDau(p->right);

}
void main()
{
	BTree t;


	Initialize(t);
	CreatebTree(t.Root);
	PrintTree(t.Root, 0);

	cout << "ket qua Tim kiem" << endl;
	TimSVLNR(t.Root);
	cout << "ket qua Tim kiem" << endl;
	int min = t.Root->info.mssv;
	Timmin(t.Root, min);
	cout << "ket qua Tim kiem" << endl;
	int max = t.Root->info.mssv;
	Timmax(t.Root, max);
}
