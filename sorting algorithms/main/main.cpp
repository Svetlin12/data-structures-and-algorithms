#include "countingSort.h"
#include "mergeSort.h"
#include <string>

void printArray(int* arr, int size, const std::string mode, const std::string sortType)
{
	std::cout << "Array " << mode << " the algorithm using " << sortType << ": " << std::endl;
	for (unsigned int i = 0; i < size; i++)
		std::cout << arr[i] << " ";

	std::cout << std::endl;
}

int main()
{
	int arr[] = { 1, 10, 5 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printArray(arr, size, "before", "counting sort");

	//countingSort(arr, size);
	mergeSort(arr, 0, size - 1);

	//printArray(arr, size, "after", "counting sort");
	printArray(arr, size, "after", "merge sort");

	std::cin.get();
	return 0;
}