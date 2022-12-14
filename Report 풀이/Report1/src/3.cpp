#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct NODE
{
    struct NODE* next;
    int data;
};

int makeRandomList(int arr[])
{
    int i;

    srand((unsigned)time(NULL));
    for (i = 0; i < 60; i++)
    {
        arr[i] = rand() % 1000;
    }
    return 0;
}

void insert(struct NODE* target, int data)
{
    struct NODE* newNode = (struct NODE*) malloc(sizeof(struct NODE));
    newNode->next = target->next;
    newNode->data = data;

    target->next = newNode;
}

void Delete(struct NODE* target)
{
    struct NODE* prevNode = (struct NODE*)malloc(sizeof(struct NODE));
    struct NODE* delNode = (struct NODE*)malloc(sizeof(struct NODE));
    struct NODE* lastNode = (struct NODE*)malloc(sizeof(struct NODE));

    prevNode = target;
    delNode = target->next;
    lastNode = delNode->next;
    while (lastNode->next != NULL) 
    {
        prevNode = delNode;
        delNode = lastNode;
        lastNode = lastNode->next;
    }
    prevNode->next = lastNode;
    printf("Deleted data is %d.\n", delNode->data);
    free(delNode);
 }

void print(struct NODE* target)
{
    int count = 0;
    int start, cut1, cut2;
    struct NODE* curr = target->next;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    cut1 = count / 3;
    cut2 = count * 2 / 3;
    curr = target->next;

    printf("Line 1: ");
    for (start = 0; start < cut1; start++)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    printf("Line 2: ");
    for (start = cut1; start < cut2; start++)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    printf("Line 3: ");
    for (start = cut2; start < count; start++)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    int i, j;
    int A[60];

    makeRandomList(A);

    struct NODE* head = (struct NODE*)malloc(sizeof(struct NODE));
    head->next = NULL;

    for (i = 0; i < 60; i++)
    {
        insert(head, A[i]);
    }
    for (j = 0; j < 3; j++)
    {

        Delete(head);
        print(head);
        printf("\n");
    }
    return 0;
}