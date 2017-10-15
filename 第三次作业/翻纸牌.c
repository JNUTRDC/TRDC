#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
int b[4][4]={0},p,q;
void put(){
     for(p=0;p<4;p++)
        {for(q=0;q<4;q++)
     printf("%4d",b[p][q]);printf("\n");}
}
void main(){
     int a[4][4]={0},h,i,j,d,x1,y1,x2,y2;
     srand( (unsigned)time( NULL ) );
     for(h=1;h<=16;h++){
       i=rand()%8;
       j=rand()%8;
       while(a[i][j]){
          i=rand()%8;
          j=rand()%8;}
       a[i][j]=(h+1)/2;
     }
     for(i=0;i<4;i++){
       for(j=0;j<4;j++)
          printf("%4d",a[i][j]);printf("\n");
     }
     Sleep(2000);
     system("cls");
     put();
     for(d=1;d<1000000;d=d+2){
z:   printf("请输入第%d个数的坐标(用空格隔开)\n",d);
     scanf("%d%d",&x1,&y1);
     if(x1>4||x1<1||y1>4||y1<1){
        printf("worng printf\n");
        printf("请输入第%d个数的坐标(用空格隔开)\n",d);
        scanf("%d%d",&x1,&y1);
        goto v;
     }
 v:  x1=x1-1,y1=y1-1;
     b[x1][y1]=a[x1][y1];
     put();
     printf("请输入第%d个数的坐标(用空格隔开)\n",d+1);
     scanf("%d%d",&x2,&y2);
     if(x2>4||x2<1||y2>4||y2<1){
        printf("worng printf\n");
        printf("请输入第%d个数的坐标(用空格隔开)\n",d+1);
        scanf("%d%d",&x2,&y2);
        goto w;
     }
w:   x2=x2-1,y2=y2-1;
     if(a[x1][y1]==a[x2][y2]){
        b[x2][y2]=a[x2][y2];
        put();
        }
     else{
         b[x2][y2]=a[x2][y2];
         put();
         b[x2][y2]=0,b[x1][y1]=0;
         Sleep(2000);
         printf("请重新游戏\n");
         put();
         goto z;



     }
  }
}






