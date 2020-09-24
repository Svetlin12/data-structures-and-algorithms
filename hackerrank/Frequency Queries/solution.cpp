#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // values: value - count of occurrences
    // count: count of occurrence - its count
    unordered_map<long, long> values, count;
    int q;
    cin >> q;

    short operation;
    int val;
    for (int i = 0; i < q; i++) {
        cin >> operation >> val;
        if (operation == 1) { // when we add an element one occurrence's count becomes less and another's becomes more
            count[values[val]]--;
            values[val]++;
            count[values[val]]++;
        }
        else if (operation == 2) { // when we remove and element one occurrence's count becomes less and another's becomes more
            if (values[val]) {
                count[values[val]]--;
                values[val]--;
                count[values[val]]++;
            }
        }
        else {
            if (count[val]) {
                cout << 1 << endl;
            }
            else
                cout << 0 << endl;
        }
    }

    return 0;
}
