#include<iostream>//лл���ҿ�����λ���У����ں����ĵ����������⣬�����
#include<ctime>
#include<cstdlib>
using namespace std;

const int num = 16;
int puke[num] = { 0 };//puke[num]Ϊ16��Ҫ�µ����ֵ
int correct[num] = { 0 };//correct[num]Ϊ����Ѿ����е��˿˵ĺ���
const char b = '*';
int n[2] = { 0 };//nΪ�µ����ֵ����(����puke[num]�е��Ǹ�num)

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
}//�������д4*4���Ǹ�
			
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
	}//���������2��1~8���˿�����
	
	screen(puke[num],correct[num]);//��֪��Ϊʲô����������
	system("cls");
	
	correct[num] = { -1 };
	int x;
	int y;//x,y������
	for (int time = 0;time<16;time++) {//timeΪ�µĴ���
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
	cout << "�������"<<time%2+1<<"��������꣨�ÿո������";
	cin >> x >> y;
	n[time%2] = (y - 1) * 4 + x;
	correct[time] = n[time%2];
	
}