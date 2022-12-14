#pragma once

#define BLACK 1
#define RED 0

typedef struct node {
	int seat;
	int color;
	int password;
	const char* movie;
	const char* day;
	const char* time;
	struct node* parent;
	struct node* left;
	struct node* right;
} Node;

typedef struct {
	Node* root;
	Node* NIL;
	int len;
} Tree;

Tree** createTable(int num, int bookedSeat);				// num개의 Tree에 각각 bookedSeat개의 노드를 삽입
Tree* createRBT();											// RBT 만들기

Node* createNode(Tree* RBT, int seat, const char* movie, const char* day, const char* time, int password);						// nemNode 만들기
Node* grandparent(Node* node);								// 조부모 노드 찾기
Node* uncle(Node* node);									// 삼촌 찾기
Node* sibling(Node* node);									// 형제 찾기
Node* findSuccessor(Tree* RBT, Node* node);					// Successor 찾기
Node* search(Tree* RBT, int seat);							// seat 값을 가진 노드 찾기
Node* findNode(Tree* RBT, Node* node, int password);		// password 값을 가진 노드 찾기

void rotateLeft(Tree* RBT, Node* node);						// 트리 좌측 회전
void rotateRight(Tree* RBT, Node* node);					// 트리 우측 회전
void transPlant(Tree* RBT, Node* node, Node* successor);	// 트리 옮겨 심기

void treeFixUp(Tree* RBT, Node* node);						// 삽입시 트리 균형 수정
void treeDelFixUp(Tree* RBT, Node* node);					// 삭제시 트리 균형 수정

void rb_insert(Tree* RBT, Node* node);						// 트리에 노드 삽입
void rb_delete(Tree* RBT, Node* node);						// 트리 노드 삭제

void printTree(Tree* RBT, Node* node);						// 트리 노드 출력

int getHeight(Tree* RBT, Node* node, int left, int right);  // RBT의 Height 구하기

bool isExistSeat(Tree* RBT, char seat[]);					// seat가 RBT에 존재하는지 검사한다.