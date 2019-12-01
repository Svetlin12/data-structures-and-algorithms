struct letter
{
    int frequency;
    char ch;
    
    letter(int frequency, char ch) : frequency(frequency), ch(ch) {}
    
    bool operator<(const letter& l) const
    {
        return frequency < l.frequency;
    }
};

class Solution {
public:
    string reorganizeString(string S) {
        vector<int> vc(26, 0);
        int size = S.size();
        
        for (int i = 0; i < size; i++)
            vc[S[i] - 'a']++;
        
        priority_queue<letter> pq;
        
        for (int i = 0; i < 26; i++)
            if (vc[i] != 0)
                pq.emplace(vc[i], (char)i + 'a');
        
        letter previous(-1, '?');
        string ans = "";
        while (!pq.empty())
        {
            letter current = pq.top();
            pq.pop();
            ans += current.ch;
            current.frequency--;
            
            if (previous.frequency > 0)
                pq.push(previous);
            
            previous = current;
        }
        
        if (size != ans.size())
            return "";
        else
            return ans;
    }
};
