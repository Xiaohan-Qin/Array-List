#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include"arraylist.h"

/*
Print all elements of array.
INPUT: an array pointer.
*/
void printAll(AList* alist){
    int i;
    for(i=0; i<alist->length; i++) {
        printf("%d ", alist->list[i]);
    }
    printf("\n");
}


/*
Swap two elements in array.
INPUT: an array list pointer.
INPUT: an int value indicating the left index to be swapped.
INPUT: an int value indicating the right index to be swapped.
*/
void swap(AList* alist, int left, int right) {
    int temp = alist->list[left];
    alist->list[left] = alist->list[right];
    alist->list[right] = temp;
}


/*
Sort array.
INPUT: an array list pointer.
INPUT: an int value indicating from which index the sorting starts.
INPUT: an int value indicating to which index the sorting ends.
*/
void quicksort(AList* alist, int start, int end){
    if(start >= end) {
        return;
    }
    int pivot = partition(alist, start, end);
    quicksort(alist, start, pivot - 1);
    quicksort(alist, pivot + 1, end);
}


/*
Partition the array. For each unsorted partition, use first element as pivot.
INPUT: an array list pointer.
INPUT: an int value indicating from which index the partition starts.
INPUT: an int value indicating to which index the partition ends.
Returns the pivot index, with the array partially sorted.

for each unsorted partition, set first element as pivot
initialize storeIndex at pivotIndex + 1
traverse the array and compare each element with pivot
if element is smaller or equal to pivot, swap element with storeIndex and increment storeIndex by 1
if element is larger than pivot, keep going
finally swap pivot with storeIndex - 1
*/
int partition(AList* alist, int start, int end) {
    // printf("pivot is %d and end is %d\n", start, end);
    int pivot = alist->list[start];
    int storeIndex = start + 1;
    int i;
    for (i = storeIndex; i <= end; i++){
        if (alist->list[i] < pivot){
            swap(alist, i, storeIndex);
            storeIndex++;
        }
    }
    swap(alist, start, storeIndex - 1);
    // printf("returning... New pivot is at index %d\n", storeIndex - 1);
    return storeIndex - 1;
}


/*
Append an element at the end of an array.
INPUT: an array list pointer.
INPUT: an int value.
*/
void add(AList* alist, int val) {
    int* arr = (int*)malloc(sizeof(int) * (alist->length + 1));
    int* temp = alist->list;

    int i;
    for(i=0; i<alist->length; i++) {
        arr[i] = alist->list[i];
    }
    arr[alist->length] = val;
    alist->list = arr;
    alist->length = alist->length + 1;
    free(temp);
}


/*
Initializa an array with just one element.
INPUT: an int value.
Returns a pointer to the array list.
*/
AList* create(int val) {
    int* l = (int*)malloc(sizeof(int));
    l[0] = val;

    AList* alist = (AList*)malloc(sizeof(AList));
    alist->list = l;
    alist->length = 1;
    return alist;
}


/*
Generate a random array at a given length within a given range.
INPUT: an int value indicating the lower bound.
INPUT: an int value indicating the upper bound.
INPUT: an int value indicating the number of elements in array.
Returns a pointer to the newly generated array list.
*/
AList* createRandom(int lower, int upper, int count){
    srand(time(0));
    int first = rand() % (upper - lower + 1) + lower;
    AList* randomList = create(first);
    int i;
    for (i=1; i<count; i++){
        int num = (rand() % (upper - lower + 1)) + lower;
        add(randomList, num);
    }
    return randomList;
}


/*
Get run time for an array sorting.
INPUT: an int value indicating the lower bound of array elements.
INPUT: an int value indicating the upper bound of array elements.
INPUT: an int value indicating the number of elements in array.
Returns the elapsed time in micro-seconds as a double.
*/
double getRunTime(int lower, int upper, int count){
    AList* alist = createRandom(lower, upper, count);
    struct timeval start, end;
    gettimeofday(&start, NULL);
    quicksort(alist, 0, alist->length - 1);
    gettimeofday(&end, NULL);
    long seconds = (end.tv_sec - start.tv_sec);
    long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
    printf("Elapsed time is %d micros\n", micros);
    free(alist->list);
    free(alist);
}


/*
Driver program
*/
int main() {
    printf("------------FUNCTION TESTS------------\n");
    AList* alist = create(10);
    printAll(alist);
    add(alist, 2);
    printAll(alist);
    add(alist, 2);
    printAll(alist);

    add(alist, 5);
    add(alist, 1);
    add(alist, 7);
    printf("Unsorted list:\n");
    printAll(alist);

    quicksort(alist, 0, alist->length - 1);
    printf("Sorted list:\n");
    printAll(alist);
    free(alist->list);
    free(alist);
    printf("------------FUNCTION TESTS END------------\n");

    printf("\n");
    printf("------------RUN TIME TESTS------------\n");

    printf("Lower bound is 0\nUpper bound is 100\nLength is 10:\n");
    getRunTime(0, 100, 10);
    printf("\n");
    printf("Lower bound is 0\nUpper bound is 100\nLength is 100:\n");
    getRunTime(0, 100, 100);
    printf("\n");
    printf("Lower bound is 0\nUpper bound is 100\nLength is 10000:\n");
    getRunTime(0, 100, 10000);
    printf("\n");
    printf("Lower bound is 0\nUpper bound is 10000\nLength is 10:\n");
    getRunTime(0, 10000, 10);
    printf("\n");
    printf("Lower bound is 0\nUpper bound is 10000\nLength is 100:\n");
    getRunTime(0, 10000, 100);
    printf("\n");
    printf("Lower bound is 0\nUpper bound is 10000\nLength is 10000:\n");
    getRunTime(0, 10000, 10000);

    printf("------------RUN TIME TESTS END------------\n");

    return 0;
}
