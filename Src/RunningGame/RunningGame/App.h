#pragma once
#include "Map.h"
#include "Interactoin.h"

#define GOLD_RATE 0.02f	// 포인트가 나올 확률 2%
#define HURDLE_RATE 0.03f + GOLD_RATE	// 장애물이 나올 확률 3%
#define HOLE_RATE 0.025f + HURDLE_RATE	// 구멍이 나올 확률 2.5%

typedef struct _App App;
struct _App
{
	Map *map;
	unsigned int stage;
	unsigned int playTime;
	unsigned int score;
	bool bflag;
	bool jumpped;
	bool up;
	bool down;
};

App *NewApp(); // App 개체 생성
void AppApp(App *app);	// App 개체 초기화
void AppRun(App *app);	// App 실행
void ReleaseApp(App *app);	// App 해제

int SelectMenu();	// 메뉴 선택
void StartGame(App *app); // 게임 시작
void SelectStage(App *app);	// 단계 선택
void PollingInput(App *app);	// 사용자 입력
bool Update(App *app);	// 프레임 업데이트
void Draw(App *app);	// 맵 드로우

void PlayMusic(int stage);
float GetProbability();	// 확률 함수


