/ implementation of sparse table for answering range minimum queries
// time complexity of precomputation is O(NlogN) where N is the size of the initial array
// note that (1 << j) means 2^j

// maxN - max array range

// k - max power to compute

// precompute logarithms so that we have them on the go instead of recalculating them on each query
vector<int> buildLog(const int maxN) {
    vector<int> log(maxN + 1);
    log[1] = 0;
    for (int i = 2; i <= maxN; i++) {
        log[i] = log[i/2] + 1;
    }

    return log;
}

// build sparse table
// note that since its vector of vectors, the rows are the second dimension and the columns are the first!
// we want to build the sparse table so that the number of the row is the starting position and the number of column is the length
// of the interval (2^j) we have computed the minimum, for instance:
// sparseTable[1][2] means that we have an interval starting from index 2 and with length 2^1=2
vector<vector<int>> buildSparseTable(const int maxN, const int k, vector<int>& arr) {
    vector<vector<int>> sparseTable(k, vector<int>(maxN));

    int n = arr.size();
    for (int i = 0; i < n; i++) {
        sparseTable[0][i] = arr[i];
    }

    for (int j = 1; j <= k; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            sparseTable[j][i] = min(sparseTable[j-1][i] , sparseTable[j-1][i + (1 << (j-1))]);
        }
    }

    return sparseTable;
}

// to get minimum we first find the biggest power of two that is smaller than the interval length
// if the interval length is an even number, then biggestPowerOfTwo will be the exact length since it's a power of two and then we just find that interval in the sparse table and return the minimum
// if the interval length is an odd number, then biggestPowerOfTwo will cover all but one element, so we need to take two intervals and return the minimum in those two:
// one is from L with size biggestPowerOfTwo and the other one ends at the last element of the interval with length biggestPowerOfTwo
int findMinInInterval(int L, int R, vector<vector<int>>& sparseTable, vector<int>& log) {
    int biggestPowerOfTwo = log[R - L + 1];
    return min(sparseTable[biggestPowerOfTwo][L], sparseTable[biggestPowerOfTwo][R - (1 << biggestPowerOfTwo) + 1]);
}
