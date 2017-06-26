#pragma once
#pragma warning(disable:4996)
#define WIDTH 25
#define HEIGHT 10
#define XPOS 5
#define YPOS HEIGHT - 1

enum _Block
{
	EMPTY, HOLE, WALL, CHARACTER, HURDLE, GOLD
	// "  ", "■", "♪", "▲" ,"★"
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

Map *NewMap();	// Map 개체 생성
void MapMap(Map *map);	// Map 개체 초기화
void ReleaseMap(Map *map);	// Map 개체 해제

void DrawMap(Map *map); // Map 그리기
void MoveMap(Map *map);	// 1 Tick 이동
bool Collision(Map *map); // 충돌

void JumpCharacter(Map *map);	// 캐릭터 점프
void ReposCharacter(Map *map);	// 캐릭터 원점
void CreateHurdle(Map *map);	// 장애물 생성
void CreatePoint(Map *map);	// 포인트 생성
void CreateHole(Map *map);	// 구멍 생성


