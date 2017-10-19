using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace game2
{
    class Program
    {
        public static int[] rdom = new int[16];
        public static int[] face = new int[16];
        public static int[] condition = new int[16];
        public static int[] right = new int[16];
        static void Start1()
        {
            //顺序赋值
            for (int i = 0; i <= 7; i++)
            {
                for(int j = 0;j <= 1; j++)
                {
                    rdom[2 * i + j] = i + 1;
                }
            }
            //赋值结束
        }//编码
        static void Start2()
        {
            int length = 15,t;
            Random rd = new Random();
            for (int i = 0; i <= 15; i++)
            {
                t = rd.Next(0, length);
                face[i] = rdom[t];
                rdom[t] = rdom[length];
                length -= 1;   
            }
        }//赋值
        static void Print()
        {
            Console.Clear();
            for (int i = 0; i < 16; i++)
            {
                if (condition[i] == 0)
                    Console.Write(" * ");
                else
                    Console.Write(" "+face[i]+" ");
                if ((i+1) % 4 == 0)
                    Console.WriteLine();
            }
        }//打印
        static void Game()
        {
            int Line1, Colomn1,Line2,Colomn2,bingo=0;
            for (int i = 0; i < 16; i++)
            { condition[i] = 1; }
            Print();
            for (int i = 0; i < 16; i++)
            { condition[i] = 0; }
            Console.WriteLine("你还有3秒钟观察时间");
            Thread.Sleep(1000);
            Console.WriteLine("你还有2秒钟观察时间");
            Thread.Sleep(1000);
            Console.WriteLine("你还有1秒钟观察时间");
            Thread.Sleep(1000);
            for (; ; )
            {
                Print();
                for (; ; )
                {
                    Console.Write("请输入第一个坐标的行:");
                    Line1 = Convert.ToInt16(Console.ReadLine());
                    if (0 >= Line1 && Line1 >=5) Console.WriteLine("输入错误！");
                    else break;
                }               
                for (; ; )
                {
                    Console.Write("请输入第一个坐标的列:");
                    Colomn1 = Convert.ToInt16(Console.ReadLine());
                    if (0 >= Colomn1 && Colomn1 >= 5) Console.WriteLine("输入错误！");
                    else break;
                }
                condition[(Line1 - 1) * 4 + Colomn1 - 1] = 1;
                Print();               
                for (; ; )
                {
                    Console.Write("请输入第二个坐标行");
                    Line2 = Convert.ToInt16(Console.ReadLine());
                    if (0 >= Line2 && Line2 >= 5) Console.WriteLine("输入错误！");
                    else break;
                }
                for (; ; )
                {
                    Console.Write("请输入第二个坐标列");
                    Colomn2 = Convert.ToInt16(Console.ReadLine());
                    if (0 >= Colomn2 && Colomn2 >= 5) Console.WriteLine("输入错误！");
                    else break;
                }
                condition[(Line2 - 1) * 4 + Colomn2 - 1] = 1;
                Print();
                if (face[(Line1-1)*4+Colomn1 -1]== face[(Line2 - 1) * 4 + Colomn2 - 1]
                    && right[(Line1 - 1) * 4 + Colomn1 - 1] == 0
                    && right[(Line2 - 1) * 4 + Colomn2 - 1] == 0
                   )
                {
                    Console.WriteLine("对了！");
                    condition[(Line1 - 1) * 4 + Colomn1 - 1] = condition[(Line2 - 1) * 4 + Colomn2 - 1] = 1;
                    right[(Line1 - 1) * 4 + Colomn1 - 1] = right[(Line2 - 1) * 4 + Colomn2 - 1] = 1; Thread.Sleep(1000);
                }
                else if (right[(Line1 - 1) * 4 + Colomn1 - 1] != 0 || right[(Line2 - 1) * 4 + Colomn2 - 1] != 0)
                {
                    Console.WriteLine("操作错误，请重输一遍！");
                    if (right[(Line1 - 1) * 4 + Colomn1 - 1] == 0) condition[(Line1 - 1) * 4 + Colomn1 - 1] = 0;
                    if (right[(Line2 - 1) * 4 + Colomn2 - 1]==0)condition[(Line2 - 1) * 4 + Colomn2 - 1]=0;
                    Thread.Sleep(1000);
                }
                else
                {
                    Print();
                    Console.WriteLine("错了！");
                    condition[(Line1 - 1) * 4 + Colomn1 - 1] = condition[(Line2 - 1) * 4 + Colomn2 - 1] = 0;
                    Thread.Sleep(1000);
                }
                for (int i = 0; i < 16; i++)
                {
                    if (condition[i] == 1) bingo += 1;
                }
                if (bingo == 16)
                {
                    Console.WriteLine("您胜利了！！！！！！");
                    break;
                }
                else bingo = 0;
            }

        }//主游戏
        static void Main(string[] args)
        {
            Console.WriteLine("******************");
            Console.WriteLine("本游戏为翻纸牌游戏");
            Console.WriteLine("   开局三秒观察 ");
            Console.WriteLine("然后翻出数字相同的牌");
            Console.WriteLine("翻出全部牌则为胜利");
            Console.WriteLine("******************");
            Console.WriteLine("ps：由于我技术不佳的原因，请不要连续敲击回车键，否则引起崩溃，谢谢合作！");
            Console.WriteLine("按任意键继续。。。");
            Console.ReadKey();
            Start1();
            Start2();
            Game();
        }
    }
}
