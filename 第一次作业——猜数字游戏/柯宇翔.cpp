#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	int min, max;
	srand((unsigned)time(NULL));
	int number = rand() % 100 + 1;
	int count = 0;
	int a = 0;
	int b = 1;
	int people;
	int repeat;
	do {
		system("cls");
		printf("锟斤拷锟斤拷锟斤拷锟斤拷锟睫猴拷锟斤拷锟斤拷");
		scanf("%d %d", &min, &max);
		printf("锟斤拷锟斤拷锟斤拷锟斤拷戏锟斤拷锟斤拷锟斤拷");
		scanf("%d", &people);
		system("cls");
		printf("锟斤拷锟窖撅拷锟斤拷锟斤拷锟揭伙拷锟�%d锟斤拷%d之锟斤拷锟斤拷锟斤拷锟�", min, max);
		do {
			printf("锟斤拷锟斤拷锟斤拷%d锟斤拷%d之锟斤拷锟斤拷锟斤拷", min, max);
			scanf("%d", &a);
			if (a > number) {
				printf("锟斤拷%d锟斤拷锟剿猜碉拷锟斤拷锟斤拷锟剿★拷", b);
				max = a;
				b++;
				if(b > people) {
					b = 1;
				}
			}
			else if ( a < number ) {
				printf("锟斤拷%d锟斤拷锟剿猜碉拷锟斤拷小锟剿★拷", b);
				min = a;
				b++;
				if (b > people) {
					b = 1;
				}
			}
			count++;
		} while (a != number);

		printf("BOOM!锟斤拷%d锟剿猜讹拷锟剿ｏ拷锟斤拷锟斤拷锟斤拷%d锟轿就猜碉拷锟剿答案★拷\n", b, count);
		printf("锟角凤拷锟斤拷锟斤拷锟较凤拷锟�1(yes) or 2(no)");
		scanf("%d,&repeat");
    } while (repeat != 2);

	return 0;
} 
