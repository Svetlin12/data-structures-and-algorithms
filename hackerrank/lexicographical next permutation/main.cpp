#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string word;
        cin >> word;

        int len = word.size(), j = len - 2;
        while (j >= 0 && word[j] >= word[j + 1])
            j--;

        if (j < 0)
        {
            cout << "no answer\n";
            continue;
        }

        int left = j + 1, right = len - 1, ind = INT_MIN;
        while (left <= right)
        {
            int middle = (left + right) / 2;
            if (word[middle] > word[j])
            {
                ind = max(middle, ind);
                left = middle + 1;
            }
            else
                right = middle - 1;
        }

        swap(word[j], word[ind]);
        reverse(word.begin() + j + 1, word.end());
        cout << word << "\n";
    }

    return 0;
}
