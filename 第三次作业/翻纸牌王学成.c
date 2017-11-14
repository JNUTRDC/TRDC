#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
int e[4][4]={0};
int p,q;
void output()
{	
	for(p=0;p<4;p++)
		{
			for(q=0;q<4;q++) printf("%4d",e[p][q]);
			printf("\n");
		}
}
main()
{
    int card[4][4]={0};
	int i,p1,p2,d,p,q;
	int	x1,x2,y1,y2;
	srand(time(0));
	for(i=1;i<=16;i++)
	{
		p1=rand()%4;
		p2=rand()%4;
		while(card[p1][p2]) {p1=rand()%4;p2=rand()%4;}
		card[p1][p2]=(i+1)/2;
	}
	for(p1=0;p1<4;p1++)
	{
		for(p2=0;p2<4;p2++) printf("%4d",card[p1][p2]);
		printf("\n");
	}
	Sleep(4000);
	system("cls");
	output();
	for(d=1;d<=10000;d=d+2)
	{
		printf("请输入第%d个坐标，以逗号隔开\n",d);
		scanf("%d,%d",&x1,&y1);
		if(x1>4||x1<1||y1>4||y1<1) {printf("输入数据有误\n");}
		x1-=1;y1-=1;
		e[x1][y1]=card[x1][y1];
		output();
		printf("请输入第%d个坐标，以逗号隔开\n",d+1);
		scanf("%d,%d",&x2,&y2);
		if(x2>4||x2<1||y2>4||y2<1) {printf("输入数据有误\n");}
		x2-=1;y2-=1;
		if(card[x2][y2]==card[x1][y1]) e[x2][y2]=card[x2][y2];
		else {e[x1][y1]=0;e[x2][y2]=0;}
		output();
		for(p=0,q=0;e[p][q]!=0;) {q++;if(q>3) {p++;q=0;}}
		if(p>=4) break;
	}		
	printf("You win\n");
}