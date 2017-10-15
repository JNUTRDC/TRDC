using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace ConsoleApp3
{
    //随机给牌面
    public class  faceGiving
    {
        public char[,] card_face = new char[4, 4];
        public faceGiving(char []f)
        {
            long tick = DateTime.Now.Ticks;
            Random ran = new Random((int)(tick & 0xffffffffL) | (int)(tick >> 32));
            for (int i = 0; i <=3;i++)
            {
                for (int j = 0; j <=3; j++)
                {

                    int rr = ran.Next(0, 13);
                    card_face[i, j ]= f[rr];
                    
                }
            }
        }
    }
    //排序并输将牌翻上
    public class sort
    {
        public char[,] hidingFace = new char[4, 4];
        public sort(char[,]s)
        {
            for(int i=0;i<=3;i++)
            {
                for(int j=0;j<=3;j++)
                {
                    Console.Write(format: "{0,7:d}", arg0: s[i, j]);
                }
                Console.WriteLine();
                Console.WriteLine();
            }
            Thread.Sleep(2000);
            Console.Clear();
            for(int i = 0; i <=3; i++)
            {
                for (int j = 0; j <= 3; j++)
                {
                    hidingFace[i, j] = '*';
                }
            }
            for (int i = 0; i <= 3; i++)
            {
                for (int j = 0; j <= 3; j++)
                {
                    Console.Write(format: "{0,7:d}", arg0: hidingFace[i, j]);
                }
                Console.WriteLine();
                Console.WriteLine();
            }
        }
    }
    //读取坐标
    public class input
    {
        public int x_p, y_p;
        public input()
        {
            Console.WriteLine("Please enter the coordinate of one of the cards: ");
            string input = Console.ReadLine();
            string[] inputnum = input.Split(' ');
            x_p = int.Parse(inputnum[0]) - 1;
            y_p = int.Parse(inputnum[1]) - 1;
        }
    }
    //判断每两次翻盘牌面是否相同
    public class judge
    {
        public bool flag = false;
        public static int[] n;
        public judge(int[]a)
        {
            n = a;
            for (int i=0; i<n.Length-1; i++)
            {
                for(int j=i+1; j<n.Length;j++)
                {
                    if(n[i]==n[j])
                    {
                        flag =true;
                        break;
                    }
                }
            }
        }
    }
    //显示被翻出的牌的牌面
    public class _isActive
    {
        public char[,] hide;
        public _isActive(int  a,int b,char[,] h,char[,]f)
        {
            h[a, b] = f[a, b];
            hide = h;
            Console.Clear();
            for (int i = 0; i <= 3; i++)
            {
                for (int j = 0; j <= 3; j++)
                {
                    Console.Write("{0,7:d}", hide[i, j]);
                }
                Console.WriteLine();
                Console.WriteLine();
            }
        }
    }
    //主函数，里面有个叫接口的东西？
    class Program
    {
        static void Main(string[] args)
        {
            //游戏规则
            Console.WriteLine("Welcome! Let's  play a game to test your memory.");
            Thread.Sleep(1000);
            for (int i=1;i<115;i++)
            {
                Console.Write("\\");
            }
            Console.WriteLine();
            Console.WriteLine();
            Thread.Sleep(1000);
            Console.WriteLine("Rules:1、You have two seconds to memorize the card face;");
            Thread.Sleep(1000);
            Console.WriteLine("      2、Enter one coordinate each time and do it twice; ");
            Thread.Sleep(1000);
            Console.WriteLine("      3、If the two cards you have turned have the same face,you win;Or they will be turned back again ");
            Console.WriteLine();
            Thread.Sleep(1000);
            for (int i = 1; i < 115; i++)
            {
                Console.Write("\\");
            }
            Console.WriteLine();
            Console.WriteLine();
            Thread.Sleep(1000);
            Console.WriteLine("Ok!Game will start whthin 10 seconds.");
            Console.WriteLine();
            Console.WriteLine();
            //游戏倒计时10s开始
            int Y_N = 'y';
            for(int i=1; i<11;i++)
            {
                Thread.Sleep(1000);
                Console.Write("*");
            }
            Console.Clear();
            char[] face = new char[13] { '1', '2', '3', '4', '5', '6', '7', '8', '9','十', 'J', 'Q','K' };
            do
            {
                //调用faceGiving类分配牌面
                faceGiving fGiving = new faceGiving(face);
                char[,] faceGiven = fGiving.card_face;
                //调用sort类进行排序
                sort sorTing = new sort(faceGiven);
                char[,] faceHiden = sorTing.hidingFace;
                int[] card_turned = new int[2];                    
                failed: for (int i = 0; i < 2; i++)
                {
                    //调用input类进行输入
                    input input_2 = new input();
                    int x_p_1 = input_2.x_p, y_p_1 = input_2.y_p;
                    //调用_isActive类进行翻牌
                    _isActive activeCard_1 = new _isActive(y_p_1,x_p_1, faceHiden, faceGiven);
                    faceHiden = activeCard_1.hide;
                    card_turned[i] = (int)(activeCard_1.hide[x_p_1, y_p_1]);


                }
                //调用judge进行判断
                judge jd = new judge(card_turned);
                if (jd.flag)
                {
                    Console.WriteLine("You win!!");
                    Console.WriteLine("Do you want to play again?Input Yes\"Y\" or No\"N\":");
                    Y_N = (char) Console.Read();
                }
                else
                {
                    Thread.Sleep(500);
                    Console.Clear();
                    for (int i = 0; i <= 3; i++)
                    {
                        for (int j = 0; j <= 3; j++)
                        {
                            sorTing.hidingFace[i, j] = '*';
                        }
                    }
                    for (int i = 0; i <= 3; i++)
                    {
                        for (int j = 0; j <= 3; j++)
                        {
                            Console.Write(format: "{0,7:d}", arg0: sorTing.hidingFace[i, j]);
                        }
                        Console.WriteLine();
                        Console.WriteLine();
                    }
                    goto failed;
                }
            } while (Y_N == 'y');

            Console.Read();

    }
    }
}
