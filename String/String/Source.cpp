#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>
using namespace std;
//void C1(char *s) day la bai tap tren lop cua GV
//{
//	int len = strlen(s);
//	int i;
//	for(i = len-1; i>=0;i--)
//		if(s[i] == ' ') break;
//	for(int j = i+1; j<len; j++)
//		cout << (char)tolower(s[j]); 
//	cout<<'.';
//	for(int j=0; j<i;j++)
//		if(s[j]!= ' ')
//			cout<<(char)tolower(s[j]);
//	cout<<"@hoasen.edu.vn"<<endl;
//}
//char* C2(char *s)
//{
//	char* email = new char[50];
//	int k=0,i;
//	int len = strlen(s);
//	for(i = len -1; i>=0;i--)
//		if(s[i]==' ') break;
//	for(int j=i+1; j<len;j++)
//		email[k++] = (char)tolower(s[j]);
//	email[k++]= '.';
//	for(int j=0;j<i;j++)
//		if(s[j]!=' ')
//			email[k++] = (char)tolower(s[j]);
//	email[k]='\0';
//	strcat(email,"@hoasen.edu.vn\n");
//	return email;
//}
// Phan duoi la BTVN cua SV
void C3(char *s)//Cau A: In ra màn hình từ bên phải nhất và phần còn lại của chuỗi
{
	int len = strlen(s);
	int i;
	for(i = len-1; i>=0;i--)
		if(s[i] == ' ') 
		{
			cout<<"\n";
			break;
		}
	for(int j = i+1; j<len; j++)
		cout << (char)tolower(s[j]); 
	cout<<'\n';
	for(int j=0; j<i;j++)
		if(s[j]== ' ')
		{
			cout<<"\n";
		}
		else cout<<(char)tolower(s[j]);
}
void C4(char *s)//Cau B:In ra màn hình từ bên trái nhất và phần còn lại của chuỗi.
{
	int len =strlen(s);
	int i;
	for(i=0; i<len;i++)
		if(s[i]==' ')
		{
			cout<<"\n";
			break;
		}
	for(int j=0; j<i;j++)
		cout<<(char)(s[j]);
	cout<<"\n";
	for(int j= i+1;j<len;j++)
		if(s[j]!=' ')
			cout<<(char)(s[j]);
}
void C5(char *s)//Cau C: Xuất chuỗi đó ra màn hình dưới dạng mỗi từ một dòng
{
	int len =strlen(s);
	int i;
	for(i=0;i<len;i++)
		if(s[i]==' ')
		{
			cout<<"\n";
			break;
		}
	for(int j=0;j<i;j++)
		cout<<(char)(s[j]);
	cout<<"\n";
	for(int j=i+1;j<len;j++)
		if(s[j]==' ')
			cout<<"\n";
		else
			cout<<(char)(s[j]);
}
void C6(char *s)//Cau 2: chuoi dao nguoc
{
	int len= strlen(s);
	for(int j=len-1;j>=0;j--)//duyet tu dich len dau
		cout<<(char)(s[j]);
}
void C7(char *s)//Cau F: viet hoa chu cai dau cua moi ten
{
	int len=strlen(s);
	for(int i=0;i<len;i++)
		if(i==0||s[i-1]==' ')//ktra truoc no co phai la khoang trang hay khong
			s[i]=toupper(s[i]);
	cout<<s;		
}

void main()
{
	char ht[20];
	cout<<"Nhap ho ten Giao Vien: ";
	gets(ht);
	/*C1(ht);
	char *email = C2(ht);
	cout<< email;*/
	C3(ht);
	cout<<"\n";
	C4(ht);
	cout<<"\n";
	C5(ht);
	cout<<"\n";
	C6(ht);
	cout<<"\n";
	C7(ht);
	_getch();
}