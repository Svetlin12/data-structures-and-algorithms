#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

struct Point
{
    long long time;
    int type;

    Point(long long time, int type) : time(time), type(type) {}

    bool operator<(const Point& p) const
    {
        if (time == p.time)
            return type < p.type;
        return time < p.time;
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    multiset<Point> s;
    unordered_map<long long, int> queriesAns;

    long long input;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> input;
        if (i % 2 == 0)
            s.emplace(input, -1);
        else
            s.emplace(input, 1);
    }

    vector<long long> queries;
    queries.reserve(q);

    for (int i = 0; i < q; i++)
    {
        cin >> input;
        s.emplace(input, 0);
        queries.push_back(input);
    }

    auto it = s.begin();
    int counterIntervals = 0;
    while (it != s.end())
    {
        if (it->type == -1)
            counterIntervals++;
        else if (it->type == 1)
            counterIntervals--;
        else
            queriesAns[it->time] = counterIntervals;
        it++;
    }

    for (int i = 0; i < q; i++)
    {
        cout << queriesAns[queries[i]] << " ";
    }

    return 0;
}
