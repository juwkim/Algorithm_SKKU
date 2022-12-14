#pragma once

void swap(int* first_num, int* second_num);	// 각 주소에 저장된 정수를 서로 바꾼다.

const char* movie_name(int movie_num);		// 영화 이름 반환
const char* when_day(int movie_num);		// 영화 상영 일자 반환
const char* when_time(int movie_num);		// 영화 상영 시간 반환

int* uniqueNums(int count);					// 1 ~ count 정수를 섞어서 반환한다.
int calculate_seat_num(const char* seat);	// A1 -> 1, B3 -> 13, D4 -> 44와 같이 좌석번호를 반환


/*******************************************************************************
								입력값 유효성 검사
*******************************************************************************/

bool isValidDay(char day);					// day가 0 ~ 3 사이의 값인지 검사한다.
bool isValidTime(char time);				// time이 0 ~ 9 사이의 값인지 검사한다.
bool isValidSeat(char seat[]);				// seat가 A1 ~ J10까지의 좌석인지 검사한다.
