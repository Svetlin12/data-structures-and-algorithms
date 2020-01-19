#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

void bubbleSort(vector<int>& arr)
{
	int size = (int)arr.size();
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (arr[i] > arr[i + 1])
				swap(arr[i], arr[i + 1]);
}

// pick the minimal current element and place it at the i-th position
void selectionSort(vector<int>& arr)
{
	int size = (int)arr.size();
	for (int i = 0; i < size; i++)
	{
		int min = i;
		for (int j = i + 1; j < size; j++)
			if (arr[min] > arr[j])
				min = j;

		if (min != i)
			swap(arr[min], arr[i]);
	}
}

// pick the current element and place it at its right position
void insertionSort(vector<int>& arr)
{
	int size = (int)arr.size();
	for (int i = 1; i < size; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void merge(vector<int>& nums, int left, int middle, int right)
{
	int sizeL = middle - left + 1;
	int sizeR = right - middle;

	vector<int> numsL(sizeL);
	vector<int> numsR(sizeR);

	for (int i = 0; i < sizeL; i++)
		numsL[i] = nums[i + left];

	for (int i = 0; i < sizeR; i++)
		numsR[i] = nums[i + middle + 1];

	int i = 0, j = 0, counter = left;

	while (i < sizeL && j < sizeR)
	{
		if (numsL[i] > numsR[j])
			nums[counter++] = numsR[j++];
		else
			nums[counter++] = numsL[i++];
	}

	while (i < sizeL)
		nums[counter++] = numsL[i++];

	while (j < sizeR)
		nums[counter++] = numsR[j++];
}

void mergeSort(vector<int>& nums, int left, int right)
{
	if (left < right)
	{
		int middle = (left + right) / 2;
		mergeSort(nums, left, middle);
		mergeSort(nums, middle + 1, right);
		merge(nums, left, middle, right);
	}
}

int partition(vector<int>& nums, int left, int right)
{
	int pivot = nums[right];

	int startingInd = left;

	for (int i = left; i < right; i++)
		if (nums[i] <= pivot)
			swap(nums[i], nums[startingInd++]);

	swap(nums[right], nums[startingInd]);

	return startingInd;
}

int randomPartition(vector<int>& nums, int left, int right)
{
	int randomInd = left + rand() % (right - left);
	swap(nums[randomInd], nums[right]);
	return partition(nums, left, right);
}

// prefer mergeSort when nums is big in size
// quickSort is better than mergeSort when nums is small in size
void quickSort(vector<int>& nums, int left, int right)
{
	if (left < right)
	{
		int pi = randomPartition(nums, left, right);

		quickSort(nums, left, pi - 1);
		quickSort(nums, pi + 1, right);
	}
}

// only works with positive numbers
void countingSort(vector<int>& nums)
{
	int size = (int)nums.size(), i;
	int max = nums[0];
	vector<int> copy(size);

	for (i = 0; i < size; i++)
	{
		if (max < nums[i])
			max = nums[i];
		copy[i] = nums[i];
	}

	vector<int> count(max + 1, 0);

	for (i = 0; i < size; i++)
		count[nums[i]]++;

	for (i = 1; i < max + 1; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		nums[count[copy[i]] - 1] = copy[i];
		count[copy[i]]--;
	}
}

void heapify(vector<int>& nums, int size, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && nums[left] > nums[largest])
        largest = left;
    if (right < size && nums[right] > nums[largest])
        largest = right;
    if (largest != index)
    {
        swap(nums[index], nums[largest]);
        heapify(nums, size, largest);
    }
}

void heapSort(vector<int>& nums)
{
    int size = (int)nums.size();

    // build heap
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(nums, size, i);

    for (int i = size - 1; i >= 0; i--)
    {
        swap(nums[0], nums[i]);
        heapify(nums, i - 1, 0);
    }
}

int main()
{
	srand(time(nullptr));

	return 0;
}
