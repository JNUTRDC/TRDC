#include<stdio.h>
#include<stdlib.h>
int main()
{
	int A,B,i;	//A��B�ֱ��Ƿ��Ӻͷ�ĸ��i������ѭ���ģ�����i�������ǵ����Լ�� 
	for(;;)
	{
		printf("\n	��ֱ�������Ӻͷ�ĸ��");
		scanf("%d%d",&A,&B);
		if(B==0)
		{
			printf("\n\n	������\n\n");
		}
		if(A==0&&B!=0)
		{
			printf("\n\n	�����Ϊ  0\n\n");
			break;
		}
		if(A!=0&&B!=0)
		{
			if(A==B)
			{
				printf("\n\n	�����Ϊ	1\n\n");
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
						printf("\n	�����Ϊ	%d\n\n",A);
						break;
					}
					printf("\n\n	�����Ϊ	%d/%d\n\n",A,B);
					break;
				}
			}
			break;			
		}
	}
	system("pause");
}
