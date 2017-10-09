#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
int main()
{
	int min,max;
	int answer;
	int r;
	int count = 0;
	int a = 0;
	int b = 1;
	int people;
	int c;
	for(r = 1;;r++)
	{
	printf("请输入游戏人数：");
	scanf("%d",&people);
	printf("请输入上下限，用空格隔开：");
	scanf("%d %d",&min,&max) ;
	answer = rand()%(max-min+1)+min;
	printf("%d",answer);
	int time;
	time=2;
	while(1)
	{
		Sleep(1000);
		time--;
		if(time==0)
		{
			break;
		}
	}
         system("cls");
	do {
		printf("第%d个人请输入一个%d~%d的数字：",b,min,max);
		scanf("%d",&a);
		if ( a > answer and a < max ) {
			printf("大了。",b);
			max=a;
			b++;
			if(b>people) 
			    {
	         	b=1;
		     	}
		    } else if ( a < answer and a >min ) {
			printf("小了。",b);
			min=a;
			b++;
			if(b>people)
		     	{
		    	b=1;
		    	}
	    	} else if ( a > max or a <min) {
		    printf("输入数据有误，请输入一个%d~%d的数字：",min,max);
	       	}
		count ++;
     	} while (a != answer);
	printf("第%d人Boom!!! \n",b);
	printf("请问是否重新开始？，1(Yes) or 2(No)");
    scanf("%d,&c");
	if (c==1) { break;}
    if (c!=1) { system("cls");}
	} 
	getchar();
	getchar();
	return 0;
} 
