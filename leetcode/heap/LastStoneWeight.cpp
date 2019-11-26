class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        
        int size = (int)stones.size();
        
        for (int i = 0; i < size; i++)
            maxHeap.push(stones[i]);
        
        while (!maxHeap.empty())
        {
            int maxStone = maxHeap.top();
            maxHeap.pop();
            
            if (maxHeap.empty())
                return maxStone;
            
            int nextMaxStone = maxHeap.top();
            maxHeap.pop();
            
            if (maxStone - nextMaxStone > 0)
                maxHeap.push(maxStone - nextMaxStone);
        }
        
        return 0;
    }
};
