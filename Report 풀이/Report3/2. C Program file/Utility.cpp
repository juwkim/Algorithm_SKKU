#include <stdio.h>
#include <stdlib.h>

/*******************************************************************************
								유용한 함수들
*******************************************************************************/

void swap(int* first_num, int* second_num) {
	int temp = *first_num;
	*first_num = *second_num;
	*second_num = temp;
}

const char* movie_name(int movie_num) {
	if ((movie_num % 9) / 3 == 0) return "스파이더맨";
	else if ((movie_num % 9) / 3 == 1) return "인터스텔라";
	else return "레미제라블";
}
const char* when_day(int movie_num) {
	if (movie_num / 9 == 0) return "내일";
	else if (movie_num / 9 == 1) return "모레";
	else return "글피";
}
const char* when_time(int movie_num) {
	if (movie_num % 9 == 0) return "13:00 ~ 15:42";
	else if (movie_num % 9 == 1) return "16:00 ~ 18:42";
	else if (movie_num % 9 == 2) return "19:00 ~ 21:42";
	else if (movie_num % 9 == 3) return "10:00 ~ 12:49";
	else if (movie_num % 9 == 4) return "14:00 ~ 16:49";
	else if (movie_num % 9 == 5) return "17:00 ~ 19:49";
	else if (movie_num % 9 == 6) return "12:00 ~ 14:38";
	else if (movie_num % 9 == 7) return "15:00 ~ 17:38";
	else return "18:00 ~ 20:38";
}

int* uniqueNums(int count) {
	int* data = (int*)malloc(sizeof(int) * count);

	if (data) {
		int	first_index, second_index, i;
		int mixing_count = 3 * count; // count의 3배의 횟수만큼 숫자들을 섞는다.
		
		for (i = 0; i < count; i++) *(data + i) = i + 1;

		for (i = 0; i < mixing_count; i++) {
			first_index = rand() % count;
			second_index = rand() % count;

			// 동일한 인덱스가 선택된 경우 무시한다.
			// 선택된 두 값을 서로 바꾼다.
			if (first_index != second_index) swap(data + first_index, data + second_index);
		}
	}
	else printf("uniqueNums함수에서 메모리가 정상적으로 할당되지 않았습니다.\n");
	return data;
}
int calculate_seat_num(const char* seat) {
	int row, column, seat_num;

	row = 10 * (seat[0] - 'A');

	if (seat[2]) column = 10;
	else column = seat[1] - '0';
	seat_num = row + column;

	return seat_num;
}

bool isValidDay(char day) {
	return ('0' <= day && day <= '3');
}
bool isValidTime(char time) {
	return ('0' <= time && time <= '9');
}

bool isValidSeat(char seat[]) {
	return ((('A' <= seat[0]) && (seat[0] <= 'J')) && (('0' < seat[1]) && (seat[1] <= '9'))) && ((seat[2] == NULL) || ((seat[2] == '0') && (seat[1] == '1')));
}