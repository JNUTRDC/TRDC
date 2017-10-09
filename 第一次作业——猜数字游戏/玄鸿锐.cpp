#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
int main(){
    int a, b, c, d, i, e;
    char a1;
v:
    printf("请输入游戏人数:");
    scanf("%d",&a);
    printf("请输入上下界，用空格隔开:");
    scanf("%d%d",&b,&c);
    srand( (unsigned)time( NULL ) );
    d = rand()%(c-b+1)+b;
    printf("%d\n", d);
    sleep(2);
    system("cls");
    for(i=0;i<a;i=(i+1)%a){
    	printf("第%d个人输入一个%d到%d数字：", i+1, b, c);
    	scanf("%d", &e);
		if(e > d)
		   printf("大了\n");
		if(e < d)
		   printf("小了\n");
	    if(e == d)
		{ 
		   printf("第%d个人boom!!!", i+1);
		   printf("是否重新开始？Y or N  ");
		   getchar();
		   scanf("%c", &a1);
		   if(a1 == 'y' || a1 == 'Y'){
		   	    system("cls");
				goto v;
		   }
		   else{
		        return(0);
		   } 
		}
	
		  
	}
}

