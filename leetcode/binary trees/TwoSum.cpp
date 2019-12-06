struct num
{
    int val;
    int ind;
    
    num(int val, int ind) : val(val), ind(ind) {}
    
    bool operator<(const num& n) const
    {
        if (val == n.val)
            return ind < n.ind;
        return val < n.val;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multiset<num> ms;
        
        int size = (int)nums.size();
        for (int i = 0; i < size; i++)
            ms.emplace(nums[i], i);
        
        multiset<num>::iterator it = ms.begin();
        while (it != ms.end())
        {
            num toSearch(target - it->val, -1);
            multiset<num>::iterator additional = ms.lower_bound(toSearch);
            if (additional->ind == it->ind)
            {
                additional++;
            }
            if (additional != ms.end() && additional->val + it->val == target)
            {
                return {it->ind, additional->ind};
            }
            it++;
        }
        
        return {};
    }
};
