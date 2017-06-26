#include "Interactoin.h"

int getKey()
{
	int key = NOT;
	key = getch();
	if (key == 32)
	{
		return SPACE;
	}
	else if (key == 27)
	{
		return ESC;
	}
	else if (key == 0)
	{
		key = getch();
		switch (key)
		{
		case 59:return F1;
		case 60:return F2;
		case 61:return F3;
		default:return NOT;
		}
	}
	return NOT;
}