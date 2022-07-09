#include <iostream>

using namespace std;

template <typename T>
struct node {
private:

    node* deep_copy(node* other_node) {
        if (other_node == nullptr) {
            return nullptr;
        }
        
        node* new_node = new node(other_node->data);
        new_node->next = deep_copy(other_node->next);
        return new_node;
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
class list {
private:
    node<T> * head, * tail;
    int size;

    void insert_with_null_head(const T& elem) {
        head = new node<T>(elem);
        tail = head;
    }

    void copy_params(const list& other_list) {
        this->head = new node<T>(other_list.head);
        this->tail = new node<T>(other_list.tail);
        this->size = other_list.size;
    }

    void clear() {
        node<T>* traverse = head;
        while (traverse) {
            node<T>* current = traverse;
            traverse = traverse->next;
            delete current;
        }
        tail = nullptr;
        head = nullptr;
    } 
public:
    list() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    list(const list& other_list) {
        copy_params(other_list);
    }

    list& operator = (const list& other_list) {
        clear();
        copy_params(other_list);
        return *this;
    }

    void insert_last(const T elem) {
        if (head == nullptr) {
            insert_with_null_head(elem);
        }
        else {
            tail->next = new node<T>(elem);
            tail = tail->next;
        }
        size++;
    }

    void insert_front(const T elem) {
        if (head == nullptr) {
            insert_with_null_head(elem);
        }
        else {
            node<T>* new_head = new node<T>(elem);
            new_head->next = head;
            head = new_head;
        }
        size++;
    }

    void delete_front() {
        if (empty()) {
            return;
        }

        node<T>* old_head = head;
        head = head->next;
        delete old_head;

        if (head == nullptr) {
            tail = nullptr;
        }

        size--;
    }

    void delete_last() {
        if (empty()) {
            return;
        }

        if (head == tail) {
            delete_front();
            return;
        }

        node<T>* traverse = head;

        while (traverse->next != tail) {
            traverse = traverse->next;
        }

        delete traverse->next;
        tail = traverse;
        tail->next = nullptr;
        size--;
    }

    int length() {
        return this->size;
    }

    bool empty() {
        return this->size == 0;
    }

    void print() {
        node<T>* traverse = head;

        while (traverse) {
            cout << traverse->data;

            if (traverse->next != nullptr) {
                cout << " -> ";
            }

            traverse = traverse->next;
        }

        cout << endl;
    }

    ~list() {
        clear();
    }
};

int main() {
    list<int> l;
    l.insert_front(1);
    l.insert_last(2);
    l.insert_front(3);
    l.insert_last(4);

    l.print();
    cout << l.length() << endl;

    l.delete_front();
    l.print();

    l.delete_last();
    l.print();

    l.delete_last();
    l.delete_front();
    l.delete_front();

    list<int> l2;
    l2.insert_front(1);
    l2.insert_last(2);
    l2.insert_front(3);
    l2.insert_last(4);

    l2.print();

    list<int> copy_list(l2);
    copy_list.print();
    cout << copy_list.length() << endl;

    list<int> copy_list_2;
    copy_list_2 = l2;
    copy_list_2.print();
    cout << copy_list_2.length() << endl;

    return 0;
}
