#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

const int num = 16;
int puke[num] = { 0 };//a[num]Ϊ16��Ҫ�µ����ֵ
int correct[num] = { 0 };//correct[num]Ϊ����Ѿ����е��˿˵ĺ���
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
}//�������д4*4���Ǹ�
			
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
	}//����16�������

	int screen(int puke[num], int correct[num]);//��֪��Ϊʲô����ط�������4*4���Ǹ�����
	cout << "�������" << n << "���������(�ÿո������";//Ȼ�����ľ�ûд�ˣ�ʵ���Ǻܱ�Ǹ����),���ܻᾡ�첹�ϵ�

	system("pause");
	return 0;
}