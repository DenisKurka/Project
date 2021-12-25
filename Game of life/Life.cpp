#include "Life.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <windows.h>

using namespace std;

Life::Life() {
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			spase[i][j] = 0;
}

Life::~Life() {

}

int Life::rule(int i, int j)
{
	int lifeCount = 0;
	for (int k = i - 1; k < i + 2; k++)
		for (int n = j - 1; n < j + 2; n++)
			lifeCount = lifeCount + spase[k][n];
	lifeCount = lifeCount - spase[i][j];

	if (lifeCount == 3 && spase[i][j] == 0)
		spase[i][j] = 1;
	if ((lifeCount < 2 || lifeCount > 3) && spase[i][j] == 1)
		spase[i][j] = 0;

	return 0;
}

void Life::printSpase()
{
	for (int i = 1; i < x - 1; i++) {
		for (int j = 1; j < y - 1; j++)
			if (spase[i][j] == 1)
				cout << "#";
			else
				cout << " ";
		cout << endl;
	}
}

void Life::generateLife()
{
	srand((unsigned)time(NULL));

	for (int i = 1; i < x - 1; i++)
		for (int j = 1; j < y - 1; j++)
			spase[i][j] = rand() % 2;
}

void Life::runLife()
{
	generateLife();
	printSpase();

	Sleep(1000);
	system("cls");

	while (1) {
		for (int i = 1; i < x - 1; i++)
			for (int j = 1; j < y - 1; j++)
				rule(i, j);
		printSpase();

		Sleep(30);
		system("cls");
	}
}
	