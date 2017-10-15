#include<stdio.h>//正在看我得代码的这位大佬。。别来气啊。。，我谢谢你能看。。
#include<stdlib.h>
#include<time.h>
#include<conio.h>
int  main()
{
int a,b,c,d;//要输入两次坐标横纵横纵
int i,j,p,x;//循环以及随机数要用的横纵坐标
int oc=0;
int card[4][4]={{0000},{0000},{0000},{0000}};//矩阵16
int opened[4][4]={{0000},{0000},{0000},{0000}};//出来的是一个横行而不是一个矩阵
srand(time(0));
for(i=1;i<=4;i++)
for(j=1;j<=4;j++)
{
p=rand()%4;
x=rand()%4;
while(card[p][x])p=rand()%4,x=rand()%4;
card[p][x]=(i+1)/2,(j+1)/2;//我实际上不懂这里的意思。。我看的网上的一维是这样写的。。就照葫芦画瓢
}
printf("按任意键开始");
getch();
while(oc<3)
{
	do
	{
		system("cls");
		for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		if(opened[i][j])
		printf("%d",card[i][j]);
		else
		printf("*");
		printf("请输入你第一张牌的横坐标");
        scanf("%d",&a);//第一次横坐标
		printf("请你输入第一张牌的纵坐标");
		scanf("%d",&b);//第一次纵坐标
	}
	while(!(0<a&&a<=4&&!opened[a-1][b-1]));//输入完在第一张牌的位置后。。程序就崩溃了
	do
	{
		system("cls");
		for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(opened[i][j]||i==a-1,j=b-1)
				printf("%d",card[i][j]);
			else
				printf("*");
			printf("请输入你第二张牌的横坐标");
        scanf("%d",&c);//第二次横坐标
		printf("请你输入第二张牌的纵坐标");
		scanf("%d",&d);//第二次纵坐标
	}
	while(!(0<b&&b<=6&&!opened[b-1]&&b!=a));
	system("cls");
		for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		if(opened[i]||i==a-1||i==b-1)
			printf("%d",card[i][j]);
		else
			printf("*");
			printf("按任意键继续");
			getch();
			if (card[a-1][b-1]==card[c-1][d-1])
			{
				oc++;
				opened[a-1][b-1]=1;
				opened[c-1][d-1]=1;
}
}
system("cls");
printf("恭喜你成功啦");
return 0;
}
