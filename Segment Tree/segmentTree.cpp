#include <climits>
#include <vector>
#include <iostream>
using namespace std;

// segment tree used to answer ranged minimum queries in logn time

struct node {
    int val, start, end;

    node *left, *right;

    node(int val = 0, int start = 0, int end = 0, node *left = nullptr, node *right = nullptr) {
        this->val = val;
        this->start = start;
        this->end = end;
        this->left = left;
        this->right = right;
    }
};

class segmentTree {
private:

    node *root;

    void build(node* curr, int start, int end, vector<int>& v) {
        curr->start = start;
        curr->end = end;

        // if we are at a leaf node, then the value we want to assign from the vector is at position start == end
        if (start == end) {
            curr->val = v[start];
            return;
        }

        // create child nodes in the case where we are not at a leaf node
        curr->left = new node;
        curr->right = new node;

        // recurse through the child nodes
        build(curr->left, start, (start+end)/2, v);
        build(curr->right, (start+end)/2 + 1, end, v);

        // when we have created both subtrees, we can assign the value of the current node to the min of the values from his two children
        curr->val = min(curr->left->val, curr->right->val);
    }

    // range minimum query
    int rmq(node* curr, int from, int to) {
        // if the current interval is inside the searched interval or if both intervals match, then return the value of the current node
        if (curr->start >= from && curr->end <= to) {
            return curr->val;
        }
        // if the current interval does not intersect with the searched one, then return a number big enough so that it doesn't play role in the parent's value
        else if (curr->start > to || curr->end < from) {
            return INT_MAX;
        }
        // otherwise the two intervals intersect in some way and we need to traverse through the left and right children
        else {
            return min(rmq(curr->left, from, to), rmq(curr->right, from, to));
        }
    }

    void updateRec(node* curr, int ind, int newVal) {
        // if searched index matches the leaf node, then this is the node we want to update
        if (curr->start == curr->end && curr->start == ind) {
            curr->val = newVal;
            return;
        }
        // if the index is outside the current node's interval, then do nothing
        else if (curr->start > ind || curr->end < ind) {
            return;
        }
        // otherwise, the index is inside the current node's interval, so we need to traverse through the children
        else {
            updateRec(curr->left, ind, newVal);
            updateRec(curr->right, ind, newVal);

            curr->val = min(curr->left->val, curr->right->val);
        }
    }

public:

    segmentTree(vector<int>& v) {
        if (!v.empty()) {
            root = new node;
            build(root, 0, v.size() - 1, v);
        }
    }

    int findMinInInterval(int from, int to) {
        return rmq(root, from, to);
    }

    void update(int ind, int newVal) {
        updateRec(root, ind, newVal);
    }
};

int main() {
    int N, d;
    cin >> N >> d;

    vector<int> arr(N, 0);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    segmentTree s(arr);
    long long sum = 0;
    for (int i = 0; i < N - d + 1; i++) {
        sum += s.findMinInInterval(i, i+d - 1);
    }

    cout << sum << endl;

    return 0;
}
