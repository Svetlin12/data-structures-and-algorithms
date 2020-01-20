class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = (int)height.size() - 1;
        int maxAr = INT_MIN;
        
        while (left < right)
        {
            maxAr = max(maxAr, min(height[left], height[right]) * (right - left));
            
            if (height[left] > height[right])
                right--;
            else
                left++;
        }
        return maxAr;
    }
};
