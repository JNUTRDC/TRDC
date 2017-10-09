#include"stdio.h"  /*调用输入输出库函数 服务于printf,scanf*/ 
#include <stdlib.h>  /*调用（清屏）标准库函数 服务于sleep*/ 
#include<windows.h>  /*调用windows（延迟）标准库函数 服务于system*/ 
main()
  {int boom,num,input,no,up,down,cho=1;  /*boom爆炸数字，num总人数，input输入数字，no当前玩家序号，up当前上限，down当前下限，cho最终选择 */  /*00*/ 
   int system(const char *string);
    do
     {no=1;   /*01*/
	  printf("请输入玩家数目：");  /*上帝视角输入玩家数目、上限、下限*/
      scanf("%d",&num);
      printf("请输入上限：");
      scanf("%d",&up);
      printf("请输入下限：");
      scanf("%d",&down);
         if(up<down)  /*检查上下限是否合法*/
         {printf("请输入爆炸数字：");  /*02*/ 
          scanf("%d",&boom);
             if(up<boom and boom<down)  /*检查爆炸数字是否合法*/
             {Sleep(2000);   /*03*/
			  system("cls");
			  do  
			    {printf("请第%d位玩家输入一个%d~%d的数字：",no,up,down);   /*玩家n输入数字*/ /*04*/
			     scanf("%d",&input);
                    if(up<input and input<down)  /*检查输入数字是否合法*/
                    {if(input<boom)  /*如果输入值小于爆炸值*/  /*05*/
                       {printf("小了\n");  /*06*/
                        up=input;
                           if(no!=num)  /*判断是否为最后一位玩家*/
                            {no=no+1;  /*返回第一位玩家*/  /*07*/
							}else(no=1);  /*下一位玩家*/  /*07*/ 
					   } else{if(input>boom)  /*如果输入值大于爆炸值*/  /*06*/  /*10*/
					          {printf("大了\n");  /*08*/
					           down=input;
					           if(no!=num)  /*判断是否为最后一位玩家*/
					           {no=no+1;  /*返回第一位玩家*/  /*09*/
					           }else(no=1);  /*下一位玩家*/  /*09*/
							   }   /*08*/
					   }  /*10*/
					 } else{printf("输入数字错误！",up,down);  /*05*/  /*11*/
					 }  /*11*/
                }while(input!=boom);  /*04*/
                 printf("第%d位玩家Boom!!!\n",no);
                 printf("是否重新开始游戏？1-yes or 2-no：");
                 scanf("%d",&cho);
                 Sleep(2000);
                 system("cls");
			  }  /*03*/
		  } else printf("输入的爆炸数字有误") ;/*02*/
  }while(cho!=2);
  }  /*00*/
