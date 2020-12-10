#include <iostream>
using namespace std;

/* red-black tree properties:
 1. Every node is either red or black.
 2. The root is black.
 3. Every leaf is black.
 4. If a node is red, then both its children are black.
 5. For each node, all simple paths from the node to descendant leaves contain the same number of black nodes.
 */

enum colorType {
        RED, BLACK
};

struct Node {
    colorType color;
    int key;
    Node *parent, *left, *right; // parent, left and right child

    Node(colorType color, int key, Node *p = nullptr, Node *left = nullptr, Node *right = nullptr) {
        this->color = color;
        this->key = key;
        this->parent = p;
        this->left = left;
        this->right = right;
    }
};

class RedBlackTree {
private:
    Node *root;

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;

        if (y->left != nullptr) {
            y->left->parent = x; // fix child node parent
        }

        y->parent = x->parent;
        
        if (x == x->parent->left) { // fix parent node left or right child
            x->parent->left = y;
        }
        else {
            x->parent->right = y;
        }

        y->left = x;
        x->parent = y;

        return y;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        y->left = x->right;
        if (x->right != nullptr) {
            x->right->parent = y; // fix child node parent
        }
        x->parent = y->parent;
        if (y == y->parent->left) { // fix parent node left or right child
            y->parent->left = x;
        }
        else {
            y->parent->right = x;
        }

        x->right = y;
        y->parent = x;

        return x;
    }

    // fix violation caused by the insertion of new nodes
    void fixViolation(Node *x) {
        Node *parent = nullptr;
        Node *grandParent = nullptr;

        while ((x != root) && (x->color != BLACK) && (x->parent->color == RED)) {
            parent = x->parent; // get parent node
            grandParent = parent->parent; // get grandparent node

            if (parent == grandParent->left) { // case 1: parent of current node is left child
                Node *uncle = grandParent->right; // get uncle node

                if (uncle != nullptr && uncle->color == RED) { // case 1.1: only recoloring required since uncle's color is red
                    grandParent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    x = grandParent; // do the same operation for grandparent node (it being the current node x)
                }
                else {
                    if (x == parent->right) { // case 1.2: x is right child and left rotation is required
                        leftRotate(parent);
                        // after the left rotation x will be parent of it's previous parent so we need to make x the previous
                        // parent so that we get to case 1.3 below as if it we did not go through a left rotation
                        x = parent;
                        parent = x->parent;
                    }

                    // case 1.3: x is left child
                    rightRotate(grandParent);
                    swap(parent->color, grandParent->color);
                    x = parent;
                }
            }
            else { // same as above but with 'left' and 'right' swapped
                Node *uncle = grandParent->left;

                if (uncle != nullptr && uncle->color == RED) {
                    grandParent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    x = grandParent;
                }
                else {
                    if (x == parent->left) {
                        rightRotate(parent);
                        x = parent;
                        parent = x->parent;
                    }

                    leftRotate(grandParent);
                    swap(parent->color, grandParent->color);
                    x = parent;
                }
            }
        }
        
        root->color = BLACK;
    }

    void redBlackInsert(Node *toAdd) {
        Node *y = nullptr, *x = root;

        while (x != nullptr) { // traverse through the tree to determine the parent of the new node
            y = x;
            if (toAdd->key < x->key) {
                x = x->left;
            }
            else {
                x = x->right;
            }
        }

        toAdd->parent = y; // attach parent

        if (y == nullptr) { // if the tree did not contain any nodes prior to the call of the insert, then this will be the root
            root = toAdd;
        }
        // determine whether it will be left or right child of the parent node
        else if (toAdd->key < y->key) {
            y->left = toAdd;
        }
        else {
            y->right = toAdd;
        }



    }

    void printRec(Node *curr) {
        if (curr != nullptr) {
            printRec(curr->left);
            cout << curr->key << " ";
            printRec(curr->right);
        }
    }

public:

    RedBlackTree() {
        root = nullptr;
    }

    void insert(int val) {
        Node *toAdd = new Node(RED, val); // 1 means that the new node will have red color
        redBlackInsert(toAdd);
    }

    void print() {
        printRec(root);
        cout << endl;
    }

};

int main() {

    RedBlackTree r = RedBlackTree();
    r.insert(4);
    r.print();
    r.insert(7);
    r.print();
    r.insert(1);
    r.print();
    r.insert(2);
    r.print();
    r.insert(10);
    r.print();
    r.insert(8);
    r.print();
    
    return 0;
}
