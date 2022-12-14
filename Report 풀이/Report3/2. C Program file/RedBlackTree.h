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

Tree** createTable(int num, int bookedSeat);				// num���� Tree�� ���� bookedSeat���� ��带 ����
Tree* createRBT();											// RBT �����

Node* createNode(Tree* RBT, int seat, const char* movie, const char* day, const char* time, int password);						// nemNode �����
Node* grandparent(Node* node);								// ���θ� ��� ã��
Node* uncle(Node* node);									// ���� ã��
Node* sibling(Node* node);									// ���� ã��
Node* findSuccessor(Tree* RBT, Node* node);					// Successor ã��
Node* search(Tree* RBT, int seat);							// seat ���� ���� ��� ã��
Node* findNode(Tree* RBT, Node* node, int password);		// password ���� ���� ��� ã��

void rotateLeft(Tree* RBT, Node* node);						// Ʈ�� ���� ȸ��
void rotateRight(Tree* RBT, Node* node);					// Ʈ�� ���� ȸ��
void transPlant(Tree* RBT, Node* node, Node* successor);	// Ʈ�� �Ű� �ɱ�

void treeFixUp(Tree* RBT, Node* node);						// ���Խ� Ʈ�� ���� ����
void treeDelFixUp(Tree* RBT, Node* node);					// ������ Ʈ�� ���� ����

void rb_insert(Tree* RBT, Node* node);						// Ʈ���� ��� ����
void rb_delete(Tree* RBT, Node* node);						// Ʈ�� ��� ����

void printTree(Tree* RBT, Node* node);						// Ʈ�� ��� ���

int getHeight(Tree* RBT, Node* node, int left, int right);  // RBT�� Height ���ϱ�

bool isExistSeat(Tree* RBT, char seat[]);					// seat�� RBT�� �����ϴ��� �˻��Ѵ�.