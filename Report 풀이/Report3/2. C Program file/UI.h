#pragma once
#pragma once

#define WIDTH 120

/*******************************************************************************
								UI 함수
*******************************************************************************/

void start();														// 시작 화면을 출력하면서 영화 예약 프로그램을 시작한다.
void close();														// 종료 화면을 출력하면서 영화 예약 프로그램을 종료한다.

void menu1_reservation(Tree** Table);								// 영화 예약 UI
void menu2_cancle(Tree** Table);									// 영화 취소 UI

char show_main();													// 홈 화면을 보여준다.

int show_timeTable();												// 현재 상영 영화와 상영 시간을 보여준다.
char* show_seat(Tree** Table, int movie_num);						// 선택한 영화의 현재 예약 상황을 보여준다.
char show_confirm(Tree** Table, int movie_num, const char* seat);	// 선택한 영화의 좌석을 예약 성공 했음을 보여준다.

void showSeatBox();													// SeatBox를 보여준다.
void fillSeatBox(Tree* RBT, Node* node);							// SeatBox에 현재 예약 내역을 채운다.

int* presentCur();													// 현재 커서의 위치를 받아온다.
void gotoxy(int x, int y);											// 커서를 (x, y)로 이동시킨다.
void gotox(int x);													// 커서를 현재 커서가 위치한 줄의 x로 이동시킨다.

void printHere(const char txt[], int x, int y);						// (x, y)에 문자를 출력한다.
void alignCenter(const char txt[]);									// 문자를 가운데 정렬하여 출력한다.
void textColor(const char txt[], int color);						// 글자색을 변경하여 출력한다.

void printfTime(const char txt[], int time);						// 문자열 출력후 일정시간 지연시킨다.
void printfS(const char txt[]);										// 문자열 출력후 33ms 지연시킨다.
void printfL(const char txt[]);										// 문자열 출력후 44ms 지연시킨다.
