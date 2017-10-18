#include<stdio.h>
#include<math.h>
#include<stdlib.h>
main()
{
	int z;	
	for(z=0;;++z)
	{	
		float a,b,c,d;
		int ab,g,bc,cd,de,ef;	
		printf("\n			一元三次方程求实数解近似值\n\n				<玩不坏版>\n\n			     aX^3+bX^2+cX+d=0\n\n	请输入系数：\n\n  a=");
		bc=scanf("%f",&a);
		for(g=0;;++g)
		{
			if(bc==1)
			{
				break;
			}
			if(bc!=1)
			{
				fflush(stdin);
				printf("\n	格式错误，请重新输入\n\n  a=");
				bc=scanf("%f",&a);
			}
		}		
		for(g=0;;++g)
		{	
			if(a==0)
			{
				printf("\n a不能为0哦，不然就不是三次方程了\n\n请重新输入一次吧！\n\n  a=");
				scanf("%f",&a);
			}
			if(a!=0)
			{
				break;
			}
		}
		printf("\n  b=");
		cd=scanf("%f",&b);
		for(g=0;;++g)
		{
			if(cd==1)
			{
				break;
			}
			if(cd!=1)
			{
				fflush(stdin);
				printf("\n	格式错误，请重新输入\n\n  b=");
				cd=scanf("%f",&b);
			}
		}
		printf("\n  c=");
		de=scanf("%f",&c);
		for(g=0;;++g)
		{
			if(de==1)
			{
				break;
			}
			if(de!=1)
			{
				fflush(stdin);
				printf("\n	格式错误，请重新输入\n\n  c=");
				de=scanf("%f",&c);
			}
		}
		printf("\n  d=");
		ef=scanf("%f",&d);
		for(g=0;;++g)
		{
			if(ef==1)
			{
				break;
			}
			if(ef!=1)
			{
				fflush(stdin);
				printf("\n	格式错误，请重新输入\n\n  d=");
				ef=scanf("%f",&d);
			}
		}				//这之前的代码全部是用来纠错的 
		if(a<0)
		{
			a=-a;
			b=-b;
			c=-c;
			d=-d;		
		}				//系数正负转化，方便后面的讨论
		double i,k,p,q;
		int o,j,h;	
		if(b*b<=3*a*c)
		{		
			if(b*b==3*a*c)
			{
				k=-b/(3*a);
				p=a*k*k*k+b*k*k+c*k+d;
				o=1;
				if(p>0)
				{				
					for(j=0;;++j)
					{
						i=-b/(3*a)-o;
						q=a*i*i*i+b*i*i+c*i+d;
						o=o*2;
						if(q<=0)
						{
							break;
						}
					}				
				}
				if(p<0)
				{
					for(j=0;;++j)
					{
						i=-b/(3*a)+o;
						q=a*i*i*i+b*i*i+c*i+d;
						o=o*2;
						if(q>=0)
						{
							break;
						}
					}
				}				
				for(h=0;h<50;++h)
				{
					i=i-(a*i*i*i+b*i*i+c*i+d)/(3*a*i*i+2*b*i+c);
				}
				if(p==0)
				{
					i=-b/(3*a);
				}
			}
			if(b*b<3*a*c)
			{
				i=-b/(3*a);		
				for(h=0;h<100;++h)
				{			
					i=i-(a*i*i*i+b*i*i+c*i+d)/(3*a*i*i+2*b*i+c);			
				}
			}	
			printf("\n这个方程对应的函数是单调的\n\n所以只有一个实数解\n\n  即\n\n				X=%.16f",i);
		}
		if(b*b>3*a*c)
		{
			double r,s,t,u;
			int w,y;
			r=(-b-sqrt(b*b-3*a*c))/(3*a);
			s=(-b+sqrt(b*b-3*a*c))/(3*a);
			t=a*r*r*r+b*r*r+c*r+d;
			u=a*s*s*s+b*s*s+c*s+d;
			if(t*u>=0)
			{
				if(d>0)
				{
					o=1;
					for(w=0;;++w)
					{						
						i=r-o;
						o=o*2;
						if(a*i*i*i+b*i*i+c*i+d<=0)
						{
							break;
						}
					}
				}
				if(d<0)
				{
					o=1;
					for(w=0;;++w)
					{
						
						i=s+o;
						o=o*2;
						if(a*i*i*i+b*i*i+c*i+d>=0)
						{
							break;
						}										
					}
				}
				for(h=0;h<100;++h)
				{
					i=i-(a*i*i*i+b*i*i+c*i+d)/(3*a*i*i+2*b*i+c);				
				}
			}
			if(t*u>0)
			{
				printf("\n这个方程只有一个实数解\n\n  即\n\n				X=%.16f",i);
			}
			if(t*u==0)
			{
				if(t==0)
				{
					printf("\n这个方程刚好有两个解\n\n  分别是\n\n				X1=%.16f\n\n				X2=%.16f",r,i);				
				}
				if(u==0)
				{
					printf("\n这个方程刚好有两个解\n\n  分别是\n\n				X1=%.16f\n\n				X2=%.16f",i,s);
				}
			}
			if(t*u<0)
			{
				double m,n,v;
				o=1;
				for(w=0;;++w)
				{
					
					m=r-o;
					o=o*2;
					if(a*m*m*m+b*m*m+c*m+d<=0)
					{
						break;
					}
				}
				for(h=0;h<100;++h)
				{
					m=m-(a*m*m*m+b*m*m+c*m+d)/(3*a*m*m+2*b*m+c);
				}
				o=1;
				for(w=0;;++w)
				{
				
					n=s+o;
					o=o*2;
					if(a*n*n*n+b*n*n+c*n+d>=0)
					{
						break;
					}
				}
				for(h=0;h<100;++h)
				{
					n=n-(a*n*n*n+b*n*n+c*n+d)/(3*a*n*n+2*b*n+c);
				}
				v=(r+s)/2;
				for(h=0;h<100;++h)
				{				
					if(a*v*v*v+b*v*v+c*v+d>0)
					{
						r=v;
						v=(r+s)/2;						 
					}
					if(a*v*v*v+b*v*v+c*v+d<0)
					{
						s=v;
						v=(r+s)/2;
					}
					if(a*v*v*v+b*v*v+c*v+d==0)
					{
						break;
					}
				}
				printf("\n这个方程有三个解\n\n  分别是\n\n				X1=%.16f\n\n				X2=%.16f\n\n				X3=%.16f",m,v,n);
			}		
		}
		printf("\n\n输入1保留历史纪录\n输入2清空屏幕\n输入其他数字退出：");
		scanf("%d",&ab);
		if(ab!=1)
		{
			if(ab==2)
			{
				system("cls");
			}
			else
			{
				break;
			}			
		}	
	}	
}
