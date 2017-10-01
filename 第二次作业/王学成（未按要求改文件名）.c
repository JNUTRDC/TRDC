#include<stdio.h>
main()
{
	int countorange=14;
	int countwatermelon=3;
	int orangeweight=100;
	int watermelonweight=200;
	int totalorange=countorange*orangeweight;
	int totalwatermelon=countwatermelon*watermelonweight;
	int total=totalorange+totalwatermelon;
    int equalside=total/2;
	int leftholdorange=equalside/orangeweight;
	int rightholdorange=countorange-leftholdorange;
	printf("左边放%d箱的橘子，右边放%d箱的橘子和%d箱的西瓜",leftholdorange,rightholdorange,countwatermelon);
}
