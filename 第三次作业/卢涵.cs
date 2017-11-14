using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace ConsoleApp1
{
    class Program
    {
        static bool flag;
        static short h,l,x1,y1,x=0,y=0;
        static int weishu,amount;
        static short [,] num;
        static short [,] po;
        static void rand()
        {
            Random ro = new Random();
            int [] random=new int [h*l+1];
            int len=h*l,i,h1,l1;
            for(i=1;i<=h*l/2;++i){
                random[i]=random[i+h*l/2]=i;
            }
            while(len>0){
                i=ro.Next(len);
                i++;
                do{
                    h1=ro.Next(h)+1;
                    l1=ro.Next(l)+1;
                }while(num[h1,l1]!=0);
                num[h1,l1]=Convert.ToInt16(random[i]);
                random[i]=random[len];
                --len;
            }
        }
        static void init()
        {
            do{
                Console.Write("请输入行：");
                h=Convert.ToInt16(Console.ReadLine());
                Console.Write("请输入列：");
                l=Convert.ToInt16(Console.ReadLine());
                if(h*l%2!=0)
                     Console.Write("输入错误。按任意键重新输入");
                else
                    break;
                Console.ReadKey();
                Console.Clear();
            }while(true);
            Console.Clear();
            po=new short [h+1,l+1];
            num=new short [h+1,l+1];
        }
        static void print()
        {
            int i,j,k;
            Console.Clear();
            for(i=1;i<=h;++i){
                for(j=1;j<=l;++j){
                    if(x1==i&&y1==j)Console.ForegroundColor = ConsoleColor.Red;
                    if(po[i,j]==0) Console.Write("*");
                    else Console.Write("{0}",po[i,j]);
                    if(x1==i&&y1==j)Console.ForegroundColor = ConsoleColor.White;
                    if(po[i,j]!=0)
                        for(k=1;k<=weishu-Convert.ToInt16(num[i,j]>=10);++k)
                            Console.Write(" ");
                    else
                        for(k=1;k<=weishu;++k)
                            Console.Write(" ");
                 }
                Console.Write("\n");
             }
            Console.Write("通过方向键控制，回车键确认选择");
        }
        static void Up()
        {
            short i;
            i=x1;
            --i;
            if(i==0)i=h;
            x1=i;
        }
        static void Down()
        {
            short i;
            i=x1;
            ++i;
            if(i==h+1)i=1;
            x1=i;
        }
        static void Left()
        {
            short i;
            i=y1;
            --i;
            if(i==0)i=l;
            y1=i;
        }
        static void Right()
        {
            short i;
            i=y1;
            ++i;
            if(i==l+1)i=1;
            y1=i;
        }
        static void Enter()
        {
            if(po[x1,y1]!=0){
                flag=true;
                return ;
            }
            if(x==0&&y==0){
                x=x1;
                y=y1;
                po[x,y]=num[x,y];
                return ;
            }
            if(x!=0&&y!=0){
                po[x1,y1]=num[x1,y1];
                print();
                if(po[x1,y1]!=po[x,y]){
                    po[x,y]=po[x1,y1]=0;
                    x=y=0;
                    Thread.Sleep(1000);
                    return ;
                }
                else{
                    x=y=0;
                    --amount;
                    return ;
                }
            }
        }
        static void play()
        {
            while(true){
                flag=true;
                while(flag){
                    ConsoleKeyInfo info = Console.ReadKey();
                    switch (info.Key){
                        case ConsoleKey.UpArrow:
                            flag=false;
                            Up();
                            break;
                        case ConsoleKey.DownArrow:
                            flag=false;
                            Down();
                            break;
                        case ConsoleKey.LeftArrow:
                            flag=false;
                            Left();
                            break;
                        case ConsoleKey.RightArrow:
                            flag=false;
                            Right();
                            break;
                        case ConsoleKey.Enter:
                            flag=false;
                            Enter();
                            break;
                    }
                }
                print();
                if(amount==0)
                    break;
            }
        }
        static int Main(string[] args)
        {   
            init();
            short i,j,k;int hl=h*l/2;
            weishu=1;x1=y1=1;
            while(hl/10!=0){
                ++weishu;
                hl=hl/10;
            }
            amount=h*l/2;
            print();
            rand();
            play();
            Console.Write("\n游戏结束，输入任意键退出");
            Console.ReadKey();
            return 0;
        }
    }
}