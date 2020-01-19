// upper bound
// if x is present multiple times in the vector, it returns the index of the leftmost element
// if x is not present in the vector, it returns the index of the smallest number such that it is the bigger than x if such number exists
int upperBound(vector<int>& vec, int x)
{
	int start = 0;
	int end = (int)vec.size() - 1;

	int ans = -1;
	int mid;
	while (start < end)
	{
		mid = (start + end) / 2;

		if (vec[mid] >= x)
		{
			ans = mid;
			end = mid - 1;
		}
		else
			start = mid + 1;
	}

	if (vec[start] >= x)
	{
		return start;
	}
	return ans;
}
