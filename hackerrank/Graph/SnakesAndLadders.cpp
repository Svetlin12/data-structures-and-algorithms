#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int bfs(vector<unordered_map<int, int>>& table, int start)
{
    queue<int> q;
    vector<bool> visited(101);
    q.push(start);

    visited[start] = true;
    int level = 0, size = 1, curr;

    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        size--;

        for (auto child : table[curr])
        {
            if (child.second == 100)
                return level + 1;
            if (!visited[child.second])
            {
                visited[child.second] = true;
                q.push(child.second);
            }
        }

        if (size == 0)
        {
            level++;
            size = q.size();
        }
    }

    if (curr < 100)
        return -1;

    return level;
}

int main()
{
    int cases;
    cin >> cases;

    for (int j = 0; j < cases; j++)
    {
        int i;
        vector<unordered_map<int, int>> table;
        table.resize(101);

        for (i = 1; i < 101; i++)
        {
            for (int j = 1; j < 7; j++)
            {
                if (i + j > 100)
                    break;
                table[i][j] = i + j;
            }
        }

        int snakes, ladders;
        cin >> ladders;
        pair<int, int> p;

        for (i = 0; i < ladders; i++)
        {
            cin >> p.first >> p.second;
            for (int j = 0; j < 7; j++)
            {
                if (p.first - j < 0)
                    break;
                table[p.first - j][j] = p.second;
            }
        }

        cin >> snakes;

        for (i = 0; i < snakes; i++)
        {
            cin >> p.first >> p.second;
            for (int j = 0; j < 7; j++)
            {
                if (p.first - j < 0)
                    break;
                table[p.first - j][j] = p.second;
            }
        }

        cout << bfs(table, 1) << "\n";
    }

    return 0;
}
