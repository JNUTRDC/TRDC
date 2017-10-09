#include<stdio.h>
#include<time.h>
#include<dos.h>
#include<stdlib.h>
#include<windows.h>
int main()
{
    int min,max,target,guess,a,bl=0;
    long Itend,Itstart;
    float timeuse;
    char i,c='Y';

	while(1){
		printf("请输入游戏人数：\n");
		scanf("%d",&a);
		printf("请输入上下限，用空格隔开：\n");
		scanf("%d %d",&min,&max);
		srand((unsigned)time(NULL));
		target=rand()%max;
		printf("target=%d\n",target);
		_sleep(2);
		system("cls");
		bl=0;
		Itstart=clock();
		while(1){
			for(i=1;i<=a;i++)
			{
				printf("第%d个人请输入一个%d~%d的数字：\n",i,min,max);
				scanf("%d",&guess);
				if(guess<min||guess>max)
				{
					printf("输入数据有误，请输入%d~%d的数字：\n",min,max);
					i=i-1;
					continue;
				}
				else 
				{
					if(target==guess)
					{
						printf("第%d个人Boom!!!\n",i);
						bl=1;
						break;
					}
					else if(target>guess)
					{
						min=guess;
						printf("小了\n");
					}
					else if(target<guess)
					{
						max=guess;
						printf("大了\n");
					}
				}
			}
			if (bl) break;
		}
		Itend=clock();
		timeuse=((float)(Itend-Itstart))/CLOCKS_PER_SEC;
		printf("execution time:%ld millsecond(%f second)\n",Itend-Itstart,timeuse);
		printf("请问是否重新开始？Y（es）orN(o)\n");
		fflush(stdin);
		scanf("%c",&c);
		if(toupper(c)!='Y')
		{
			break;
		}
	}
}
