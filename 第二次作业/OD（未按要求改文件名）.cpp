#include<stdio.h>
 void main()
{
double containerOrange=14;
double containerWatermelon=3;
double orangeWeight=100;
double watermelonWeight=200;
double totalOrange=containerOrange*orangeWeight;
double totalWatermelon=containerWatermelon*watermelonWeight;
double totalWeight= totalOrange+totalWatermelon;
double halfOfTheWeight=totalWeight/2;
double orangeContainerNumberOfTheHalf=halfOfTheWeight/orangeWeight;
double orangeContainerNumberLeft=containerOrange- orangeContainerNumberOfTheHalf;
	printf("一边橘子的箱数为%lf",orangeContainerNumberOfTheHalf);
    printf("另一边橘子的箱数为%lf",orangeContainerNumberLeft);
}