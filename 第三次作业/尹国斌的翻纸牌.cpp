#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct rowColumn
{
    int row;
    int column;
    char Temp;
};

struct card
{
    char Front;
    char Contrary;
    char Condition;//close->c,open->o
};

rowColumn gain(rowColumn S)//�ж������Ƿ������ȡһ��������
{
    int bing=0;
    do
    {
        cout<<"������Ҫ����С��У�"<<endl;
        cin>>S.row>>S.column;
        if((S.row*S.column)%2==0 && (S.row*S.column)<=26)
            bing=1;
        else
        {
            cout<<"���ݲ�����Ŷ����������"<<endl;
            Sleep(3000);
            system("Cls");
        }
    }
    while(bing==0);
    return S;
}

void print(card(&blocks)[26][26],int row,int column)//��ӡ�������
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            if(blocks[i][j].Condition=='c')cout<<blocks[i][j].Contrary<<' ';
            else cout<<blocks[i][j].Front<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}

void renew(card (&blocks)[26][26],int row,int column)//Ϲ���Ѹ�ֵ
{
    for(int i=0; i<26; i++)
        for(int j=0; j<26; j++)
        {
            blocks[i][j].Contrary='%';
            blocks[i][j].Condition='c';
            blocks[i][j].Front='@';
        }
    char a[14];
    int x,y,tempFornum[13]= {0},counts,tempCounts,tempForchar;
    counts=0;a[1]='1';a[2]='2';a[3]='3';a[4]='4';
    a[5]='5';a[6]='6';a[7]='7';a[8]='8';a[9]='9';
    a[10]='I';a[11]='J';a[12]='Q';a[13]='K';
    for(int i=0; i<row; i++)
       {
            for(int j=0; j<column; j++)
            {
                tempCounts=counts;
                do
                {
                    tempCounts=counts;
                    srand((unsigned)time(NULL));
                    tempForchar=rand()%13+1;//��ȡĳ�����Ƶ�����1~13;
                    while(tempCounts>=0)
                    {
                        if(tempFornum[tempCounts]==tempForchar)break;
                        tempCounts--;
                    }
                }while(tempCounts!=-1); //�����ȷ�����ֵ
                tempFornum[counts]=tempForchar;
                while(blocks[i][j].Contrary!='%')
                {
                    j++;
                    if(j==column)
                    {
                        j=0;
                        i++;
                    }
                    if(j==column&&i==row)
                    {
                        cout<<"Finish it"<<endl;
                        break;
                    }
                }
                blocks[i][j].Front=a[tempFornum[counts]];
                blocks[i][j].Contrary='*';
                if(j!=column&&i!=row)
                do
                {
                    srand((unsigned)time(NULL));
                    x=rand()%row;
                    srand((unsigned)time(NULL));
                    y=rand()%column;
                }
                while(blocks[x][y].Contrary=='*');
                blocks[x][y].Contrary='*';
                blocks[x][y].Front=a[tempFornum[counts]];
                counts++;
                if(counts==row*column/2)break;
            }
            if(counts==row*column/2)break;
    }
}
rowColumn getDate(card (&blocks)[26][26],int row1,int column1)//����
{
    rowColumn temp;//��ȡ����
    int bing=0;
    do
    {
        bing=0;
        cout<<"���������뷭���Ƶ����꣺"<<endl;
        cin>>temp.row>>temp.column;
        cout<<endl;
        if(temp.row>0&&temp.row<=row1&&temp.column>0&&temp.column<=column1)bing++;
        else {cout<<"�������ݳ�����Χ������"<<endl;}
        if(blocks[temp.row-1][temp.column-1].Condition=='c')bing++;
        else{cout<<"�˿��ѷ���"<<endl;bing=0;}
    }
    while(bing!=2);
    temp.Temp=blocks[temp.row-1][temp.column-1].Front;
    blocks[temp.row-1][temp.column-1].Condition='o';
    return temp;
}

void Begins(card (&blocks)[26][26],int row,int column)//��Ϸ��ʼ
{
    rowColumn temp1,temp2;
    int counts=0;
    do
    {
        temp1=getDate(blocks,row,column);
        print(blocks,row,column);
        temp2=getDate(blocks,row,column);
        system("Cls");
        print(blocks,row,column);
        if(temp1.Temp!=temp2.Temp)
        {
            blocks[temp1.row-1][temp1.column-1].Condition='c';
            blocks[temp2.row-1][temp2.column-1].Condition='c';
            cout<<"WRONG!!!���������"<<endl;
            Sleep(2000);
            system("Cls");
        }
            else counts++;
        print(blocks,row,column);
    }while(counts!=row*column/2);
    cout<<"You win!"<<endl;
}

int main()
{
    rowColumn gameSize=gain(gameSize);
    card blocks[26][26];
    renew(blocks,gameSize.row,gameSize.column);
    print(blocks,gameSize.row,gameSize.column);
    Begins(blocks,gameSize.row,gameSize.column);//��Ϸ��ʼ
    return 0;
}
