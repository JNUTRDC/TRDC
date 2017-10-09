#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
void main()
{
	char i='y';
	while(i=='y'||i=='Y')
	{
		int a,b,c,d,e,f=1;
		srand(time(NULL));
		printf("请输入游戏人数:");
		scanf("%d",&d);
		printf("请输入猜数字的下限和上限，以逗号隔开");
		scanf("%d,%d",&a,&b);  
		c=a+(rand()%(b-a));
		printf("%d\n",c);
		Sleep(2000);
		system("cls");
		for(;e!=c;)
		{	
		printf("第%d个人请输入一个%d~%d的数字:",f,a,b);
		scanf("%d",&e);
		if(e>b||e<a) printf("输入数据有误,请输入一个%d~%d的数字\n",a,b);
		else {
			  if(e>c) {printf("大了\n");b=e;f=f%d+1;}
			  if(e<c) {printf("小了\n");a=e;f=f%d+1;}
			}
		}
   		printf("第%d个人BOOM!\n",f);
		printf("是否重新开始游戏？（y/n）\n");
		i=getche();
    }
	printf("游戏结束");
}