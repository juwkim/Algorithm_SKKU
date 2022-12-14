#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linear_prob(int k, int a) {
	return (((k % 37) + a) % 37);
}

int quadratic_prob(int k, int b) {
	return (((k % 37) + b + 3*b*b) % 37);
}
int double_hashing(int k, int c) {
	return (((k % 37) + c * (1 + (k % 36))) % 37);
}
int prob(int k, int i, int f) {
	if (f == 0) return linear_prob(k, i);
	else if (f == 1) return quadratic_prob(k, i);
	else return double_hashing(k, i);
}

int Hash_Insert(int T[], int k, int f) {
	int i = 0;
	while (i != 37) {
		int a = prob(k, i, f);
		if (T[a] == NULL) {
			T[a] = k;
			return a;
		}
		else i = i + 1;
	}
}

int Hash_Search(int T[], int k, int f, int *i) {
	int b = prob(k, 0, f);

	while ((T[b] != NULL) && ((*i) != 37)) {
		b = prob(k, *i, f);
		if (T[b] == k) return b;
		*i += 1;
	}
	return NULL;
}

int print(int T[], int f) {
	float sum = 0; int max = 0;
	for (int j = 0; j < 30; j++) {
		int i = 0;
		int pos = Hash_Search(T, T[j], f, &i);
		printf("%d의 위치는 HashTable[%d]입니다.\n", T[j], pos);
		sum += (i+1);
		if ((i+1) > max) max = (i+1);
	}
	float avg = sum / 30;
	printf("average number of probes: %f\n", avg);
	printf("primary(largest) cluster of the hash table: %d\n\n", max);
	return 0;
}

int main() {
	int m = 37;

	int HashTable1[30] = { NULL, };
	int HashTable2[30] = { NULL, };
	int HashTable3[30] = { NULL, };
	srand((unsigned)time(NULL));

	for (int j = 0; j < 30; j++) {
		int key = rand() % 1000;
		Hash_Insert(HashTable1, key, 0);
		Hash_Insert(HashTable2, key, 1);
		Hash_Insert(HashTable3, key, 2);
	}
	printf("%d번째\n", 1);
	print(HashTable1, 0);
	printf("%d번째\n", 2);
	print(HashTable1, 1);
	printf("%d번째\n", 3);
	print(HashTable1, 2);
	return 0;
}