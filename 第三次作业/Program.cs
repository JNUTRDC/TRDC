using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace 纸牌游戏
{
    class Program
    {
        public static int[] math = new int[16];
        public static int[] face = new int[16];
        public static int[] now = new int[16];
        public static int[] ou = new int[16];
        public static string fal;
        public static string life;

        static void Start()
        {
            for (int i = 0; i <= 3; i++)
            {
                for (int j = 0; j <= 3; j++)
                {
                    math[i * 2 + j] = i + 1;
                }
            }
            int L = 15, x;
            Random go = new Random();
            for (int i = 0; i <= 15; i++)
            {
                x = go.Next(0, L);
                face[i] = math[x];
                math[x] = math[L];
                L = 1;
            }

        }
        static void Cardback()
        {
            Console.Clear();
            for (int i = 0; i <= 15; i++)
            {
                if (now[i] == 0)
                    Console.WriteLine("*");
                else
                    Console.WriteLine("{face[i]}");
                if ((i + 1) % 16 == 0)
                    Console.WriteLine();

            }
        }
        static void Welcome()
        {
            string Player;
            Console.WriteLine("欢迎进入游戏，请问您的名字是？");
            Player = Console.ReadLine();
            Console.WriteLine($"欢迎你！挑战者{Player}！\n");
            Thread.Sleep(1000);
            Console.WriteLine("游戏规则");
            Console.WriteLine("4X4超简易翻纸牌益智小游戏");
            Console.WriteLine("按照游戏提示输入（可以尝试输入其他的数字哦，有彩蛋）\n当全部牌翻开或生命值耗尽时结束游戏。\n");
            Thread.Sleep(1000);
        }

        public static void Game()
        {
            int h1, h2, r1, r2, v;
            
            for (int i = 0; i <= 15; i++)
            {
                now[i] = 0;
                Cardback();
            }
            Console.WriteLine("即将开始游戏，您拥有五秒的观察时间，请集中╭( ･ㅂ･)و ");
            Thread.Sleep(5000);
            Console.WriteLine("Start!");
            for (; ; )
            {
                Console.WriteLine("请输入您要翻的第一个牌子的行~");
                h1 = Convert.ToInt16(Console.ReadLine());
                if (h1 >= 5)
                {
                    Console.WriteLine("您输入的行数已经溢出去了╰(￣▽￣)╭");
                    continue;
                }

                if (h1 == 0)
                {
                    Console.WriteLine("......0什么的、不存在的");
                    continue;
                }
                else break;
            }
            
            for (; ; )
            {
                Console.WriteLine("请输入您要翻的第一个牌子的列~");
                r1 = Convert.ToInt16(Console.ReadLine());
                if (r1 >= 5)
                    Console.WriteLine("我很好奇您是怎么到这么一列的，明明这么明显");
                if (r1 == 0)
                    Console.WriteLine("哈哈哈，别想了，没有这有这一列的.....");
                else break;

            }
            now[(h1 - 1) * 4 + r1 - 1] = 1;
            Cardback();
            for (; ; )
            {
                Console.WriteLine("请输入您要翻的第二个牌子的行~");
                h2 = Convert.ToInt16(Console.ReadLine());
                if (h2 >= 5)
                    Console.WriteLine("这个是........4X4翻纸牌游戏哦......重新输入");
                if (h2 == 0)
                    Console.WriteLine("能输入这种数字，我也是很佩服你的= =");
                else break;

            }
            for (; ; )
            {
                Console.WriteLine("请输入您要翻的第二个牌子的列~");
                r2 = Convert.ToInt16(Console.ReadLine());
                if (r2 >= 5)
                    Console.WriteLine($"喵、并没有{r2}这种东西的存在，请看着规则重新输入（微笑）");
                if (r2 == 0)
                    Console.WriteLine("我应该从哪里开始吐槽呢....");
            }
            now[(h2 - 1) * 4 + r2 - 1] = 1;
            Cardback();
            if (face[(h1 - 1) * 4 + r1 - 1] == face[(h2 - 1) * 4 + r2 - 1] &&
                ou[(h1 - 1) * 4 + r1 - 1] == 0 && ou[(h2 - 1) * 4 + r2 - 1] == 0)
            {
                Console.WriteLine("成功！记忆力超强的！");
                now[(h1 - 1) * 4 + r1 - 1] = now[(h2 - 1) * 4 + r2 - 1] = 1;
                ou[(h1 - 1) * 4 + r1 - 1] = ou[(h2 - 1) * 4 + r2 - 1] = 1;
                Thread.Sleep(2000);
            }
            else
            {
                Thread.Sleep(1000);
                Cardback();
                Console.WriteLine("失败(ﾉ*･ω･)ﾉ，加油！");
                now[(h1 - 1) * 4 + r1 - 1] = now[(h2 - 1) * 4 + r2 - 1] = 0;
                int life = Convert.ToInt32(life);
                life-=1;
                Thread.Sleep(1000);
            }
            for (int i = 0; ; i++)
            {
                if (now[i] == 1)
                {
                    v += 1;
                }
                if (v == 16)
                {
                    Console.WriteLine("恭喜你翻开了所有的牌！大吉大利，晚上吃鸡！");
                    break;
                }
                else
                    v = 0;
            }

        }
        public static void Choose()
        {
            Console.WriteLine("勇敢的挑战者，请输入你希望上天给予的生命值");
            life = Console.ReadLine();

            Console.WriteLine($"以生命值——{life}开始游戏\n按任意键继续");
        }
        public static void Result()
        {
            for (; ; )
            {
                int m = Convert.ToInt32(life);
                if (m == 0)
                {
                    Console.WriteLine("bia！你死了！");
                    return;
                }
                else break;
            }
        }
        static void Main(string[] args)
        {
            Welcome();
            Choose();
            Console.ReadKey();
            Start();
            Game();
            Result();
        }

    }
}