#include<stdio.h> 
#include <stdlib.h>
#include <time.h>
int main()
{
	int N;
	int x,m,M,i,n,a;
	char c;
    do
    {
		printf("请输入游戏人数: ");
	    scanf("%d",&x);
	    printf("请输入游戏上下限:  ");
	    scanf("%d %d",&m,&M);
	    srand((unsigned)time(NULL));
	    i=rand()%(M-m+1)+m;
	    system("cls");
	    do
	    {
	    	for(n=1;n<=x;n++)
			{
	        	printf("请第%d个人输入%d - %d的数字:\n",n,m,M);
	    		do
	    		{
					if(scanf("%d",&a)==1 && m<a && a<M) break;
					getchar();
					printf("输入数据有误,请第%d个人输入%d - %d的数字:\n",n,m,M);
				}
				while(1);
				if(m<a && a<i)
				{
					printf("小了");
	    	   		m=a;
				}
	    	   	if(i<a && a<M)
				{
					printf("大了");
					M=a;
				}
	    	   	if(i==a)
	    	   		break;
	    	}
	    }
        while(a!=i);
        printf("%d\n",a);
        printf("Boom!!!\n");
        printf("请问是否重新开始?Y or N：");
        getchar();
        scanf("%c",&c);
    }
	while(c!='N' && c!='n');
}
    
