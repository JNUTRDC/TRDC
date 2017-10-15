#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

const int num = 16;
int puke[num] = { 0 };//a[num]为16个要猜的随机值
int correct[num] = { 0 };//correct[num]为玩家已经猜中的扑克的号码
const char b = '*';

int screen(int puke[num],int correct[num]) {
	for (int i = 0; i < num; i++) {
		if (i != correct[num])
			cout << b;
		else
			cout << puke[num];
		if ((i + 1) % 4 == 0)
			cout << endl;
	}
	return 0;
}//这个是在写4*4的那个
			
int main() {
	
	srand((unsigned)time(0));
	for (int k = 0; k < 16; k++) {
		puke[k] = rand() % 16 + 1;
		for (int i=0; i < 16; i++) {
			if (puke[k] == puke[i])
				puke[k] = rand() % 16 + 1;
		}
		if (puke[k] > 8)
			puke[k] -= 8;
	}//生成16个随机数

	int screen(int puke[num], int correct[num]);//不知道为什么这个地方看不到4*4的那个东西
	cout << "请输入第" << n << "个点的坐标(用空格隔开）";//然后后面的就没写了，实在是很抱歉（哭),下周会尽快补上的

	system("pause");
	return 0;
}