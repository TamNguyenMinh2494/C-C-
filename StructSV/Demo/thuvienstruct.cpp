#include "thuvienstruct.h"

void Nhap1SV(SinhVien &s)
{
	cout << "Nhap ma so sinh vien: ";
	cin >> s.MSSV;
	rewind(stdin);
	cout << "\nNhap ten sinh vien: ";
	gets_s(s.Ten);
	cout << "\nNhap nam sinh cua sinh vien: ";
	cin >> s.NamSinh;
	rewind(stdin);
	cout << "\nNhap gioi tinh: ";
	gets_s(s.GioiTinh);
	rewind(stdin);

}
void Them1SV(SinhVien a[], int &n)// Add a SinhVien to Array
{
	if (n < MAX)
	{
		Nhap1SV(a[n]);
		FILE *f;
		fopen_s(&f, "SinhVien.txt", "ab");
		fwrite(&a[n], sizeof(SinhVien), 1, f);
		fclose(f);
		n++;
	}
	else
	{
		cout << "Mang da day"; return;
	}
}
void ThemmSV(SinhVien a[], int &n)// Add m SinhVien to Array
{
	int m;
	cout << "Nhap so luong sinh vien muon them: ";
	cin >> m;
	if (n + m < MAX)
	{
		for (int i = 0; i<n + m; i++)
			Nhap1SV(a[i]);
		FILE *f;
		fopen_s(&f, "SinhVien.txt", "ab");
		fwrite(&a[n], sizeof(SinhVien), m, f);
		fclose(f);
		n += m;
	}
	else
	{
		cout << "Mang da day";
		return;
	}
}
void Xuat1SV(SinhVien s)
{
	cout << s.MSSV << "\t" << s.Ten << "\t" << s.NamSinh << "\t" << s.GioiTinh << endl;
}
void XuatMang(SinhVien a[], int n)// Add a SinhVien to Array
{
	for (int i = 0; i < n; i++)
		Xuat1SV(a[i]);
}
void LoadFile(SinhVien a[], int &n)
{
	FILE *f;
	fopen_s(&f, "SinhVien.txt", "rb");
	if (f == NULL)
	{
		cout << "Khong mo duoc file";
		return;
	}
	while (!feof(f))
	{
		if (fread(&a[n], sizeof(SinhVien), 1, f))
			n++;
	}
	fclose(f);
	XuatMang(a, n);
}
void Swap(SinhVien &a, SinhVien &b)
{
	SinhVien t = a;
	a = b;
	b = t;
}
void BubbleSort(SinhVien a[], int &n)
{
	for (int i = 0; i<n - 1; i++)
	{
		for (int j = n - 1; j >= i; j--)
		{
			if (a[j].MSSV<a[j - 1].MSSV)
			{
				Swap(a[j - 1], a[j]);
				XuatMang(a, n);
			}
		}
	}
}