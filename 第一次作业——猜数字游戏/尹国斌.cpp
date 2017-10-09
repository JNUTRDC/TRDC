#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
using namespace std;

int judge(int num,int min,int max,int answer)
{
    if(num==answer)return 3;
    if((num>min) && (num <answer))
        return 1;
    if((num<max) && (num >answer))
        return 2;
    if((num>max) || (num <min))return 4;

}

int main()
{
    int players,MAX,MIN,temp,reply,count=1;
    char hahaha='n';
    do{
    cout << "请输入游戏人数:";
    cin >> players;
    cout <<"请输入上下限，用空格隔开：";
    cin >>MIN>>MAX;
    //int answers;
    //cin>>answers;
    int answers=MIN+rand()%(MAX-MIN+1);
    cout << answers<<endl;
    Sleep(2000);
    system("Cls");
    do
    {
        cout<<"第"<<count<<"个人请输入一个"<<MIN<<"~"<<MAX<<"的数字:";
        cin>>reply;
        temp=judge(reply,MIN,MAX,answers);
        switch(temp)
        {
            case 4:cout<<"输入数据有误，请输入一个"<<MIN<<"~"<<MAX<<"的数字:"<<endl;count--;break;
            case 3:cout<<"第"<<count<<"个人Boom!!!"<<endl;break;
            case 2:cout<<"大了"<<endl;MAX=reply;break;
            case 1:cout<<"小了"<<endl;MIN=reply;break;
        }
        //cout<<"temp="<<temp<<endl;
        count=count%players;
        count++;
    }while(temp!=3);
    cout<<"PLAY AGAIN?(y or n)";
    cin>>hahaha;
    system("Cls");
    }while(hahaha=='y');
       return 0;
}
