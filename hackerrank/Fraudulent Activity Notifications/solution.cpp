#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int activityNotifications(vector<int>& expenditure, int d) {
    vector<int> cnt(201, 0);

    for (int i = 0; i < d; i++)
        cnt[expenditure[i]]++;

    int left = floor((d - 1) / 2.0), right = ceil((d - 1) / 2.0), median, notificationsCnt = 0;
    for (int i = d; i < expenditure.size(); i++) {
        if (left == right) {
            for (int j = 0, pos = 0; pos <= left; pos += cnt[j], j++)
                median = j;

            if (expenditure[i] >= 2 * median)
                notificationsCnt++;
        }
        else {
            int leftVal, rightVal;
            for (int j = 0, pos = 0; pos <= left; pos += cnt[j], j++)
                leftVal = j;

            for (int j = 0, pos = 0; pos <= right; pos += cnt[j], j++)
                rightVal = j;

            median = leftVal + rightVal;

            if (expenditure[i] >= median)
                notificationsCnt++;
        }

        cnt[expenditure[i - d]]--;
        cnt[expenditure[i]]++;
        median = 0;
    }

    return notificationsCnt;
}

int main() {
    int n, d;
    cin >> n >> d;

    vector<int> expenditures(n);
    for (int i = 0; i < n; i++)
        cin >> expenditures[i];

    cout << activityNotifications(expenditures, d);

    return 0;
}
