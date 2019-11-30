struct str
{
    int frequency;
    char c;
    
    str(int frequency, char c) : frequency(frequency), c(c) {}
};

struct compare
{
    bool operator()(const str& s1, const str& s2)
    {
        return s1.frequency < s2.frequency;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        vector<int> chars(256, 0);
        
        int size = s.size();
        for (int i = 0; i < size; i++)
        {
            chars[s[i]]++;
        }
        
        priority_queue<str, vector<str>, compare> pq;
        
        for (int i = 0; i < 256; i++)
        {
            if (chars[i] != 0)
            {
                pq.emplace(chars[i], i);
            }
        }
        
        string ans;
        ans.resize(size);
        int i = 0;
        while (!pq.empty())
        {
            str s = pq.top();
            while (s.frequency-- != 0)
                ans[i++] = s.c;
            pq.pop();
        }
        
        return ans;
    }
};
