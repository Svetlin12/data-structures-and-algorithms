bool lexicographicalOrder(string::iterator firstBeg, string::iterator firstEnd, string::iterator secondBeg, string::iterator secondEnd)
{
    while (firstBeg != firstEnd)
    {
        if (secondBeg == secondEnd || *secondBeg < *firstBeg)
            return false;
        else if (*firstBeg < *secondBeg)
            return true;
        ++firstBeg;
        ++secondBeg;
    }
    return secondBeg != secondEnd;
}

struct word
{
    int frequency;
    string s;
    
    word(int frequency, string s) : frequency(frequency), s(s) {}
    
    bool operator<(word& w)
    {
        if (frequency == w.frequency)
            return lexicographicalOrder(s.begin(), s.end(), w.s.begin(), w.s.end());
        return frequency > w.frequency;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<string, vector<string>, greater<string>> pq;
	    multiset<string> ms;

	    int size = (int)words.size();
	    for (int i = 0; i < size; i++)
	    {
		    ms.insert(words[i]);
		    pq.push(words[i]);
	    }

	    vector<word> ans;
	    ans.reserve(k);

	    while (!pq.empty())
	    {
		    string top = pq.top();
		    pq.pop();
		    if (ms.find(top) != ms.end())
		    {
			    word w(ms.count(top), top);
			    ans.push_back(w);
			    ms.erase(top);
		    }
	    }

	    sort(ans.begin(), ans.end());

	    vector<string> vec;
	    size = (int)ans.size();
	    vec.resize(k);

	    for (int i = 0; i < k; i++)
	    {
		    vec[i] = ans[i].s;
	    }

	    return vec;
    }
};
