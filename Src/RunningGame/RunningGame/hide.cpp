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
		// 1~5�� �ƴ� �ٸ� ���ڰ� ���� �Է� �� ���ӿ��� ���
		//return n; //1~5�� �ƴѰ�� ó���� �κ�
	}
}

//class �ƹ��ų� �����ϼ� ����ϰ