// lower bound
// if x is present multiple times in the vector, it returns the rightmost index
// if x is not present in the vector, it returns the biggest element such that it is smaller than x if such number exists
int lowerBound(vector<int>& vec, int x)
{
	int start = 0;
	int end = (int)vec.size() - 1;

	int mid;
	int ans = -1;
	while (start < end)
	{
		mid = (start + end) / 2;
		
		if (vec[mid] <= x)
		{
			ans = mid;
			start = mid + 1;
		}
		else
			end = mid - 1;
	}

	if (vec[start] <= x)
	{
		return start;
	}
	else
		return ans;
}
