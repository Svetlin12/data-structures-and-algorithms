class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int size = (int)nums.size();
        
        for (int i = 0; i < size; i++)
            pq.push(nums[i]);
        
        for (int i = 0; i < k - 1; i++)
            pq.pop();
        
        return pq.top();
    }
};
