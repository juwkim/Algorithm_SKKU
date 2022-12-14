#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

typedef int Data;

typedef struct _Node {
    Data item;
    struct _Node* next;
} Node;

typedef struct {
    Node* head;
    Data len;
} LinkedList;

// Make a list empty.
void InitList(LinkedList* plist) {
    // Create a dummy node;
    plist->head = (Node*)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->len = 0;
}

// Insert an item at the k-th position.
void InsertFirst(LinkedList* plist, Data item) {
    Node* head = plist->head;
    Node* newNode;

    // Create a new node.
    newNode = (Node*)malloc(sizeof(Node));

    newNode->item = item;
    newNode->next = head->next;
    head->next = newNode;

    plist->len++;
}

// Print each item in a list in sequence.
void PrintList(LinkedList* plist) {
    for (Node* cur = plist->head->next; cur != NULL; cur = cur->next)
        printf("%d ", cur->item);
     
}
void PrintLength(LinkedList* plist, float m) {
    float sum = 0; int max = 0; int min = 50;
    for (int i = 0; i < m; i++) {
        int num = (plist + i)->len;
        sum += num;
        if (num > max) max = num;
        if (num < min) min = num;
    }
    float avg = sum / m;
    printf("shortest length: %d\n", min);
    printf("longest length: %d\n", max);
    printf("average length: %f\n", avg);
}


int main() {
    srand((unsigned)time(NULL));
    int key, hash;
    int num[3];
    num[0] = 7, num[1] = 13, num[2] = 17;

    LinkedList HashTable[17];
   
    for (int i = 0; i < 3; i++) {
        int m = num[i];

        for (int i = 0; i < m; i++) {
            InitList(&HashTable[i]);
        }

        for (int i = 0; i < 50; i++) {
            key = rand() % 1000;
            hash = key % m;
            InsertFirst(&HashTable[hash], key);
        }

        printf("h(k) = k mod %d 인 경우\n", m);
        for (int i = 0; i < m; i++) {
            printf("해쉬 값 %d: ", i);
            PrintList(&HashTable[i]);
            printf("\n");
        }
        PrintLength(HashTable, m);
        printf("\n");
    }
    return 0;
}

