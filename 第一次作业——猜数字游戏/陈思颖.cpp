#include <iostream>
using namespace std;
#include<cstdlib>
#include<ctime>
#include<dos.h>


int main()
{
	char ch='n';
	while (ch != 'N') {
			int  min, max;//min��Сֵmax���ֵ
			int i, r;//r�����
			int num, peop;//num��ǰ��Ϸ�����ţ�peop��Ϸ��������
			cout << "��������Ϸ������";
			cin >> peop;
			cout << "���������Ͻ磬�ÿո������";
			cin >> min >> max;

			srand((unsigned)time(0));
			for (i = 0; i < 1; i++) {
				r = (rand() % (max - min)) + min + 1;
				cout << r << " ";
			}

			system("cls");

			int guess;//guess�µ�����
			num = 0;
			guess = r - 1;
			while (guess != r) {
				num++;
				cout << "��" << num << "����������һ��" << min << "~" << max << "������";
				cin >> guess;
				while ((guess > max) || (guess < min)){
					cout << "����������������������һ��" << min << "~" << max << "������";
					cin >> guess;
				}
				if (guess < r)
				{
					cout << "С��";
					min = guess;
					num = num%peop;
				}
				if (guess > r)
				{
					cout << "����";
					max = guess;
					num = num%peop;
				}
			}
			if (guess == r)
				cout << "��" << num << "����boom!";

		cout << "�����Ƿ����¿�ʼ��Y(es)orN(o)";
		cin >> ch;
	}

	system("pause");

	return 0;
}
