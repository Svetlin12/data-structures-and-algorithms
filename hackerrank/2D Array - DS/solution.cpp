#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int hourglassSum(vector<vector<int>>& arr) {
    vector<vector<int>> prefix(6, vector<int>(6));

    for (int i = 0; i < 6; i++) {
        int sum = 0;
        for (int j = 0; j < 6; j++) {
            sum += arr[i][j];
            prefix[i][j] = sum;
        }
    }

    int top = 0, middle = 1, bottom = 2, maxSum = INT_MIN;
    for (int i = 0; i < 4; i++) {
        int columnCnt = 3, currSum = 0;
        for (int j = 0; j < 4; j++) {
            if (columnCnt - 4 < 0) {
                currSum += prefix[top][columnCnt - 1];
                currSum += prefix[bottom][columnCnt - 1];
            }
            else {
                currSum += prefix[top][columnCnt - 1] - prefix[top][columnCnt - 4];
                currSum += prefix[bottom][columnCnt - 1] - prefix[bottom][columnCnt - 4];
            }

            currSum += prefix[middle][columnCnt - 2] - prefix[middle][columnCnt - 3];

            columnCnt += 1;
            maxSum = max(maxSum, currSum);
            currSum = 0;
        }

        top += 1;
        middle += 1;
        bottom += 1;
    }

    return maxSum;
}

int main() {
    vector<vector<int>> arr(6, vector<int>(6));

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            cin >> arr[i][j];

    cout << hourglassSum(arr) << endl;

    return 0;
}
