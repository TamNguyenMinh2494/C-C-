#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
//7)Tính S(n) = 1/2 + 2/3 + 3/4 + ... + n/(n+1)
float TinhTong(float n)
{
	if(n==1)
		return 0.5;
	else
		return TinhTong(n-1) + n/(n+1);

}
//8)Tính S(n) = 1/2 + 3/4 + 5/6 + ... + (2n+1)/(2n+2)
float TinhSTong(float n)
{
	if(n==1)
		return 0.5;
	else
		return TinhSTong(n-1) + ((2*n+1)/(2*n+2));

}

//11)Tính S(n) = 1 + 1.2 + 1.2.3 + .... + 1.2.3....n
long GiaiThua(int n)
{
	if(n==1)
		return 1;
	return GiaiThua(n-1)*n;
}
long Tong(int n)
{
	if(n == 1)
		return 1;
	return Tong(n-1) + GiaiThua(n-1)*n;
}
//18)Tìm ước số lẻ lớn nhất của số nguyên dương n . Ví dụ : n = 100 ước lẻ lớn nhất của 100 là 25
int UocLe(int n)
{
	if(n%2 ==1)
		return n;
	return UocLe(n/2);
}
//21)Tính S(n) = sqrt(1 + sqrt(2 + sqrt (3 + ...sqrt (n-1 + sqrt (n)))))
float TinhCan(float n)
{
	if(n==1)
		return 1;
	return sqrt(1+ TinhCan(n-1));
}
void main()
{
	float n;
	cout << "Nhap vao n: ";
	cin >> n;	
	cout << "Gia tri cau 7 la: "<< TinhTong(n);
	cout << "\n";
	cout << "Gia tri cau 8 la: "<< TinhSTong(n);
	cout << "\n";
	cout << "Gia tri cau 11 la: "<< Tong(n);
	cout << "\n";
	cout << "Gia tri cau 21 la: "<< TinhCan(n);
	cout << "\n";
	cout << "Gia tri cau 18 la: "<< UocLe(n);
	
	cout<<endl;
	_getch();
}