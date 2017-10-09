#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{  
	int a,c,m,M,number,min,max,guess,count;
	printf("请输入游戏人数:\n");
	scanf("%d\n",&a);
	printf("请输入上下限，用空格隔开:\n");
	scanf("%d %d\n",&m,&M);
	srand((unsigned)time(NULL));
	number=rand()%(M-m+1)+m;
    system("cls");
  do{
	  printf("请输入一个数 %d ~ %d",min,max);
	        scanf("%d",&guess);
			count ++;
			if(number>guess)
			{
				min=guess;
				printf("小了\n",guess);
			}
					else if(number<guess)
				{
					max=guess;
					printf("大了\n",guess);
		}
			else if(a==guess)
				{
				printf("游戏结束，炸弹被引爆:\n",count);
			}
	        else if(guess<min||guess>max)
			{
				printf("错误，请重新猜一个在已定范围内的数\n",guess);
				scanf("%d",&guess);
            printf("请问是否重新开始(Y-yes,N-no):\n");
            fflush(stdin);
            char c='Y';
			scanf("%c",&c);
			}
            if((c) !='Y')
        	break;
            return 0;
 }
