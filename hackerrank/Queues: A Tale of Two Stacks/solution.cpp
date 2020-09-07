#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
private:
    stack<int> main, secondary;

    void transferMainItems() {
        while (!main.empty()) {
            secondary.push(main.top());
            main.pop();
        }
    }

public:
    void push(int x) {
        main.push(x);
    }

    void pop() {
        if (main.empty() && secondary.empty())
            return;

        if (secondary.empty())
            transferMainItems();

        secondary.pop();
    }

    int front() {
        if (main.empty() && secondary.empty())
            return -1;

        if (secondary.empty())
            transferMainItems();

        return secondary.top();
    }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> type;
        if (type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if (type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    return 0;
}
