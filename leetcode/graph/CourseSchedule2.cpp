class Solution {
private:

    vector<vector<int>> graph;
    stack<int> s;
    vector<bool> visited;
    vector<bool> recStack;

    void topSortUtil(int curr, bool& isCycle)
    {
        visited[curr] = true;
        recStack[curr] = true;
        for (auto child : graph[curr])
        {
            if (recStack[child])
                isCycle = true;
            else if (!visited[child])
                topSortUtil(child, isCycle);
        }
        recStack[curr] = false;

        s.push(curr);
    }

    void topSort(vector<int>& result)
    {
        int size = (int)visited.size();
        bool isCycle = false;
        for (int i = 0; i < size; i++)
        {
            if (!visited[i])
            {
                topSortUtil(i, isCycle);
                if (isCycle)
                {
                    result.resize(0);
                    return;
                }
            }
        }

        while (!s.empty())
        {
            result.push_back(s.top());
            s.pop();
        }
    }

public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        result.reserve(numCourses);
        visited.resize(numCourses, 0);
        recStack.resize(numCourses, 0);
        int size = (int)prerequisites.size();
        graph.assign(numCourses, vector<int>(0));
        for (int i = 0; i < size; i++)
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);

        topSort(result);
        return result;
    }
};
