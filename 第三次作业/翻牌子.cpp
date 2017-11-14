#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int main()
{
	int a,b,i,p,q,P,Q,oc=0;
	int card[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	int opened[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	srand(time(0));
	for (i = 1; i <= 16; i++)
    	{
        	p = rand() % 4;q=rand()%4;
        	while (card[p][q]) p = rand() % 4,q=rand()%4;
        	card[p][q] = (i + 1) / 2;
    	}
    for(p=0;p<=3;p++)
		{
			for(q=0;q<=3;q++)printf("  %d",card[p][q]);printf("\n");
		}
	printf("按任意键开始");
    getch();
    
    // while (oc < 3)
   // {
        do
        {
            system("cls");
            for (int P = 0; P < 4; P++)
            	{for(int Q = 0;Q<4;Q++);}
                {
				if (opened[P][Q])
                    printf("%d", card[p][q]);
                else
                    printf("*");
                }
            printf("\n");
            printf("输入你第一张牌的位置:");
            scanf("%d %d", &P,&Q);
        } while (!(0 < P&& P <= 6 && !opened[P - 1][Q -1]&&0 < Q && Q <= 4));
    //} 
    
    
    do
        {
            system("cls");
            for (int P = 0; P < 4; P++){for(int Q =0 ; Q < 4) ;Q++}
                if (opened[P][Q] || P == a - 1)
                    printf("%d", card[P][Q]);
                else
                    printf("*");
            printf("\n");
            printf("输入你第二张牌的位置:");
            scanf("%d", &b);
        } while (!(0 < b && b <= 6 && !opened[b - 1] && b != a));
	
return 0 ;
}
	
