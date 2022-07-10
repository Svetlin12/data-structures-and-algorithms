#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

template <typename T>
struct node {
private:

    node* deep_copy(node* other_node) {
        if (other_node == nullptr) {
            return nullptr;
        }

        node* curr_node = new node(other_node->data);
        curr_node->next = deep_copy(other_node->next);
        return curr_node;
    }

public:
    T data;
    node* next;

    node(T data) : data(data), next(nullptr) {}
    
    node(node* other_node) {
        this->data = other_node->data;
        this->next = deep_copy(other_node->next);
    }
};

template <typename T>
class queue {
private:

    const string NO_ELEMENTS_EXC_MESSAGE = "There are no elements in the queue!";

    node<T>* first;
    node<T>* back;
    int size;

    void clear() {
        node<T>* traverse = first;

        while (traverse) {
            node<T>* to_delete = traverse;
            traverse = traverse->next;
            delete to_delete;
        }

        first = nullptr;
        back = nullptr;
        size = 0;
    }

    void copy_params_from_queue(const queue& other_queue) {
        this->first = new node<T>(other_queue.first);
        this->back = new node<T>(other_queue.back);
        this->size = other_queue.size;
    }

public:

    queue() : size(0), first(nullptr), back(nullptr) {}

    queue(const queue& other_queue) {
        copy_params_from_queue(other_queue);
    }

    queue& operator = (const queue& other_queue) {
        clear();
        copy_params_from_queue(other_queue);
        return *this;
    }

    void push(T data) {
        if (back == nullptr) {
            back = new node<T>(data);
            first = back;
        }
        else {
            back->next = new node<T>(data);
            back = back->next;
        }
        size++;
    }

    void pop() {
        if (empty()) {
            throw invalid_argument(NO_ELEMENTS_EXC_MESSAGE);
        }

        node<T>* old_front = first;
        first = first->next;
        delete old_front;

        if (first == nullptr) {
            back = nullptr;
        }

        size--;
    }

    T front() {
        if (empty()) {
            throw invalid_argument(NO_ELEMENTS_EXC_MESSAGE);
        }

        return first->data;
    }

    bool empty() {
        return this->size == 0;
    }

    int length() {
        return this->size;
    }

    void print() {
        node<T>* traverse = first;

        while (traverse) {
            cout << traverse->data;

            if (traverse->next) {
                cout << " -> ";
            }

            traverse = traverse->next;
        }

        cout << endl << "Size is: " << size << endl;
    }

    ~queue() {
        clear();
    }
};

int main() {
    queue<string> q;
    q.push("this");
    q.push("is");
    q.push("an");
    q.push("implementation");
    q.push("of");
    q.push("queue");

    q.print();
    cout << "Front: " << q.front() << endl << endl;

    q.pop();

    q.print();
    cout << "Front: " << q.front() << endl << endl;

    queue<string> q2;
    //q2.pop();
    //q2.front();

    queue<string> copied_q = queue<string>(q);
    copied_q.print();
    cout << "Front: " << copied_q.front() << endl << endl;

    copied_q.pop();
    copied_q.print();
    cout << "Front: " << copied_q.front() << endl << endl;

    queue<string> another_q;
    another_q = q;
    another_q.print();
    cout << "Front: " << another_q.front() << endl << endl;

    another_q.pop();
    another_q.print();
    cout << "Front: " << another_q.front() << endl << endl;

    q.print();
    cout << "Front: " << q.front() << endl;

    return 0;
}
