#pragma once

void swap(int* first_num, int* second_num);	// �� �ּҿ� ����� ������ ���� �ٲ۴�.

const char* movie_name(int movie_num);		// ��ȭ �̸� ��ȯ
const char* when_day(int movie_num);		// ��ȭ �� ���� ��ȯ
const char* when_time(int movie_num);		// ��ȭ �� �ð� ��ȯ

int* uniqueNums(int count);					// 1 ~ count ������ ��� ��ȯ�Ѵ�.
int calculate_seat_num(const char* seat);	// A1 -> 1, B3 -> 13, D4 -> 44�� ���� �¼���ȣ�� ��ȯ


/*******************************************************************************
								�Է°� ��ȿ�� �˻�
*******************************************************************************/

bool isValidDay(char day);					// day�� 0 ~ 3 ������ ������ �˻��Ѵ�.
bool isValidTime(char time);				// time�� 0 ~ 9 ������ ������ �˻��Ѵ�.
bool isValidSeat(char seat[]);				// seat�� A1 ~ J10������ �¼����� �˻��Ѵ�.
