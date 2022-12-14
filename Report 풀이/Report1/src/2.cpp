#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int temp[100];
int com = 0;
int merge(int list[], int left, int mid, int right)
{
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

    while (i <= mid && j <= right)
    {
        if (list[i] >= list[j])
            temp[k++] = list[i++];
        else
            temp[k++] = list[j++];
    }

    if (i > mid)
    {
        for (l = j; l <= right; l++)
            temp[k++] = list[l];
    }
    else
    {
        for (l = i; l <= mid; l++)
            temp[k++] = list[l];
    }

    for (l = left; l <= right; l++)
    {
        com++;
        list[l] = temp[l];
    }
    return com;
}
int merge_sort(int list[], int left, int right)
{
    int mid;

    if (left < right)
    {
        mid = (left + right) / 2;
        merge_sort(list, left, mid);
        merge_sort(list, mid + 1, right);
        merge(list, left, mid, right);
    }
    return com;
}


int checkSame(int arr[], int end, int num)
{
    int i, count = 0;
    for (i = 0; i < end; i++)
    {
        if (num != arr[i]) count++;
    }
    if (count == end) return 1;
    else return 0;
}

int makeRandomList(int arr[])
{
    int i, j = 0, temp;

    srand((unsigned)time(NULL));
    for (i = 0; i < 100; i++)
    {
        temp = rand() % 1000;
        if (checkSame(arr, i, temp) == 1) arr[i] = temp;
        else i = i - 1;
    }
    return 0;
}
int makeSortedList(int arr[])
{
    int i;
    for (i = 0; i < 100; i++)
    {
        arr[i] = i + 1;
    }
    return 0;
}
int makeReverselySortedList(int arr[])
{
    int i;
    for (i = 0; i < 100; i++)
    {
        arr[i] = 100 - i;
    }
    return 0;
}

int printList(int arr[])
{
    int i;
    for (i = 0; i < 100; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

int main()
{
    int RandomList[100];
    int SortedList[100];
    int ReverselySortedList[100];
    int count1, count2, count3;

    makeRandomList(RandomList);
    makeSortedList(SortedList);
    makeReverselySortedList(ReverselySortedList);

    printf("Random List Result\n");
    printf("Before sorting\n");
    printList(RandomList);

    count1 = merge_sort(RandomList, 0, 99);
    printf("After sorting\n");
    printList(RandomList);
    printf("Random List Count: %d\n", count1);
    printf("\n");

    printf("Already Sorted List Result\n");
    printf("Before sorting\n");
    printList(SortedList);

    com = 0;
    count2 = merge_sort(SortedList, 0, 99);

    printf("After sorting\n");
    printList(SortedList);
    printf("Already Sorted List Count: %d\n", count2);
    printf("\n");

    printf("Reversely Sorted List Result\n");
    printf("Before sorting\n");
    printList(ReverselySortedList);

    com = 0;
    count3 = merge_sort(ReverselySortedList, 0, 99);

    printf("After sorting\n");
    printList(ReverselySortedList);
    printf("Reversely Sorted List Count: %d\n", count3);
    printf("\n");

    return 0;
}