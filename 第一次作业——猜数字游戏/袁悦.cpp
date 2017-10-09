#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int n;
	int i;
	int a;
	int b;
	int q;
	int(i=0);
	printf("输入参与的人数:  \n");
    scanf("%d",&q);
	printf("输入要扔的最大可能值：  \n");
    scanf("%d",&n);
	srand(time(NULL));
    a=1+(rand()%n);
   for(i=1;i<=q;i++)
{
	printf("第%d聪明的你猜我会把林小浩从几楼扔下去:   ",i);
	scanf("%d",&b);
		if(a==b)
		{
  printf("恭喜你猜对啦！\n");
  break;
		}
if(b<a)
  printf("楼层太低啦！\n");
if(b>a)
  printf("林小浩会成饼的，你萌这样很容易失去他。。\n");
   }
   getchar;
}



     