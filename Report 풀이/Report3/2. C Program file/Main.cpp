#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "RedBlackTree.h"
#include "Utility.h"
#include "UI.h"

#pragma comment(lib,"winmm.lib")
#pragma warning(disable:4996)

int main() {
	Tree** Table = createTable(27, 30); // 27개 RTB에 각각 30개씩의 예약된 좌석을 채워놓는다.
	char input;

	
	start(); // start라는 함수 이름과 같이 김동률의 『출발』을 재생하면서 프로그램을 시작한다.

	while (1) {
		input = show_main();
		if (input == '1') menu1_reservation(Table);
		else if (input == '2') menu2_cancle(Table);
		else break;
	}
	
	close();
	
	return 0;
}