#pragma once

#define spaseX 30
#define spaseY 60

const int x = spaseX + 2;
const int y = spaseY + 2;

class Life
{
	int spase[x][y];

	int rule(int i, int j);
	void printSpase();
	void generateLife();

public:
	Life();
	~Life();
	void runLife();

};

