using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace testproject
{
    class QLNV
    {
        int SS;
        int[] arr;
        public void Nhap()
        {
            Console.Write("Nhap si so nhan vien: ");
            SS = int.Parse(Console.ReadLine());
            arr = new int[SS];

        }
        public void Xuat()
        {
            for (int i = 0; i < SS; i++)
            {
                Console.Write("a[{0}] = {1}\n", i, arr[i]);
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            QLNV nv = new QLNV();
            nv.Nhap();
            nv.Xuat();
        }
    }
}
