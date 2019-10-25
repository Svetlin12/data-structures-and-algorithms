#include <iostream>
#include <vector>
#include <string>
using namespace std;

string balancedSums(vector<int>& arr) 
{
    int size = (int)arr.size();
    unsigned int sum1 = 0;
    unsigned int sum2 = 0;

    for (int i = 0; i < size; i++)
    {
        sum2 += arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        sum2 -= arr[i];
        if (sum1 == sum2)
            return "YES";
        sum1 += arr[i];
    }

    return "NO";
}

int main()
{
    int T;
    cin >> T;

    vector<string> answers(T);

    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        vector<int> vec(N);

        int number;
        for (int j = 0; j < N; j++)
        {
            cin >> number;
            vec[j] = number;
        }

        answers[i] = balancedSums(vec);
    }

    for (int i = 0; i < T; i++)
        cout << answers[i] << endl;

    return 0;
}
