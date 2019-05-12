#include"thuvienstruct.h"

void main()
{
	SinhVien a[MAX];
	int n=0;
	/*ThemmSV(a,n);
	Them1SV(a,n);
	XuatMang(a,n);*/
	cout << "Sau day la Load File";
	LoadFile(a,n);
	cout<< "\n";
	/*cout << "\nSau day la ham Selection Sort\n";
	SelectionSort(a,n);*/
	cout << "\nSau day la ham Bubble Sort\n";
	BubbleSort(a,n);
	
	_getch();
}