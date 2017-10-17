#include<iostream>//谢谢帮我看的这位大佬，我在函数的调用那有问题，求帮助
#include<ctime>
#include<cstdlib>
using namespace std;

const int num = 16;
int puke[num] = { 0 };//puke[num]为16个要猜的随机值
int correct[num] = { 0 };//correct[num]为玩家已经猜中的扑克的号码
const char b = '*';
int n[2] = { 0 };//n为猜的数字的序号(就是puke[num]中的那个num)

int screen(int puke[num],int correct[num]) {
	for (int i = 0; i < num; i++) {
		if (i != correct[num])
			cout << b;
		else
			cout << puke[num];
		if ((i + 1) % 4 == 0)
			cout << endl;
		return 0;
	}
}//这个是在写4*4的那个
			
int main() {
	
	srand((unsigned)time(0));
	for (int k = 0; k < 16; k++) {
		puke[k] = rand() % 16 + 1;
		for (int i=0; i < 16; i++) {
			if (puke[k] == puke[i]) {
				puke[k] = rand() % 16 + 1;
				i = -1;
			}
		}
	}
	for (int k = 0; k < 16; k++) {
		if (puke[k] > 8)
			puke[k] -= 8;
	}//生成随机的2对1~8的扑克排序
	
	screen(puke[num],correct[num]);//不知道为什么这里有问题
	system("cls");
	
	correct[num] = { -1 };
	int x;
	int y;//x,y是坐标
	for (int time = 0;time<16;time++) {//time为猜的次数
		screen(puke[num],correct[num]);
		judge(x,y,time);
		if (time % 2 == 1) {
			if (puke[n[1]] != puke[n[0]]) {
				correct[time-1] = correct[time - 2] = -1;
				time -= 2;
			}
		}
	}
	cout << "You win!";

	system("pause");
	return 0;
}

int judge(int x,int y,int time) {
	cout << "请输入第"<<time%2+1<<"个点的坐标（用空格隔开）";
	cin >> x >> y;
	n[time%2] = (y - 1) * 4 + x;
	correct[time] = n[time%2];
	
}