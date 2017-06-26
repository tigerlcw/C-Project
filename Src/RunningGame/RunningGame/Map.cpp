#include "Map.h"
#include<iostream>
using namespace std;
#include <stdlib.h>
#include <memory.h>
#include <assert.h>

Map *NewMap()	// Map ��ü ����
{
	Map *map = (Map *)malloc(sizeof(Map));
	MapMap(map);
	return map;
}

void MapMap(Map *map)	// Map ��ü �ʱ�ȭ
{
	memset(map->base, 0, sizeof(map->base));
	for (int x = 0; x < WIDTH + 1; x++)
	{
		map->base[0][x] = WALL;
		map->base[HEIGHT][x] = WALL;
	}
	map->base[YPOS][XPOS] = CHARACTER;
	map->pt = { XPOS,YPOS };
}

void ReleaseMap(Map *map)	// Map ��ü ����
{
	free(map);
}

void DrawMap(Map *map) // Map �׸���
{
	for (int y = 0; y < HEIGHT + 1; y++)
	{
		for (int x = 0; x < WIDTH + 1; x++)
		{
			if (x == 0)
			{
				cout << "\t";
			}
			switch (map->base[y][x])
			{
			case HOLE:
			case EMPTY:
				cout << "  ";
				break;
			case WALL:
				cout << "��";
				break;
			case CHARACTER:
				cout << "��";
				break;
			case HURDLE:
				cout << "��";
				break;
			case GOLD:
				cout << "��";
				break;
			default:
				assert(false);
				break;				
			}
		}
		cout << "\n";
	}
}

void MoveMap(Map *map)	// 1 Tick �̵�
{
	map->base[HEIGHT - 1][0] = EMPTY;
	for (int x = 0; x < WIDTH; x++)
	{
		int val = map->base[HEIGHT - 1][x+1];
		if (val == GOLD || val == HURDLE)
		{
			map->base[HEIGHT - 1][x] = map->base[HEIGHT - 1][x + 1];
			map->base[HEIGHT - 1][x + 1] = EMPTY;
		}
		map->base[HEIGHT][x] = map->base[HEIGHT][x + 1];
		map->base[HEIGHT][x + 1] = WALL;
	}
}

bool Collision(Map *map) // �浹
{
	bool flag = (map->base[YPOS][XPOS] == CHARACTER && map->base[YPOS][XPOS + 1] == HURDLE);
	flag = flag || (map->base[YPOS][XPOS] == CHARACTER && map->base[YPOS + 1][XPOS + 1] == HOLE);
	return flag;
}

void JumpCharacter(Map *map)	// ĳ���� ����
{
	Point pt = map->pt;
	map->base[pt.Y][pt.X] = EMPTY;
	map->base[pt.Y - 1][pt.X] = CHARACTER;
	map->pt.Y--;
}

void ReposCharacter(Map *map)	// ĳ���� ����
{
	Point pt = map->pt;
	map->base[pt.Y][pt.X] = EMPTY;
	map->base[pt.Y + 1][pt.X] = CHARACTER;
	map->pt.Y++;
}

void CreateHurdle(Map *map)	// ��ֹ� ����
{
	map->base[HEIGHT-1][WIDTH] = HURDLE;
}

void CreatePoint(Map *map)	// ����Ʈ ����
{
	map->base[HEIGHT-1][WIDTH] = GOLD;
}

void CreateHole(Map *map)
{
	map->base[HEIGHT][WIDTH] = HOLE;
}
