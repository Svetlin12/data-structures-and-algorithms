#pragma once
#include <iostream>

// swap function
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

// the partition function takes the rightmost element of the current subarray and starts moving the elements that
// are lower than or equal to it to its left and those that are greater than it to its right
// after the cycle has finished we move this rightmost element to its right position which is right after the last
// element that was lower than or equal to it
// at the end of this function when we return the index that points to that element in the subarray we will know
// in quickSort() that at that index we have an element that is in its right place and that the subarray to its
// left contains unsorted numbers that are all lower than or equal to that number and the subarray to its right
// contains numbers that are all bigger than it
int partition(int* arr, int left, int right)
{
	// this is the element that we were talking about
	int pivot = arr[right];

	// this points to the start of the subarray
	int startingIndex = left;

	// we start cycling from the start of the subarray until the end of it and place each element that is lower than
	// or equal at the start of the subarray with the help of startingIndex
	for (int i = left; i < right; i++)
		if (arr[i] <= pivot)
			swap(arr[i], arr[startingIndex++]);

	// place the pivot number at its right place (right after the last element that was lower than or equal to it)
	swap(arr[right], arr[startingIndex]);

	// return the index that points to where that number is
	return startingIndex;
}

// the implementation of quick sort
void quickSort(int* arr, int left, int right)
{
	// the recursion stops when we reach one element which by default is a sorted subarray
	if (left < right)
	{
		// we get the index of the current right most element which after going through partition() is sorted 
		// meaning that it is in its right place in the array
		int pi = partition(arr, left, right);

		// what is left is to sort the left and the right subarrays
		quickSort(arr, left, pi - 1);
		quickSort(arr, pi + 1, right);
	}
}