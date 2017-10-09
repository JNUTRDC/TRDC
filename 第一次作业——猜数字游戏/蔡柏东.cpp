#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
//主程序
void main()
{
	int a,b,c,min,max,boom=0;
	char t;
	for(;;)
	{
		printf("请输入游戏人数:\n");
		scanf("%d",&a);
		printf("请输入上下限，用空格隔开\n");
		scanf("%d%d",&min,&max);
		srand((unsigned)time(0));
		b=rand()%(max-min);
		b+=min;
		system("cls");

		for(;;)
		{
			for(int i=1;i<=a;i++)
			{
				printf("第%d个人请输入一个%d ~ %d的数字:\n",i,min,max);+
				scanf("%d",&c);
				//
				for(;;)
				{
					if(c<min||c>max)
					{
						printf("输入数据有误，请输入一个%d ~ %d的数字:",min,max);
						scanf("%d",&c);
					}
					else break;
				}
				//
				if(c>b)
				{
					printf("大了\n");
					max=c;
				}
				else if(c<b)
				{
					printf("小了\n");
					min=c;
				}
				else
				{
					boom=i;
					break;
				}
			}
			if (boom!=0) break;
		}
			scanf("%c");
			printf("第%d个人boom!\n",boom);
			printf("是否重新开始？y/n :\n");
			scanf("%c",&t);
			if(t!='y')break;
			else system("cls");
	}
}