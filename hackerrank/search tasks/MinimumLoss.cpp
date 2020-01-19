#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<long long, int>> vec(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i].first;
        vec[i].second = i;
    }

    sort(vec.begin(), vec.end());

    long long minCost = INT_MAX;
    for (int i = 0; i < n - 1; i++)
        if (vec[i].second > vec[i + 1].second)
            minCost = min(minCost, (long long)vec[i + 1].first - vec[i].first);

    cout << minCost;

    return 0;
}
