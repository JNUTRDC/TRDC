#include<iostream>//лл���ҿ�����λ����
#include<ctime>
#include<cstdlib>
#include<Windows.h>
using namespace std;

const int num = 16;
int poker[num] = { 0 };//poker[num]Ϊ16��Ҫ�µ����ֵ
int correct[num] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };//correct[num]Ϊ����Ѿ����е��˿˵ĺ���
const char b = '*';
int n[2] = { 0 };//nΪ�µ����ֵ����(����poker[num]�е��Ǹ�num)

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
}//�������д4*4���Ǹ�
			
int judge(int x, int y, int time) {
	cout << "�������" << time % 2 + 1 << "��������꣨�ÿո������";
	cin >> x >> y;
	while(x>4||y>4){
		cout << "�����������������������������";
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
	}//���������2��1~8���˿�����
	
	screen(poker,correct,num);
	Sleep(2000);
	system("cls");
	
	for (int i=0; i < num; i++) {
		correct[i] =-1;
	}
	int x=0;
	int y=0;//x,y������
	for (int time = 0;time<num;time++) {//timeΪ�µĴ���
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

