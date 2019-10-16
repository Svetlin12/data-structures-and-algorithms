#pragma once
#include <iostream>

// we get the original array, the left pointer of the left subarray, the middle pointer which is the 
// pointer to the right part of the left subarray (also, this pointer points to the element that was 
// originally the 'center' of the divided array) and the right pointer to the right subarray
// first(left) subarray is arr1[l,...,m]
// second(right) subarray is arr2[m + 1,...r]
void merge(int *arr, int left, int middle, int right)
{
	// get the size of the left sub-array
	int size1 = middle - left + 1;
	
	// get the size of the right sub-array
	int size2 = right - middle;

	// initialize the two subarrays that will contain the parts of the given array that we will copy
	int *arr1 = new int[size1];
	int *arr2 = new int[size2];

	// set the values of the subarrays to their corresponding ones from the given array
	for (unsigned int i = 0; i < size1; i++)
		arr1[i] = arr[i + left];

	for (unsigned int i = 0; i < size2; i++)
		arr2[i] = arr[i + middle + 1];

	// i will be the counter for the first array (arr1)
	// j will be the counter for the second array (arr2)
	int i = 0, j = 0;

	// this counter will be for the main array
	// we basically set the sorted value to counterArr position in arr and then increment counterArr to prepare for
	// the next insertion
	int counterArr = left;

	// while there are elements in both of them simultaneously we check whether the element in the first subarray
	// is less than the one in the second subarray
	// if yes, then set the value in counterArr position in arr to arr1[i] and increment i
	// if not, then set the value in counterArr position in arr to arr2[j] and increment j
	while (i < size1 && j < size2)
	{
		if (arr1[i] < arr2[j])
			arr[counterArr++] = arr1[i++];
		else
			arr[counterArr++] = arr2[j++];
	}

	// if after the above cycle we didn't check all of the elements in the first subarray (arr1)
	// we add them to the original array
	while (i < size1)
		arr[counterArr++] = arr1[i++];

	// same as above cycle, only now we check if we haven't added all the elements in the second subarray (arr2)
	while (j < size2)
		arr[counterArr++] = arr2[j++];

	// clear the memory that we have taken with new
	delete[] arr1;
	delete[] arr2;
}

// the implementation of merge sort:
void mergeSort(int *arr, int left, int right)
{
	// the break case for the recursion is when we reach a single element (left == right) or if left pointer
	// gets bigger than the right one, which is a mistake since in an array the left pointer should always
	// be less than or equal to the right one
	if (left < right)
	{
		// we take the middle element of the current array to continue dividing it into two subarrays until we get
		// two single element arrays and start sorting them
		int middle = (left + right) / 2;

		// merge the left subarray
		mergeSort(arr, left, middle);

		// merge the right subarray
		mergeSort(arr, middle + 1, right);

		// this is the function where we merge the two subarrays whilst sorting them
		// see explanation above
		merge(arr, left, middle, right);
	}
}