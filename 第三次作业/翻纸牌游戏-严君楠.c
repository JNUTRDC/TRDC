#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
int main()
{
	
	int a,b;
	int i,p;
	int oc=0;
	int card[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int opened[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	srand(time(0));
	
	for (i=1;i<=16;i++)
	{
		p=rand()%16;
		while(card[p])
		{
			p=rand()%16;
			card[p]=(i+1)/2;
		}
	}
	printf("���������ʼ");
	getch();
	while(oc<3)
	{
//do1
		do
		{
			system("cls");
//for1
			for(i=0;i<16;i++)
			{
			if(opened[i]>0)
				printf("%d",card[i]);
			else
			{
				printf("*");
				printf("\n");
				printf("�������һ���Ƶ�λ��:");
				scanf("%d",&a);
			}
		}
//for1
		}while(!(0<a && a<=16 &&!opened[a-1]));
//do1
	
//do2
	do
	{
		system("cls");
		for(i=0;i<16;i++)
		{
		if(opened[i] || (i==(a-1)))
		printf("%d",card[i]);
		else
		{
		printf("*");
		printf("");
		printf("������ڶ����Ƶ�λ��:");
        scanf("%d",&b);
		}
		}
	}while(!(0<b && b<=16 && !opened[b-1]&&b !=a));
//do2
	system("cls");
	for (i=0;i<16;i++)
	{
	if(opened[i] || i==a-1||i==b-1)
		printf("%d",card[i]);
	else
	{	printf("*");
	    printf("");
		printf("��������");
		getch();
		if(card[a-1]==card[b-1])
		{
		oc++;
		opened[a-1]=1;
		opened[b-1]=1;
		}
	}
	}	
	
	 system("cls");
	 printf("��ϲ�� �ɹ���");
	 return 0;
}
}