#pragma once
#include "Map.h"
#include "Interactoin.h"

#define GOLD_RATE 0.02f	// ����Ʈ�� ���� Ȯ�� 2%
#define HURDLE_RATE 0.03f + GOLD_RATE	// ��ֹ��� ���� Ȯ�� 3%
#define HOLE_RATE 0.025f + HURDLE_RATE	// ������ ���� Ȯ�� 2.5%

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

App *NewApp(); // App ��ü ����
void AppApp(App *app);	// App ��ü �ʱ�ȭ
void AppRun(App *app);	// App ����
void ReleaseApp(App *app);	// App ����

int SelectMenu();	// �޴� ����
void StartGame(App *app); // ���� ����
void SelectStage(App *app);	// �ܰ� ����
void PollingInput(App *app);	// ����� �Է�
bool Update(App *app);	// ������ ������Ʈ
void Draw(App *app);	// �� ��ο�

void PlayMusic(int stage);
float GetProbability();	// Ȯ�� �Լ�


