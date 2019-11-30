class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
	    if (n == 1)
		    return 1;

	    priority_queue<long long, vector<long long>, greater<long long>> pq;
	    pq.push(1);
	    int size = primes.size();
	    int counter = 1;

	    while (counter < n)
	    {
		    long long top = pq.top();
		    pq.pop();
		    if (pq.size() == 0)
		    {
			    counter++;
			    for (int i = 0; i < size; i++)
				  pq.push(top * primes[i]);
		    }
		    else if (top != pq.top())
		    {
			    counter++;
			    for (int i = 0; i < size; i++)
				   pq.push(top * primes[i]);
		    }
	    }

	  return pq.top();
    }
};
