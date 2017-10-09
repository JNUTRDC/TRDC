#include <iostream>
#include<cstdlib>
#include<ctime>
#include<stdio.h>
#include<string>
#include<windows.h>
using namespace std;
int maxnum=0,input,num;
char in;
 void start()
    {
        cout<<"请选择难度\n";
        cout<<"1，初级：0-100\n";
        cout<<"2，中级：0-1000\n";
        cout<<"3， 地狱级：0-10000\n";
        cin>>in;
switch(in)
{
    case '1':maxnum=100;cout<<"小菜鸡，欢迎进入初级模式，请输入您猜的0-100任意数\n";break;
    case '2':maxnum=1000;cout<<"勇士，欢迎来到中级模式，请输入0-1000任意数\n";break;
    case '3':maxnum=10000;cout<<"抖m，欢迎来到地狱哈哈哈哈哈，你随便输吧，看看上面写了啥\n";break;
}
  num=rand()%maxnum;




    }
void game()
{
    cin>>input;
 if(input>maxnum)
{
    cout<<"这都能输错？！难道是手抖？！(￢_￢)\n";
    game();
}
  else if(input<num)
{
    cout<<"不行不行，太小了(。＾▽＾)\n";
    game();
}
 else if(input>num)
{
    cout<<"输进来的数字大了(。_。)\n";
    game();
}
 else if(input=num)
{

    cout<<"恭喜你成功了！╰(￣▽￣)╭\n";
    cout<<"请再来一局吧英雄！\n";
    cout<<"y(es) or n(o)\n";
    cin>>in;
    switch(in)
    {
        case 'y':system("cls");start();game();
        case 'n':return;
    }
}
}

int main()
{
    cout << "猜数字游戏" << endl;
    srand(time(NULL));
   start();
     game();
}
