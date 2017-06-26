#pragma once
#pragma warning(disable:4996)
#define WIDTH 25
#define HEIGHT 10
#define XPOS 5
#define YPOS HEIGHT - 1

enum _Block
{
	EMPTY, HOLE, WALL, CHARACTER, HURDLE, GOLD
	// "  ", "��", "��", "��" ,"��"
};

typedef struct _Point
{
	int X;
	int Y;
}Point;

typedef struct _Map
{
	int base[HEIGHT + 2][WIDTH + 1];
	Point pt;
}Map;

Map *NewMap();	// Map ��ü ����
void MapMap(Map *map);	// Map ��ü �ʱ�ȭ
void ReleaseMap(Map *map);	// Map ��ü ����

void DrawMap(Map *map); // Map �׸���
void MoveMap(Map *map);	// 1 Tick �̵�
bool Collision(Map *map); // �浹

void JumpCharacter(Map *map);	// ĳ���� ����
void ReposCharacter(Map *map);	// ĳ���� ����
void CreateHurdle(Map *map);	// ��ֹ� ����
void CreatePoint(Map *map);	// ����Ʈ ����
void CreateHole(Map *map);	// ���� ����


