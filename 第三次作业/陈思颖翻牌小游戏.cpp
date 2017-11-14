#include<iostream>//谢谢帮我看的这位大佬
#include<ctime>
#include<cstdlib>
#include<Windows.h>
using namespace std;

const int num = 16;
int poker[num] = { 0 };//poker[num]为16个要猜的随机值
int correct[num] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };//correct[num]为玩家已经猜中的扑克的号码
const char b = '*';
int n[2] = { 0 };//n为猜的数字的序号(就是poker[num]中的那个num)

int screen(int poker[],int correct[],int num) {
	for (int i = 0; i < num; i++) {
		int k;
		for (k=0; k<num; k++) {
			if (i == correct[k]) {
				cout << poker[i];
				break;
			}
		}
		if (k > num-1)
			cout << b;
		if ((i + 1) % 4 == 0)
			cout << endl;
	}
	return 0;
}//这个是在写4*4的那个
			
int judge(int x, int y, int time) {
	cout << "请输入第" << time % 2 + 1 << "个点的坐标（用空格隔开）";
	cin >> x >> y;
	while(x>4||y>4){
		cout << "输入的数据有误，请重新输入点的坐标";
		cin >> x >> y;
	}
	n[time % 2] = x-4*y+15;
	correct[time] = n[time % 2];
	return 0;
}

int main() {
	
	srand((unsigned)time(0));
	for (int k = 0; k < num; k++) {
		poker[k] = rand() % 16 + 1;
		for (int i=0; i < num; i++) {
			if ((k != i)&(poker[k] == poker[i])) {
				poker[k] = rand() % 16 + 1;
				i = -1;
			}
		}
	}
	for (int k = 0; k < num; k++) {
		if (poker[k] > num/2)
			poker[k] -= num/2;
	}//生成随机的2对1~8的扑克排序
	
	screen(poker,correct,num);
	Sleep(2000);
	system("cls");
	
	for (int i=0; i < num; i++) {
		correct[i] =-1;
	}
	int x=0;
	int y=0;//x,y是坐标
	for (int time = 0;time<num;time++) {//time为猜的次数
		screen(poker,correct,num);
		judge(x,y,time);
		if (time % 2 == 1) {
			if (poker[n[1]] != poker[n[0]]) {
				system("cls");
				screen(poker, correct, num);
				Sleep(500);
				correct[time] = correct[time-1] = -1;
				time -= 2;
			}
		}
		system("cls");
	}
	cout << "You win!";

	system("pause");
	return 0;
}

