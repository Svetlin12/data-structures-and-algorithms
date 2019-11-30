struct compare
{
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2)
    {
        if (p1.first + p1.second == p2.first + p2.second)
        {
            if (p1.first == p2.first)
            {
                return p1.second < p2.second;
            }
            else
                return p1.first < p2.first;
        }
        return p1.first + p1.second > p2.first + p2.second;
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        vector<vector<int>> ans;
        vector<int>::iterator firstIt = nums1.begin();
        vector<int>::iterator secondIt = nums2.begin();
        int sizeFirst = (int)nums1.size();
        int sizeSecond = (int)nums2.size();
        
        if (sizeFirst == 0 || sizeSecond == 0)
            return ans;
        
        int size = sizeFirst * sizeSecond;
        
        for (int i = 0; i < size; i++)
        {
            pq.push({*firstIt, *secondIt});
            firstIt++;
            if (firstIt == nums1.end())
            {
                firstIt = nums1.begin();
                secondIt++;
            }
        }
        
        ans.reserve(k);
        for (int i = 0; i < k; i++)
        {
            if (pq.empty())
                return ans;
            pair<int, int> p = pq.top();
            pq.pop();
            ans.push_back({p.first, p.second});
        }
        
        return ans;
    }
};
