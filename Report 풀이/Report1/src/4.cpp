#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int A[4][4], B[4][4];
int C[8][8], D[8][8];

void fillMatrix4(int arr[][4])
{
	int i, j;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				arr[i][j] = rand() % 1000;
			}
		}
}
void fillMatrix8(int arr[][8])
{
	int i, j;
	srand((unsigned)time(NULL));
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			arr[i][j] = rand() % 1000;
		}
	}
}
void printMatrix4(int arr[][4])
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void printMatrix8(int arr[][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int standard4(int A[][4], int B[][4])
{
	int i, j, k, c, count=0, print=0;
	printf("Matrix Multiplication Result\n");
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			c = 0;
			for (k = 0; k < 4; k++)
			{
				count = count + 2;
				c = c + A[i][k] * B[k][j];
			}
			printf("%d ", c);
			print++;
			if (print % 4 == 0) printf("\n");
		}
	}
	printf("\n");
	printf("count: %d\n\n", count);
	return count;
}
int standard8(int A[][8], int B[][8])
{
	int i, j, k, c, count = 0, print = 0;
	printf("Matrix Multiplication Result\n");
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			c = 0;
			for (k = 0; k < 8; k++)
			{
				count = count + 2;
				c = c + A[i][k] * B[k][j];
			}
			printf("%d ", c);
			print++;
			if (print % 8 == 0) printf("\n");
		}
	}
	printf("\n");
	printf("count: %d\n\n", count);
	return count;
}

int recursive(int A[][4], int B[][4])
{
	int size;
	size = sizeof(A[0]) / sizeof(int);
}

void multiplyMatrix(int row1, int col1, int A[][MAX],
	int row2, int col2, int B[][MAX])
{
	int C[MAX][MAX] = { 0 };

	multiplyMatrixRec(row1, col1, A, row2, col2, B, C);

	// Print the result 
	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col2; j++)
			printf("%d  ", C[i][j]);

		printf("\n");
	}
}

int main()
{
	srand((unsigned)time(NULL));
	fillMatrix4(A);
	fillMatrix4(B);

	printf("4X4 Matrix Multiplication with Standard Algorithm\n\n");
	printf("Matrix1\n");
	printMatrix4(A);
	printf("Matrix2\n");
	printMatrix4(B);
	standard4(A, B);

	fillMatrix8(C);
	fillMatrix8(D);

	printf("8X8 Matrix Multiplication with Standard Algorithm\n\n");
	printf("Matrix 1\n");
	printMatrix8(C);
	printf("Matrix 2\n");
	printMatrix8(D);
	standard8(C, D);
	return 0;
}