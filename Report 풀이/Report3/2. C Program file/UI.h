#pragma once
#pragma once

#define WIDTH 120

/*******************************************************************************
								UI �Լ�
*******************************************************************************/

void start();														// ���� ȭ���� ����ϸ鼭 ��ȭ ���� ���α׷��� �����Ѵ�.
void close();														// ���� ȭ���� ����ϸ鼭 ��ȭ ���� ���α׷��� �����Ѵ�.

void menu1_reservation(Tree** Table);								// ��ȭ ���� UI
void menu2_cancle(Tree** Table);									// ��ȭ ��� UI

char show_main();													// Ȩ ȭ���� �����ش�.

int show_timeTable();												// ���� �� ��ȭ�� �� �ð��� �����ش�.
char* show_seat(Tree** Table, int movie_num);						// ������ ��ȭ�� ���� ���� ��Ȳ�� �����ش�.
char show_confirm(Tree** Table, int movie_num, const char* seat);	// ������ ��ȭ�� �¼��� ���� ���� ������ �����ش�.

void showSeatBox();													// SeatBox�� �����ش�.
void fillSeatBox(Tree* RBT, Node* node);							// SeatBox�� ���� ���� ������ ä���.

int* presentCur();													// ���� Ŀ���� ��ġ�� �޾ƿ´�.
void gotoxy(int x, int y);											// Ŀ���� (x, y)�� �̵���Ų��.
void gotox(int x);													// Ŀ���� ���� Ŀ���� ��ġ�� ���� x�� �̵���Ų��.

void printHere(const char txt[], int x, int y);						// (x, y)�� ���ڸ� ����Ѵ�.
void alignCenter(const char txt[]);									// ���ڸ� ��� �����Ͽ� ����Ѵ�.
void textColor(const char txt[], int color);						// ���ڻ��� �����Ͽ� ����Ѵ�.

void printfTime(const char txt[], int time);						// ���ڿ� ����� �����ð� ������Ų��.
void printfS(const char txt[]);										// ���ڿ� ����� 33ms ������Ų��.
void printfL(const char txt[]);										// ���ڿ� ����� 44ms ������Ų��.
