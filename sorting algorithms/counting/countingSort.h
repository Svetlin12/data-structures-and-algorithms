#pragma once
#include <iostream>

// the below code is the implementation of counting sort
// NOTE: this algorithm is inteded for arrays that DO NOT contain negative elements
// if they do contain such, this algorithm SHOULD NOT be used since it creates an array which will
// store the count of the repetitions of each element in the array
// therefore, if the array has a negative value, at some point we will try to access a negative index of the array 
// we just created
// this will result into the program crashing with an error message: "Access violation"
void countingSort(int* arr, int size)
{
	// first we create an array that will be the copy of the initial one which we will use when we change
	// the initial array
	int* copyArr = new int[size];

	// we initialize i here to avoid multiple initializations throught the function
	int i;

	// we find the maximum number in the array whilst copying the elements 
	// from the initial array into the copy array
	int max = arr[0];
	for (i = 0; i < size; i++)
	{
		if (max < arr[i])
			max = arr[i];
		copyArr[i] = arr[i];
	}

	// since we found the maximum number we know that the elements in the below array will be from the range
	// [0, max], so we want an array that can store these numbers including max (therefore the size of max + 1)
	// this array will store the repetitions of each element (each element in the initial array is each index
	// in the array bellow)
	int* arrOfCounts = new int[max + 1];

	// we fill this array with 0s
	for (i = 0; i < max + 1; i++)
		arrOfCounts[i] = 0;

	// we start going through the initial array and we increment the value of the corresponding cell (in arrOfCounts) 
	// for each element in the arr
	// this means that:
	// if we find 1 in arr we increment arrOfCounts[1] with 1
	// if we find 10 in arr we increment arrOfCounts[10] with 1
	// and so on
	for (i = 0; i < size; i++)
		arrOfCounts[arr[i]]++;

	// now that we have the number of repetitions of each element and since arrOfCounts is sorted by default 
	// (its an array that represents the numbers from 0 to max), we start adding the value of the previous cell
	// to the next one because this will result in arrOfCounts containing numbers that represent the index of the 
	// initial array which the numbers reach (without including the index itself)
	// this means that:
	// if the value at arrOfCounts[0] is 2, then the 0s will occupy the indices 0 and 1 in the
	// initial array
	// if the value at arrOfCOunts[1] is 5, then the 1s will occupy the indices 2, 3 and 4 in the initial array
	for (i = 1; i < max + 1; i++)
		arrOfCounts[i] += arrOfCounts[i - 1];

	// now that we know to which index each number reaches we can now start modifying arr
	for (i = size - 1; i >= 0; i--)
	{
		// copyArr[i] returns the value of the element of the previous array that resides in the i-th place
		// arrOfCounts[copyArr[i]] returns the index for the initialArray to where to put the value copyArr[i]
		// note that we will have to subtract 1 from the value above since the values in arrOfCounts were initally
		// numbers of repetitions (meaning that in total we will have size elements) and therefore the maximum sum
		// will be size
		// but we are changing an array and therefore we have to always subtract 1 from that value since it will
		// always be 1 higher than the indexing of arr
		arr[arrOfCounts[copyArr[i]] - 1] = copyArr[i];

		// after the above step we decrease the value at that index to know where to add the next value in that index
		arrOfCounts[copyArr[i]]--;
	}

	// we clear the memory that we took using new
	delete[] arrOfCounts;
	delete[] copyArr;
}