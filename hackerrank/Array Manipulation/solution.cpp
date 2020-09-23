#include <iostream>
#include <vector>
using namespace std;

// we use the approach where we don't need the actual increasing values, but we need the increases' start and end positions
// the start position is every queries[i][0] and the end position is every (queries[i][1] + 1) in order to account for the inclusive range
// [queries[i][0], queries[i][1]]
// this means that the vector v will contain the total increases and decreases at the end of the first for-loop
// the maximum value will be the accumulated increase value
long arrayManipulation(int n, vector<vector<int>>& queries) {
    long maxNum = -1, sum = 0;
    int start, end, size = queries.size();

    vector<int> v(n + 1);
    
    // for each query
    for (int i = 0; i < size; i++) {
        // start position of the increase(slope)
        start = queries[i][0];
        
        // end position of the increase(slope)
        end = queries[i][1];
        
        // the increase started at this position
        v[start] += queries[i][2];
        
        if (end + 1 <= n)
            v[end + 1] -= queries[i][2]; // the increase ended in this position (meaning that this is a decrease)
    }

    // what's left is to accumulate the resulting slopes
    for (int i = 1; i <= n; i++) {
        sum += v[i];
        if (maxNum < sum)
            maxNum = sum;
    }

    return maxNum;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> queries(m);
    int a, b, k;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> k;
        queries[i].push_back(a);
        queries[i].push_back(b);
        queries[i].push_back(k);
    }

    cout << arrayManipulation(n, queries) << endl;
    return 0;
}
