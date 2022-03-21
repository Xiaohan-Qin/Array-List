#ifndef ARRAY_H
#define ARRAY_H


/*
======================================================
ARRAYLIST
======================================================


STRUCT DEFINITIONS
This struct represents the entire array list.
This struct contains metadata about the array list.
*/
typedef struct AList {
    int* list;
    int length;
}AList, *AListPtr;


/*
Initializa an array with just one element.
INPUT: an int value.
Returns a pointer to the array list.
*/
AList* create(int val);


/*
Append an element at the end of an array.
INPUT: an array list pointer.
INPUT: an int value.
*/
void add(AList* alist, int val);


/*
Print all elements of array.
INPUT: an array pointer.
*/
void printAll(AList* alist);


/*
Generate a random array at a given length within a given range.
INPUT: an int value indicating the lower bound.
INPUT: an int value indicating the upper bound.
INPUT: an int value indicating the number of elements in array.
Returns a pointer to the newly generated array list.
*/
AList* createRandom(int lower, int upper, int count);


/*
Sort array.
INPUT: an array list pointer.
INPUT: an int value indicating from which index the sorting starts.
INPUT: an int value indicating to which index the sorting ends.
*/
void quicksort(AList* alist, int start, int end);


/*
Partition the array. For each unsorted partition, use first element as pivot.
INPUT: an array list pointer.
INPUT: an int value indicating from which index the partition starts.
INPUT: an int value indicating to which index the partition ends.
Returns the pivot index, with the array partially sorted.
*/
int partition(AList* alist, int start, int end);


/*
Swap two elements in array.
INPUT: an array list pointer.
INPUT: an int value indicating the left index to be swapped.
INPUT: an int value indicating the right index to be swapped.
*/
void swap(AList* alist, int left, int right);


/*
Get run time for an array sorting.
INPUT: an int value indicating the lower bound of array elements.
INPUT: an int value indicating the upper bound of array elements.
INPUT: an int value indicating the number of elements in array.
Returns the elapsed time in micro-seconds as a double.
*/
double getRunTime(int lower, int upper, int count);

#endif
