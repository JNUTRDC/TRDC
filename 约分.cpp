#include<stdio.h>
#include<stdlib.h>
int main()
{
	int A,B,i;	//A和B分别是分子和分母，i是用来循环的，最后的i就是它们的最大公约数 
	for(;;)
	{
		printf("\n	请分别输入分子和分母：");
		scanf("%d%d",&A,&B);
		if(B==0)
		{
			printf("\n\n	无意义\n\n");
		}
		if(A==0&&B!=0)
		{
			printf("\n\n	化简后为  0\n\n");
			break;
		}
		if(A!=0&&B!=0)
		{
			if(A==B)
			{
				printf("\n\n	化简后为	1\n\n");
				break;				 
			}
			for(i=A;i>1;i--)
			{
				if((A%i)==0&&(B%i)==0)
				{
					A=A/i;
					B=B/i;
					if(B==1)
					{
						printf("\n	化简后为	%d\n\n",A);
						break;
					}
					printf("\n\n	化简后为	%d/%d\n\n",A,B);
					break;
				}
			}
			break;			
		}
	}
	system("pause");
}
