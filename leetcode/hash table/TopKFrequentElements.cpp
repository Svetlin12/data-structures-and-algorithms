class Solution {
public:
    struct myPair
    {
        int first;
        int second;
        myPair(int first, int second) : first(first), second(second) {}
    };

    struct cmp
    {
        bool operator()(const myPair& m1, const myPair& m2) const
        {
            if (m1.first == m2.first)
            {
                if (m1.second < m2.second)
                    return false;
            }
            return m1.first < m2.first;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        vector<int> ans;
        int size = (int)nums.size();
        for (int i = 0; i < size; i++)
            um[nums[i]]++;

        multiset<myPair, cmp> m;
        for (auto& kvp : um)
        {
            myPair mp(kvp.second, kvp.first);
            m.insert(mp);
        }

        auto traverse = m.rbegin();
        for (int i = 0; i < k && traverse != m.rend(); i++, traverse++)
            ans.push_back(traverse->second);

        return ans;
    }
};
