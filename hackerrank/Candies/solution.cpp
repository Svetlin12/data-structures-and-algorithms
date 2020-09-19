#include <iostream>
#include <vector>

using namespace std;

long candies(int n, vector<int>& arr) {
    vector<int> forwardIteration(n, 1), backwardIteration(n, 1);

    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > arr[i - 1])
            forwardIteration[i] = forwardIteration[i - 1] + 1;

    for (int i = arr.size() - 2; i >= 0; i--)
        if (arr[i] > arr[i + 1])
            backwardIteration[i] = backwardIteration[i + 1] + 1;
            
    long sum = 0;
    for (int i = 0; i < forwardIteration.size(); i++)
        sum += max(forwardIteration[i], backwardIteration[i]);

    return sum;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    cout << candies(n, arr) << endl;


    return 0;
}
