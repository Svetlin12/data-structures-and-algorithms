#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

bool linearSearch(vector<int>& arr, int target)
{
	int size = (int)arr.size();
	for (int i = 0; i < size; i++)
		if (arr[i] == target)
			return true;
	return false;
}

bool binarySearch(vector<int>& arr, int target)
{
	int start = 0;
	int end = (int)arr.size() - 1;

	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (arr[mid] == target)
			return true;
		else if (arr[mid] < target)
			start = mid + 1;
		else
			end = mid - 1;
	}

	return false;
}

bool ternarySearch(vector<int>& arr, int target, int left, int right)
{
	if (left > right)
		return false;

	int mid1 = left + (right - left) / 3;
	int mid2 = right - (right - left) / 3;

	if (arr[mid1] == target || arr[mid2] == target)
		return true;
	else if (arr[mid1] > target)
		return ternarySearch(arr, target, left, mid1 - 1);
	else if (arr[mid2] < target)
		return ternarySearch(arr, target, mid2 + 1, right);
	else
		return ternarySearch(arr, target, mid1 + 1, mid2 - 1);
}

bool jumpSearch(vector<int> arr, int target)
{
	int size = (int)arr.size();

	int step = floor(sqrt(size));
	int prev = 0;
	int squareSize = step;

	while (arr[min(step, size) - 1] < target)
	{
		prev = step;
		step += squareSize;
		if (prev >= size)
			return false;
	}

	while (arr[prev] < target)
	{
		prev++;
		if (prev == min(step, size))
			return false;
	}

	if (arr[prev] == target)
		return true;

	return false;
}

//quick search
int partition(vector<int>& nums, int left, int right)
{
	int pivot = nums[right];
	int startingIndex = left;

	for (int i = left; i < right; i++)
		if (nums[i] <= pivot)
			swap(nums[i], nums[startingIndex++]);

	swap(nums[right], nums[startingIndex]);

	return startingIndex;
}

int randomPartition(vector<int>& nums, int left, int right)
{
	int randomIndex = left + rand() % (right - left);
	swap(nums[right], nums[randomIndex]);
	return partition(nums, left, right);
}

int randomizedSelect(vector<int>& nums, int left, int right, int k)
{
	if (left == right)
		return nums[left];

	int q = randomPartition(nums, left, right);

	if (q == nums.size() - k)
		return nums[q];
	else if (q > nums.size() - k)
		return randomizedSelect(nums, left, q - 1, k);
	else
		return randomizedSelect(nums, q + 1, right, k);
}

int main()
{
	srand(time(nullptr));

	return 0;
}
