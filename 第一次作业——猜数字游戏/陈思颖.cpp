#include <iostream>
using namespace std;
#include<cstdlib>
#include<ctime>
#include<dos.h>


int main()
{
	char ch='n';
	while (ch != 'N') {
			int  min, max;//min最小值max最大值
			int i, r;//r随机数
			int num, peop;//num当前游戏这的序号，peop游戏参与人数
			cout << "请输入游戏人数：";
			cin >> peop;
			cout << "请输入下上界，用空格隔开：";
			cin >> min >> max;

			srand((unsigned)time(0));
			for (i = 0; i < 1; i++) {
				r = (rand() % (max - min)) + min + 1;
				cout << r << " ";
			}

			system("cls");

			int guess;//guess猜的数字
			num = 0;
			guess = r - 1;
			while (guess != r) {
				num++;
				cout << "第" << num << "个人请输入一个" << min << "~" << max << "的数字";
				cin >> guess;
				while ((guess > max) || (guess < min)){
					cout << "输入数据有误，请重新输入一个" << min << "~" << max << "的数字";
					cin >> guess;
				}
				if (guess < r)
				{
					cout << "小了";
					min = guess;
					num = num%peop;
				}
				if (guess > r)
				{
					cout << "大了";
					max = guess;
					num = num%peop;
				}
			}
			if (guess == r)
				cout << "第" << num << "个人boom!";

		cout << "请问是否重新开始？Y(es)orN(o)";
		cin >> ch;
	}

	system("pause");

	return 0;
}
