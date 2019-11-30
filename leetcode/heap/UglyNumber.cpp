class Solution {
public:
	int nthUglyNumber(int n) {
		if (n == 1)
			return 1;
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		pq.push(1);
		set<long long> nums;
		nums.insert(1);

		for (int i = 0; i < n - 1; i++)
		{
			long long top = pq.top();
			pq.pop();
			if (nums.find(top * 2) == nums.end())
			{
				pq.push(top * 2);
				nums.insert(top * 2);
			}
			if (nums.find(top * 3) == nums.end())
			{
				pq.push(top * 3);
				nums.insert(top * 3);
			}
			if (nums.find(top * 5) == nums.end())
			{
				pq.push(top * 5);
				nums.insert(top * 5);
			}
		}

		return pq.top();
	}
};
