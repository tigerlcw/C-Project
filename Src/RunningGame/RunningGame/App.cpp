#include "App.h"
#include "hide.h"
#include<iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#pragma comment(lib, "winmm.lib")

class A {
	//class A 생성
public:
	virtual string team_own()
	{
		return "팀명 - EDD-202";
	}
};
class B:public A {
public:
	string team_own()
	{
		return "역할 : 이찬우 - 메인 개발 / 장민 - 서브 개발 / 홍성은 - 보고서 작성 및 발표 / 서준호 - 사기증진";
	
	}
};


App *NewApp()
{
	App *app = (App *)malloc(sizeof(App));
	AppApp(app);
	return app;
}

void AppApp(App *app)
{
	srand(time(NULL));
	app->map = NewMap();
	app->playTime = 0;
	app->score = 0;
	app->bflag = false;
	app->jumpped = false;
	app->up = false;
	app->down = false;
	app->stage = 1;
}

void AppRun(App *app)
{
	int key = 0;
	while ((key = SelectMenu()) != ESC)
	{
		
		switch (key)
		{
		case F1: 
			StartGame(app);
			break;
		case F2:
			SelectStage(app);
			break;
		default:
			cout<<"잘 못 눌렀습니다\n";
			break;
		}
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
		cout << "\t\t\t우흥 ~ 사망\n" << endl;
cout << "\t\t=+ +%              %=%." << endl;
cout << "\t\t *:   @           .%  *:" << endl;
cout << "\t\t#.    @          @ ==+=" << endl;
cout << "\t\t#.*++  @        @ #=:#@" << endl;
cout << "\t\t# @=*@=%*+++++++###=%#+*" << endl;
cout << "\t\t*@:                   #@:" << endl;
cout << "\t\t*:   =::=.     .=::+   %" << endl;
cout << "\t\t*:  # %# *+++++# #@ * :#" << endl;
cout << "\t\t*:  == :.*     == :*  :*" << endl;
cout << "\t\t@     ::. .      :.   +=" << endl;
cout << "\t\t@      :+#=++*=.      @" << endl;
cout << "\t\t@   =%@*======+#@@@+ .%" << endl;
cout << "\t\t.%    =+*+::=+++:    %:" << endl;
cout << "\t\t.@*.     .        .@." << endl;
cout << "\t\t.* =+++#=++++==+*++:%" << endl;
cout << "\t\t.#     .%    @  .:  %" << endl;
cout << "\t\t=*      ++   *=  +# .%" << endl;
cout << "\t\t%.  *=   @    @   ** @" << endl;
cout << "\t\t@   *=   +=   :%   :@ @" << endl;
cout << "\t\t@   .#   =+     @    @*:" << endl;
cout << "\t\t:#   .#   +=      @   @ @" << endl;
cout << "\t\t*=   :#   %.       @  :%.#" << endl;
cout << "\t\t*:   +=   @        =*  .%%" << endl;
cout << "\t\t.@   %   %.         +#  =%." << endl;
cout << "\t\t:%     #=            %+ *." << endl;
cout << "\t\t.** :%:               =@" << endl;
cout << "\t\t@#                :%" << endl;
cout << "\t\t#*            =**@" << endl;
cout << "\t\t@+**+++++**=.  %" << endl;
cout << "\t\t%              @" << endl;
cout << "\t\t%.             #" << endl;
cout << "\t\t#@*+           *@**" << endl;
cout << "\t\t#* % +#        :#.%  %" << endl;
cout << "\t\t*   %.  :          @"<<endl;
cout << "\t\t    *"<<endl;
		getKey();
	}
}

void ReleaseApp(App *app)
{
	PlaySound(NULL, 0, 0);
	ReleaseMap(app->map);
	free(app);
}

void text(A*z)
{
	cout << z->team_own().data() << endl;
}


