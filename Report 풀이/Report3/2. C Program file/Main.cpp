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
	Tree** Table = createTable(27, 30); // 27�� RTB�� ���� 30������ ����� �¼��� ä�����´�.
	char input;

	
	start(); // start��� �Լ� �̸��� ���� �赿���� ����ߡ��� ����ϸ鼭 ���α׷��� �����Ѵ�.

	while (1) {
		input = show_main();
		if (input == '1') menu1_reservation(Table);
		else if (input == '2') menu2_cancle(Table);
		else break;
	}
	
	close();
	
	return 0;
}