#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
#include<windows.h>
int main()
{
	while(1)
	{
	int a,b,c,x,min,max;
	char d;
	printf("请输入游戏人数:",x);
	scanf("%d",&x);
	printf("请输入上下限，用空格隔开：",min,max);
	scanf("%d %d",&min,&max);
	int min1=min,max1=max;

    c=1;
    srand(time(NULL));
	a=1+(rand()%max);
	printf("%d",a);
	Sleep(2000);
	system("cls");
	while(1)
    {
		printf("请第%d个玩家输入猜的数字；\n",c);
		scanf("%d",&b);
		
		if(b<min1||b>max1)
		printf("输入数据有误，请输入一个%d~%d的数字：",min1,max1);
		else
		{
	    	if(b==a) 
	    	{
	    		printf("第%d个玩家猜对了，游戏结束。\n",c);
		    	printf("请问是否重新开始？Y or N") ;
				getchar();
				scanf("%c",&d);
				if(d=='N' || d=='n')
				exit(0); 
				system("cls");
		    	break;
			}
			else	    
		    {
		    	if(b>a)
		    	printf("大了,");
				else
				printf("小了,") ;
				c=c+1; 
			}
		}
		if(c==x+1)
		c=1;
	}	
	}
} 

