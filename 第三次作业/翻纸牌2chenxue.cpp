 #include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>  
int main()
{
	int a[4][4];
	int i,j,m,n,x1,x2,y1,y2;
	int card[16];
	int opened[16];
	for(i=1;i<=4 ;i++)
	{
		for(j=1;j<=4;j++)
		{			
			srand(time(NULL));
			m=1+(rand()%8);//m��ֵ��������ֻ�������ȡһ��ֵ 
			printf("a[%d][%d]:%d\n",i,j,m);
		}		
	}
	sleep(2000);
	system("cls");
	if(opened[i]) 
	printf("%d",card[i]);
	else
	printf("*");
	printf("\n");
	printf("�������һ��������꣨�ÿո��������");
	scanf("%d %d",&x1 &y1); 
	printf("%d",card[n])
	printf("������ڶ���������꣨�ÿո��������");
	scanf("%d %d",&x2 &y2);
	printf("%d",card[o]); 
	if(x1<1||x1>4||x2<1||x2>4||y1<1||y1>4||y2<1||y2>4)
	printf("����������������������")��
	else
	{ 
	if(card[o]==card[n])
	printf("%d %d",o,n);//�Ҿ����������⣬���Ҳ�֪����ôд 
	else
	printf("* *");
	printf("�������Ϸ")
	getcher()}  //Ȼ����ôѭ���ҾͲ�֪���� 
 } 
