#include <iostream>

/*Note:
    (备注)装车指南
    橘子货箱重100磅
    西瓜货箱重200磅
    必须先装卡车的左边再装右边，并保持平衡。每边各装多少？
    西瓜始终放在一起。
    let co=14  //共有14箱
    let cw=3

    let ow=100
    let ww=200
    let to=co*ow
    let tw=cw*ww  //total
    let ttl=to+tw
    let es=ttl/2
    let lhso=es/ow  //left hold
    let rhso=co-lhso  //
*/
using namespace std;

int main()
{
    int WATERMELON_WEIGHT = 200;
    int CONTAINERS_WATERMELON = 3;
    int ORANGE_WEIGHT = 100;
    int CONTAINERS_ORANGE = 14;
    int TotalWatermelon = WATERMELON_WEIGHT * CONTAINERS_WATERMELON;
    int TotalOrange = ORANGE_WEIGHT * CONTAINERS_ORANGE;
    int TotalTruckLoad = TotalOrange + TotalWatermelon;
    int eachSide = TotalTruckLoad / 2;
    int leftHoldsomeOrange = eachSide / ORANGE_WEIGHT;
    int righHoldsomeOrange = CONTAINERS_ORANGE - leftHoldsomeOrange;
    cout<<"LEFT:"<<leftHoldsomeOrange<<endl<<"RIGHT:"<<righHoldsomeOrange;
    return 0;
}
