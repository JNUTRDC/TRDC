#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
int i,n,sl,sr,ans,a,a1;
char flag='y';
void fun()
{
	i=1;
	do{
		printf("第%d个人请输入一个%d~%d的数字:",i,sl,sr);
		scanf("%d",&a);
		while(a==a1)
			scanf("%d",&a);
		if(a<ans){
			printf("小了\n");
			sl=a;
		}
		if(a>ans){
			printf("大了\n");
			sr=a;
		}
		if(a==ans){
			printf("第%d个人Boom!!!\n",i);
			return ;
		}
		if(i<n)
			++i;
		else
			i=1;
		a1=a;
	}while(1);
}
int main()
{
	srand((unsigned)time(0));
	int t1,t2;
	while(flag=='y'){
		printf("请输入游戏人数:");
		scanf("%d",&n);
		printf("请输入上下限,用空格隔开:");
		scanf("%d%d",&sl,&sr);
		ans=rand()%(sr-sl);
		ans+=sl;
		printf("%d",ans);
		t1=clock();
		do{
			t2=clock();
		}while(t2-t1<2000);
		system("cls");
		fun();
		do{
			printf("请问是否重新开始?  y(es) or n(o):");
			scanf("%c",&flag);
		}while(flag!='y'&&flag!='n');
		if(flag=='n')
			break;
		system("cls");
	}
	return 0;
}
