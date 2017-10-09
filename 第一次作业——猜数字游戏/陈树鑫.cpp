#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int player_num, result_num, u_lim, l_lim, i, n;
char Y_N;
void game();
void game_big();
void game_small();
void game_boom();
int rand();
void srand();

int main()
{

	i = 1;
	Y_N = 'Y';
	srand((unsigned)time(NULL));
	do
	{
		cout << "Enter the number of players: ";
		cin >> player_num;
		cout << "Please enter upper and lower limit\n";
		cout << "Upper limit: ";
		cin >> u_lim;
		cout << "Lower limit: ";
		cin >> l_lim;
		result_num = rand() % (l_lim - u_lim);
		cout << "The number that is wanted is: " << result_num << endl;
		Sleep(2000);
		system("cls");
		cout << "Player " << i << ",pleaese enter a number that is between " << l_lim << " and " << u_lim << endl;
		i++;
		cin >> n;
		do
		{
			if (i <= player_num)
			{
				game();
			}
			else
			{
				i = 1;
				if (i <= player_num)
				{
					game();
				}
			}
		} while (n != result_num);
	} while (Y_N = 'Y');



	cin.get();
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	return 0;
}
void game()
{
	do
	{
		if (n != result_num)
		{
			if (n > result_num&&n < u_lim)
			{
				game_big();

			}
			else
			{
				if (n<result_num&&n>l_lim)
				{
					game_small();
				}
				else
				{
					cout << "Erorr!!!!Please enter a number in the right range!\n";
					cin >> n;

				}
			}
		}
		if (n == result_num)
		{
			game_boom();
		}
	} while (n != result_num&&i < player_num);
}
void game_big()
{
	cout << "Too big!\n";
	u_lim = n;
	cout << "Player " << i << ",pleaese enter a number that is between " << l_lim << " and " << u_lim << endl;
	i++;
	cin >> n;
}
void game_small()
{
	cout << "Too small!\n";
	l_lim = n;
	cout << "Player " << i << ",pleaese enter a number that is between " << l_lim << " and " << u_lim << endl;
	i++;
	cin >> n;
}
void game_boom()
{

	i = i - 1;
	cout << "Player" << i << " boom!!!!!" << endl;
	cout << "Do you want to player again? Y(es) or N(o)?" << endl;
	cin >> Y_N;
	system("cls");
}