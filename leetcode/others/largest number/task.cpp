bool myCompare(const string& s1, const string& s2)
{
    return s1 + s2 > s2 + s1;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int size = (int)nums.size();
        vector<string> stringNums(size);
        bool areOnly0s = true;
        for (int i = 0; i < size; i++)
        {
            stringNums[i] = to_string(nums[i]);
            if (nums[i] != 0)
                areOnly0s = false;
        }
        
        if (areOnly0s)
            return "0";
        
        sort(stringNums.begin(), stringNums.end(), myCompare);
        
        string ans = "";
        for (int i = 0; i < size; i++)
            ans += stringNums[i];
        
        return ans;
    }
};
