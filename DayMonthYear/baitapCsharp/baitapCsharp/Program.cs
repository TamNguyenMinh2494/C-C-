using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApplication2
{
    public class Xe
    {
        public string TenHang { set; get; }
        public string ID { set; get; }
        public string MauSac { set; get; }
        public string MauXe { set; get; }
        public string GiaTien { set; get; }
        public Xe()
        {
            TenHang = "Yamaha";
            ID = "0";
            MauSac = "red";
            MauXe = "Exciter";
            GiaTien = "0";
        }
        public Xe(string TenHang, string ID, string MauSac, string MauXe, string GiaTien)
        {
            this.TenHang = TenHang;
            this.ID = ID;
            this.MauSac = MauSac;
            this.MauXe = MauXe;
            this.GiaTien = GiaTien;
        }
        public virtual void Nhap()
        {
            int answer1;
            Console.WriteLine("1.Honda");
            Console.WriteLine("2.Yamaha");
            Console.WriteLine("3.Suzuki");
            Console.WriteLine("4.SYM");
            Console.WriteLine("5.Vespa");
            Console.WriteLine("6.Pjaggio");
            do
            {
                Console.Write("Nhap Ten Hang: ");
                answer1 = int.Parse(Console.ReadLine());
            } while (answer1 > 7 || answer1 < 0);
            switch (answer1)
            {
                case 1: { TenHang = "Honda"; break; }
                case 2: { TenHang = "Yamaha"; break; }
                case 3: { TenHang = "Suzuki"; break; }
                case 4: { TenHang = "SYM"; break; }
                case 5: { TenHang = "Vespa"; break; }
                case 6: { TenHang = "Pjaggio"; break; }
            }
            Console.Clear();

            Console.Write("Nhap Ma So Khung Xe: ");
            ID = Console.ReadLine().ToUpper();
            Console.Clear();

            int answer2;
            Console.WriteLine("1.Red");
            Console.WriteLine("2.Red Blue");
            Console.WriteLine("3.Blue");
            Console.WriteLine("4.Bule White");
            Console.WriteLine("5.Yellow");
            Console.WriteLine("6.Gray");
            Console.WriteLine("7.Type your car's colour if it doesn't exist in table above");
            do
            {
                Console.Write("What's your number: ");
                answer2 = int.Parse(Console.ReadLine());
            } while (answer2 > 7 || answer2 < 0);
            switch (answer2)
            {
                case 1: { MauSac = "Red"; break; }
                case 2: { MauSac = "Red Blue"; break; }
                case 3: { MauSac = "Blue"; break; }
                case 4: { MauSac = "Blue White"; break; }
                case 5: { MauSac = "Yellow"; break; }
                case 6: { MauSac = "Gray"; break; }
                case 7:
                    {
                        {
                            Console.Write("What is your car's colour: ");
                            MauSac = Console.ReadLine();
                        } break;
                    }
            }
            Console.Clear();

            int answer3;
            Console.WriteLine("1.Air Blade");
            Console.WriteLine("2.Future");
            Console.WriteLine("3.Winner");
            Console.WriteLine("4.SH");
            Console.WriteLine("5.Exciter");
            Console.WriteLine("6.Sirius");
            Console.WriteLine("7.Nhap mau xe cua ban neu khong co trong bang ");
            do
            {
                Console.Write("What is your number: ");
                answer3 = int.Parse(Console.ReadLine());
            } while (answer3 > 7 || answer3 < 0);
            switch (answer3)
            {
                case 1: { MauXe = "Air Blade"; break; }
                case 2: { MauXe = "Future"; break; }
                case 3: { MauXe = "Winner"; break; }
                case 4: { MauXe = "SH"; break; }
                case 5: { MauXe = "SH"; break; }
                case 6: { MauXe = "Sirius"; break; }
                case 7:
                    {
                        {
                            Console.Write("Ten mau xe la: ");
                            MauXe = Console.ReadLine();
                        } break;
                    }
            }

            Console.Clear();
            Console.Write("Nhap Gia Tien Cua Xe: ");
            GiaTien = Console.ReadLine();
        }
        public override string ToString()
        {

            return TenHang + "\t" + ID + "\t" + MauSac + "\t" + MauXe + "\t" + GiaTien + "VND";
        }
    }
    public class XeGanMay : Xe
    {
        int wheel;
        public override void Nhap()
        {
            base.Nhap();
            Console.Write("Xe ban co may banh? ");
            wheel = int.Parse(Console.ReadLine());
        }
        public XeGanMay()
        {
            wheel = 0;
        }
        public XeGanMay(int wheel, string TenHang, string ID, string MauSac, string MauXe, string GiaTien)
            : base(TenHang, ID, MauSac, MauXe, GiaTien)
        {
            this.wheel = wheel;
        }
        public override string ToString()
        {
            return base.ToString() + "\t" + wheel + " wheels";
        }
    }

    public class XeTayGa : Xe
    {
        int kinh;
        public override void Nhap()
        {
            base.Nhap();
            Console.Write("Xe co may guong chieu hau? ");
            kinh = int.Parse(Console.ReadLine());
        }
        public XeTayGa()
        {
            kinh = 0;
        }
        public XeTayGa(int kinh, string TenHang, string ID, string MauSac, string MauXe, string GiaTien)
            : base(TenHang, ID, MauSac, MauXe, GiaTien)
        {
            this.kinh = kinh;
        }
        public override string ToString()
        {
            return base.ToString() + "\t" + kinh + " kinh";
        }
    }
    public class XeMoTo : Xe
    {
        int pk;
        public override void Nhap()
        {
            base.Nhap();
            Console.Write("Nhap phan khoi xe (cc)? ");
            pk = int.Parse(Console.ReadLine());
        }
        public XeMoTo()
        {
            pk = 0;
        }
        public XeMoTo(int pk, string TenHang, string ID, string MauSac, string MauXe, string GiaTien)
            : base(TenHang, ID, MauSac, MauXe, GiaTien)
        {
            this.pk = pk;
        }
        public override string ToString()
        {
            return base.ToString() + "\t" + pk + "cc";
        }
    }

    public class QLXE
    {
        public int n, i, nx;
        private string k, y;

        List<Xe> list = new List<Xe>();

        public void Add()
        {
            do
            {
                Xe x = new Xe();
                int ans;
                Console.WriteLine("1.Xe Gan May");
                Console.WriteLine("2.Xe Tay Ga");
                Console.WriteLine("3.Xe Mo to");
                do
                {
                    Console.Write("Ban Muon Chon Loai Xe Nao? ");
                    ans = int.Parse(Console.ReadLine());
                } while (n > 4 || n < 0);
                switch (ans)
                {
                    case 1: { x = new XeGanMay(); break; }
                    case 2: { x = new XeTayGa(); break; }
                    case 3: { x = new XeMoTo(); break; }
                }
                Console.Clear();
                x.Nhap();
                list.Add(x);
                Console.Clear();
                Console.Write("Muon nhap tiep hay khong [Yes/No] ");
                k = Console.ReadLine().ToUpper();
            } while (k == "YES");
            Write();
            Console.Clear();
        }

        public void Remove()
        {
            do
            {
                string ans;
                Console.Write("Nhap ID Muon Xoa: ");
                ans = Console.ReadLine();
                for (int i = 0; i < list.Count; i++)
                {
                    if (list[i].ID == ans)
                        list.Remove(list[i]);
                }
                Console.Clear();
                XuatDS();
                Console.Write("Muon xoa tiep hay khong [Yes/No] ");
                k = Console.ReadLine().ToUpper();
            } while (k == "YES");
            Console.Clear();
        }
        public void Index()
        {
            do
            {
                string ans;
                Console.Write("Nhap ID Muon Tim: ");
                ans = Console.ReadLine();
                foreach (Xe x in list)
                {
                    if (ans == x.ID)
                        Console.Write(x);
                }
                /*for (int i = 0; i < list.Count; i++)
                {
                    {
                        if (list[i].ID == ans)
                            Console.Write(list[i]);
                    }
                }*/
                Console.Write("\nMuon tim tiep hay khong [Yes/No] ");
                k = Console.ReadLine().ToUpper();
            } while (k == "YES");
        }
        public void Dem()
        {
            int dem=0;
            Xe x = new Xe();
            while (x != null)
            {
                for (int i = 0; i < list.Count; i++)
                {
                    dem++;
                    Console.Write("so luong xe: {0} ", dem);
                }
            }
        }
        public void Write()
        {
            FileStream fs = new FileStream("D:\\Xe.txt", FileMode.Append, FileAccess.Write);//Append dung de ghi tiep trong file
            StreamWriter sw = new StreamWriter(fs);
            foreach (Xe x in list)
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
            FileStream fs = new FileStream("D:\\Xe.txt", FileMode.Open, FileAccess.Read);
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
        public void LoadFile()
        {
            FileStream fs = new FileStream("D:\\Xe.txt", FileMode.Open);
            StreamReader sr = new StreamReader(fs);
            string text = sr.ReadToEnd(); //doc het data trong file
            Console.Write(text);
            sr.Close();
            Console.ReadLine();
        }
        public void XuatDS()
        {
            Console.Clear();
            //Write();
            list.Sort(delegate(Xe x1, Xe x2) { return x1.TenHang.CompareTo(x2.TenHang); });//sap xep theo ten NSX 
            Console.WriteLine("\tBang Thong Tin Cu The");

            foreach (Xe x in list)
                //Console.WriteLine("Ten Hang la: {0}" + "\nMa so khung la: {1}" + ", mau sac la: {2}" + ", mau xe la: {3}" + ", gia tien la: {4}", x.TenHang,x.ID,x.MauSac,x.MauXe,x.GiaTien);
                Console.WriteLine(x);
            //Console.Clear();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            QLXE ql = new QLXE();
           
                        //ql.Read();
                        //ql.Dem();
                        string kq;
                        do
                        {
                            Console.Write("1.Them thong tin");
                            Console.Write("\n2.Tim thong tin");
                            Console.Write("\n3.Xoa thong tin");
                            Console.Write("\n-->Which one do you want to choose ");
                            int key = int.Parse(Console.ReadLine());
                            Console.Clear();
                            switch (key)
                            {
                                case 1:
                                    {
                                        ql.Read();
                                        ql.Add();
                                        ql.XuatDS();
                                        ql.Write();
                                        break;
                                    }
                                case 2:
                                    {
                                        ql.Read();
                                        ql.Index();
                                        ql.XuatDS(); break;
                                    }
                                case 3:
                                    {
                                        ql.Read();
                                        ql.Remove();
                                        ql.Write(); break;
                                    }
                            }
                            ql.Read();
                            Console.Write("Muon tiep hay khong [Yes/No] ");
                            kq = Console.ReadLine().ToUpper();
                        } while (kq == "YES");
        }
    }
}
   

