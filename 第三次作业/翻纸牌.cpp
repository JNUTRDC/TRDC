#include<stdio.h>//���ڿ��ҵô������λ���С�������������������лл���ܿ�����
#include<stdlib.h>
#include<time.h>
#include<conio.h>
int  main()
{
int a,b,c,d;//Ҫ��������������ݺ���
int i,j,p,x;//ѭ���Լ������Ҫ�õĺ�������
int oc=0;
int card[4][4]={{0000},{0000},{0000},{0000}};//����16
int opened[4][4]={{0000},{0000},{0000},{0000}};//��������һ�����ж�����һ������
srand(time(0));
for(i=1;i<=4;i++)
for(j=1;j<=4;j++)
{
p=rand()%4;
x=rand()%4;
while(card[p][x])p=rand()%4,x=rand()%4;
card[p][x]=(i+1)/2,(j+1)/2;//��ʵ���ϲ����������˼�����ҿ������ϵ�һά������д�ġ������պ�«��ư
}
printf("���������ʼ");
getch();
while(oc<3)
{
	do
	{
		system("cls");
		for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		if(opened[i][j])
		printf("%d",card[i][j]);
		else
		printf("*");
		printf("���������һ���Ƶĺ�����");
        scanf("%d",&a);//��һ�κ�����
		printf("���������һ���Ƶ�������");
		scanf("%d",&b);//��һ��������
	}
	while(!(0<a&&a<=4&&!opened[a-1][b-1]));//�������ڵ�һ���Ƶ�λ�ú󡣡�����ͱ�����
	do
	{
		system("cls");
		for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(opened[i][j]||i==a-1,j=b-1)
				printf("%d",card[i][j]);
			else
				printf("*");
			printf("��������ڶ����Ƶĺ�����");
        scanf("%d",&c);//�ڶ��κ�����
		printf("��������ڶ����Ƶ�������");
		scanf("%d",&d);//�ڶ���������
	}
	while(!(0<b&&b<=6&&!opened[b-1]&&b!=a));
	system("cls");
		for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		if(opened[i]||i==a-1||i==b-1)
			printf("%d",card[i][j]);
		else
			printf("*");
			printf("�����������");
			getch();
			if (card[a-1][b-1]==card[c-1][d-1])
			{
				oc++;
				opened[a-1][b-1]=1;
				opened[c-1][d-1]=1;
}
}
system("cls");
printf("��ϲ��ɹ���");
return 0;
}
