#include<stdio.h>
#include<time.h>
#include<windows.h>
void main()
{
	int num,x,a,b,i,t,h=1,peo=0;
	char m,n,p,l;
	l=3;
restart:
	printf("请输入游戏人数：\n");
	scanf("%d",&t);
	printf("请输入上下界，并用空格分隔开：");
	scanf("%d %d",&a,&b);
	srand((unsigned)time(NULL));
	i=(rand()%(b+a));
	printf("%d",i);
	Sleep(2000);
	system("cls");
replay:
	{   if(peo<t)++peo;
		else peo=1;
		printf("请第%d个人输入一个%d~%d之间的数\n",peo,a,b);
		scanf("%d",&x);
		if(x==i)
		{   printf("  恭喜第%d个人回答正确！\n",peo);
			printf("%5c%c%2c%c\n",l,l,l,l);
			printf("%4c%3c%3c\n",l,l,l);
			printf("%5c%4c\n",l,l);
			printf("%6c%2c\n",l,l);
			printf("%7c\n",l);
			Sleep(2000);
			system("cls");
			printf("上一局游戏的胜利者是：玩家%d!!%c",peo,l);
			printf("开始新游戏? Y(es) or N(o):\n");
			scanf("%c",&p);
			if(p!=m&&p!=n)printf("请重新输入\n");
			else if(p==m);
			else Sleep(3000);
				 system("cls");
		 	goto restart;
		}

		else
		{   if(x>=a&&x<i)printf("小了\n"),a=x;
			else if(x<=b&&x>i)printf("大了\n"),b=x;
			else;
			goto replay;
		}
	}
}

调试中
#include<stdio.h>
#include<time.h>
#include<windows.h>
void main()
{
	int num,x,a,b,i,t,h=1,peo=0;
	char m,n,p,l;
	l=3;
restart:
	printf("请输入游戏人数：\n");
	scanf("%d",&t);
	printf("请输入上下界，并用空格分隔开：");
	scanf("%d %d",&a,&b);
	srand((unsigned)time(NULL));
	i=(rand()%(b+a));
	printf("%d",i);
	Sleep(2000);
	system("cls");/*开始前数据初始化*/
replay:
	{   if(peo<t)++peo;
		else peo=1;
		printf("请第%d个人输入一个%d~%d之间的数\n",peo,a,b);
		scanf("%d",&x);
		if(x==i)/*猜中了*/
		{   printf("  恭喜第%d个人回答正确！\n",peo);
			printf("%5c%c%2c%c\n",l,l,l,l);
			printf("%4c%3c%3c\n",l,l,l);
			printf("%5c%4c\n",l,l);
			printf("%6c%2c\n",l,l);
			printf("%7c\n",l);
			Sleep(2000);
			system("cls");/*结束礼花*/
			printf("上一局游戏的胜利者是：玩家%d!!%c",peo,l);
			printf("开始新游戏? Y(es) or N(o):\n");
			scanf(" %c",&p);
			if(p!=m&&p!=n)printf("请重新输入\n");
			else if(p==m);
			else Sleep(3000);
				 system("cls");
		 	goto restart;/*重新开始的信息获取*/
		} 
	

		else
		{   if(x>=a&&x<i)printf("小了\n"),a=x;
			else if(x<=b&&x>i)printf("大了\n"),b=x;
			else;
			goto replay;
		} /*循环猜数字*/
	}
}

