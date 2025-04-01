#define _CRT_SECURE_NO_WARNINGS
#include"µÝ¹é·ÖÖÎ.h"
void move(char pos1, char pos2)
{
	printf("%c->%c\n", pos1, pos2);
}

void hanoi(int n, char pos1, char pos2, char pos3)
{
	if (n == 1)
	{
		move(pos1, pos3);
	}
	else
	{
		hanoi(n - 1, pos1, pos3, pos2);
		move(pos1, pos3);
		hanoi(n - 1, pos2, pos1, pos3);
	}
}