#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
int main()
{
	int a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16;
	int c,d,e,f,g,i,j,m,n;
	srand((unsigned)time(NULL));
	a1=rand()%13+1;		
	a2=(a1+7)%13+1;	
	a3=(a2+7)%13+1;	
	a4=(a3+7)%13+1;	
	a5=(a4+7)%13+1;	
	a6=(a5+7)%13+1;	
	a7=(a6+7)%13+1;	
	a8=(a7+7)%13+1;
	a9=a1;
	a10=a2;
	a11=a3;
	a12=a4;
	a13=a5;
	a14=a6;
	a15=a7;
	a16=a8;
	int a[]={a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16};
	for(g=1;g<=50;++g)
	{ 
		i=rand()%16;
		j=rand()%16;
		c=a[i];
		a[i]=a[j];
		a[j]=c;
	}
	printf("\n\n	%d	%d	%d	%d\n\n\n	%d	%d	%d	%d\n\n\n	%d	%d	%d	%d\n\n\n	%d	%d	%d	%d\n\n\n",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9],a[10],a[11],a[12],a[13],a[14],a[15]);
	printf("\n\n记住所有数字位置之后请输入任意字符开始游戏：");
	e=scanf("%d",&d);
	if(e!=1)
	{
		fflush(stdin);
	}
	system("cls");
	printf("\n							对应序号如下\n	0	0	0	0		1	2	3	4\n\n\n	0	0	0	0		5	6	7	8\n\n\n	0	0	0	0		9	10	11	12\n\n\n	0	0	0	0		13	14	15	16\n\n\n");	
	int b1=0,b2=0,b3=0,b4=0,b5=0,b6=0,b7=0,b8=0,b9=0,b10=0,b11=0,b12=0,b13=0,b14=0,b15=0,b16=0;
	int b[]={b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,b16};	
	printf("	请输入要翻开的两张牌的序号（用空格隔开）：");
	f=scanf("%d%d",&m,&n);
	for(;;)
	{
		for(;;)
		{
			for(;;)
			{
				if(f!=2)
				{
					for(;;)
					{			
						fflush(stdin);
						printf("\n格式不对，再输一次：");
						f=scanf("%d%d",&m,&n);
						if(f==2)
						{
							break;
						}
					}
				} 
				if(m==n&&m<=16&&m>=1&&n<=16&&n>=1)
				{
					printf("\n两个数字不能一样，请重新输入：");
					f=scanf("%d%d",&m,&n);				 
				}
				if(m>16||m<1||n>16||n<1)
				{
					printf("\n数据范围不对，请重新输入：");
					f=scanf("%d%d",&m,&n);				
				}
				if(b[m-1]!=0||b[n-1]!=0)
				{
					printf("\n已经翻过的牌不能再选了，请重新输入：");
					f=scanf("%d%d",&m,&n);
				}
				if(m!=n&&m>=1&&m<=16&&n>=1&&n<=16&&b[m-1]==0&&b[n-1]==0)
				{
					break;
				}				 
			}			
			if(a[m-1]!=a[n-1])
			{			
				printf("\n猜错了，两个数分别是%d和%d,再试一次吧：",a[m-1],a[n-1]);
				f=scanf("%d%d",&m,&n); 
			}				
			if(a[m-1]==a[n-1])
			{	
				system("cls");
				b[m-1]=a[m-1];
				b[n-1]=a[n-1];
				printf("\n							对应序号如下\n	%d	%d	%d	%d		1	2	3	4\n\n\n	%d	%d	%d	%d		5	6	7	8\n\n\n	%d	%d	%d	%d		9	10	11	12\n\n\n	%d	%d	%d	%d		13	14	15	16\n\n\n",b[0],b[1],b[2],b[3],b[4],b[5],b[6],b[7],b[8],b[9],b[10],b[11],b[12],b[13],b[14],b[15]);
				break;
			}				
		}
		if(b[0]!=0&&b[1]!=0&&b[2]!=0&&b[3]!=0&&b[4]!=0&&b[5]!=0&&b[6]!=0&&b[7]!=0&&b[8]!=0&&b[9]!=0&&b[10]!=0&&b[11]!=0&&b[12]!=0&&b[13]!=0&&b[14]!=0&&b[15]!=0&&b[m-1]==b[n-1])
		{
			printf("成功过关,恭喜！");
			break; 
		}
		printf("猜对了，请继续猜：");
		f=scanf("%d%d",&m,&n);
	}
	system("pause");
}
