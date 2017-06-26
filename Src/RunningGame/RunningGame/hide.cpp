#include<iostream>
#include<Windows.h>
#include "hide.h"
using namespace std;
int NOMU::MapInput(int n) {
	try {
		if (n >= 1 && n <= 5)
			return n;
		else
			throw n;
	}
	catch (int n) {
		return 666;
		// 1~5가 아닌 다른 문자가 숫자 입력 시 게임오버 출력
		//return n; //1~5가 아닌경우 처리할 부분
	}
}

//class 아무거나 생성하셈 사용하고