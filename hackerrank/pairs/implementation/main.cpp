#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

int hackerlandRadioTransmitters(vi& x, int k) {
    int size = (int)x.size();

    int numTransmitters = 0;
    int transmitterLoc = 0;
    int i = 0;

    while (i < size)
    {
        numTransmitters++;
        transmitterLoc = x[i] + k;
        while (i < size && x[i] <= transmitterLoc)
            i++;
        transmitterLoc = x[--i] + k;
        while (i < size && x[i] <= transmitterLoc)
            i++;
    }

    return numTransmitters;
}

int main()
{
    int n;
    int k;

    cin >> n;
    cin >> k;

    vi vec(n);

    int number;

    for (int i = 0; i < n; i++)
    {
        cin >> number;
        vec[i] = number;
    }

    sort(vec.begin(), vec.end());
    cout << hackerlandRadioTransmitters(vec, k) << endl;

    return 0;
}