int SelectMenu()
{
	system("title 쿠키런을 만들어보고 싶어요.");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	PlaySound(TEXT("sounds/maintitle.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	system("cls");

	A a;
	B b;

	text(&a);
	text(&b);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << "\t\t┌──────────────┐\n";
	cout << "\t\t│  ♥ 10점을 모으세요~! ♥   │\n";
	cout << "\t\t│  ♥ 제한시간 : 3분 ♥      │\n";
	cout << "\t\t└──────────────┘\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << "\t################################################\n";
	cout << "\t\t　　　 ※      조작키     ※\n";
	cout << "\t\t　　　　# 점프 : SPACE    #\n";
	cout << "\t\t　　　　#  ♪ : 캐릭터    #\n";
	cout << "\t\t　　　　#  ▲ : 장애물    #\n";
	cout << "\t\t　　　　#  ★ : 점  수    #\n";
	cout << "\t################################################\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	cout << "\t################################################\n";
	cout << "\t\t　　　　▷　[ F1]. 게임시작 \n";
	cout << "\t\t　　　　▶　[ F2]. 단계선택 \n";
	cout << "\t\t　　　　▣　[ESC]. 게임종료 \n";
	cout << "\t################################################\n";

	return getKey();
}

void StartGame(App *app)
{
	PlayMusic(app->stage);
	app->bflag = false;
	app->score = 0;
	clock_t et = 0, st = 0;
	et = clock();

	while (!app->bflag)
	{
		PollingInput(app);
		if (Update(app))
		{
			break;
		}
		Draw(app);
		_sleep(100 - app->stage * 10);
		app->playTime = clock() - et;
	}

	ReleaseMap(app->map);
	app->map = NewMap();
}

void SelectStage(App *app)
{
	NOMU map;
	//이쪽 부분에서 예외처리 정해진 키 말고 다른거 입력 할 경우 hide.h 발동 
	cout << "\t\t플레이 할 스테이지 (1 ~ 5): ";
	int num = 0;
	cin >> num;
	num = map.MapInput(num);
	/*if (num < 0) num = 0;
	if (num > 6) num = 6;*/
	if (num != 666) {
		int temp = app->stage;
		app->stage = num;
		PlayMusic(app->stage);
		StartGame(app);
		app->stage = temp;
	}
}

void PollingInput(App *app)
{
	int ypos = app->map->pt.Y;
	if (kbhit())
	{
		int key = getKey();
		if (key == SPACE && !app->jumpped && ypos == HEIGHT - 1)
		{
			app->jumpped = true;
		}
		else if (key == ESC)
		{
			PlaySound(NULL, 0, 0);
			app->bflag = true;
		}
	}
	if (app->jumpped && ypos > HEIGHT - 3)
	{
		JumpCharacter(app->map);
	}
	if (ypos == HEIGHT - 3)
	{
		app->jumpped = false;
	}
	if (!app->jumpped && ypos < HEIGHT - 1)
	{
		ReposCharacter(app->map);
	}
}

bool Update(App *app)
{
	float probability = GetProbability();
	if (probability <= GOLD_RATE)
	{
		CreatePoint(app->map);
	}
	else if (probability <= HURDLE_RATE)
	{
		CreateHurdle(app->map);
	}
	else if (probability <= HOLE_RATE)
	{
		CreateHole(app->map);
	}

	bool flag = Collision(app->map);
	if ( app->map->base[YPOS][XPOS] == CHARACTER && app->map->base[YPOS][XPOS + 1] == GOLD)
	{
		app->score++;
		app->map->base[YPOS][XPOS + 1] = EMPTY;
	}
	MoveMap(app->map);
	if (app->score >= 10)
	{
		app->stage++;
		app->score = 0;
		PlaySound(NULL, 0, 0);
		PlayMusic(app->stage);
	}
	else if (app->playTime / 1000 >= 180 || flag)
	{
		PlaySound(TEXT("sounds/gameend.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		app->bflag = true;
	}

	return flag;
}

void Draw(App *app)
{
	system("cls");
	DrawMap(app->map);
	cout << "\t";
	cout << "stage : "<<app->stage << "\t"<<"point : " << app->score<<endl;
	cout << "\t";
	cout << "재생중 : ";
	switch (app->stage)
	{
	case 1:
		cout << "[SPYAIR - SOME LIKE IT HOT]"; break;
	case 2:
		cout << "[텐시러브 - 케잌크노 하우스]"; break;
	case 3:
		cout << "[SPYAIR - サクラミツツキ]"; break;
	case 4:
		cout << "[트와이스 - CHEER UP]"; break;
	case 5:
		cout << "[여자친구 - 시간을 달려서]"; break;
	default:
	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
		cout << "\t\t\t\n당신은 !!! 노오오오오오잼 게임을 끝까지\n";
		cout << "\t\t\t하신 참기의 [달인]\n";
		break;
	}
	cout << "play time : "<< app->playTime / 1000;
}

void PlayMusic(int stage)
{
	switch (stage)
	{
	case 1:
		PlaySound(TEXT("sounds/stage1.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
		break;
	case 2:
		PlaySound(TEXT("sounds/stage2.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
		break;
	case 3:
		PlaySound(TEXT("sounds/stage3.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
		break;
	case 4:
		PlaySound(TEXT("sounds/stage4.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
		break;
	case 5:
		PlaySound(TEXT("sounds/stage5.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
		break;
	default:
		return;
	}
}

float GetProbability()
{
	int r = rand();
	int val = r > 0 ? r : 1;
	float fval = (float)val / (RAND_MAX);

	return fval;
}