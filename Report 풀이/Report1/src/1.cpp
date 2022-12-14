#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* pseudo-code of BUBBLE-SORT*/
/*BubbleSort(A)
n : = length(A)
for i = 1 to n - 1
    for j = 1 to n-i
        if A[j-1] > A[j]
            swap(A[j - 1], A[j])
 */

int bubble_sort(int arr[])
{
    int temp, count=0;
    for (int i = 0; i < 99; i++)
    {   
        for (int j = 1; j < 100-i; j++)
        {   
            count++;
            if (arr[j-1] > arr[j])
            {   
                temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return count;
}

int checkSame(int arr[], int end, int num)
{
    int i, count=0;
    for (i = 0; i < end; i++)
    {
        if (num != arr[i]) count++;
    }
    if (count == end) return 1;
    else return 0;
}

int makeRandomList(int arr[])
{   
    int i, j=0, temp;

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
            arr[i] = i+1;
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
    for (i = 0; i<100; i++)
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
    
    count1 = bubble_sort(RandomList);
    printf("After sorting\n");
    printList(RandomList);
    printf("Random List Count: %d\n", count1);
    printf("\n");

    printf("Already Sorted List Result\n");
    printf("Before sorting\n");
    printList(SortedList);

    count2 = bubble_sort(SortedList);

    printf("After sorting\n");
    printList(SortedList);
    printf("Already Sorted List Count: %d\n", count2);
    printf("\n");

    printf("Reversely Sorted List Result\n");
    printf("Before sorting\n");
    printList(ReverselySortedList);

    count3 = bubble_sort(ReverselySortedList);

    printf("After sorting\n");
    printList(ReverselySortedList);
    printf("Reversely Sorted List Count: %d\n", count3);
    printf("\n");

    return 0;
}