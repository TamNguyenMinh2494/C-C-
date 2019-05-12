using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace OOAD
{
    public class SinhVien
    {
        
    }
    public class Menu
    {
        public string TenChucNang;
    }
    public class DanhSachSV
    {
        List<DanhSachSV> list = new List<DanhSachSV>();
        public int MSSV { set; get; }
        public string Ten { set; get; }
        public string TenKhoa { set; get; }
        public DanhSachSV(int MSSV, string Ten, string TenKhoa)
        {
            this.MSSV = MSSV;
            this.Ten = Ten;
            this.TenKhoa = TenKhoa;
        }
        public void Nhap()
        {
            Console.WriteLine("Moi nhap vao ma so sinh vien: ");
            MSSV = int.Parse(Console.ReadLine());
            Console.WriteLine("Moi nhap vao ten sinh vien: ");
            Ten = Console.ReadLine();
            Console.WriteLine("Moi nhap vao ten khoa: ");
            TenKhoa = Console.ReadLine();
        }
        public override string ToString()
        {
            return MSSV + "\t" + Ten + "\t" + TenKhoa;
        }
        public void TimTheoMSSV()
        {
            string ans;
            Console.Write("Nhap MSSV Muon Tim ---: ");
            ans = Console.ReadLine().ToUpper();


            List<string> lines = System.IO.File.ReadLines("D:\\SinhVien.txt").ToList();


            foreach (string line in lines) // Display for verification.
            {
                string l = line.ToString().Trim().ToUpper();
                if (l.IndexOf(ans) != -1)
                {
                    Console.WriteLine(line);
                    break;
                }
            }
        }
        public void TimTheoTen()
        {
        }
        public void TimTheoKhoa()
        {
        }

    }
    public class File
    {
        List<SinhVien> list = new List<SinhVien>();
        public File()
        {
        }
        public void Write()
        {
            FileStream fs = new FileStream("D:\\SinhVien.txt", FileMode.Append, FileAccess.Write);//Append dung de ghi tiep trong file
            StreamWriter sw = new StreamWriter(fs);
            foreach (SinhVien x in list)
            {
                Console.ReadLine();
                sw.WriteLine(x);
            }
            sw.Flush();
            sw.Close();
            fs.Close();
        }
        public void Read()
        {
            FileStream fs = new FileStream("D:\\SinhVien.txt", FileMode.Open, FileAccess.Read);
            StreamReader sr = new StreamReader(fs);
            string text = sr.ReadToEnd();
            while (text != null)
            {
                Console.Write(text);
                text = sr.ReadLine();
            }
            sr.Close();
            fs.Close();
            Console.ReadLine();
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
        }
    }
}
