#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
class stack {
private:
    const int INITIAL_SIZE = 1024;

    T* elements;
    int size;
    int current;

    void init_array(int& newSize) {
        T* newArr = new T[newSize];

        for (int i = 0; i < size; i++) {
            newArr[i] = elements[i];
        }

        delete[] elements;
        elements = newArr;
    }

    void enlarge_array() {
        int newSize = size * 2;
        init_array(newSize);
        size = newSize;
    }

    bool is_exceeded_capacity() {
        return current == size;
    }

    void copy_params(const stack& other_stack) {
        this->elements = new T[other_stack.size];
        this->size = other_stack.size;
        this->current = other_stack.current;

        for (int i = 0; i < size; i++) {
            this->elements[i] = other_stack.elements[i];
        }
    }
public:
    stack() {
        size = INITIAL_SIZE;
        elements = new T[size];
        current = 0;
    }

    stack(const stack& other_stack) {
        copy_params(other_stack);
    }

    stack& operator = (const stack& other_stack) {
        delete[] this->elements;
        copy_params(other_stack);
        return *this;
    }

    void push(T elem) {
        elements[current++] = elem;

        if (is_exceeded_capacity()) {
            enlarge_array();
        }
    }

    void pop() {
        if (current == 0) {
            return;
        }

        current--;
    }

    T top() {
        if (current == 0) {
            throw invalid_argument("No elements inside the stack!");
        }

        return elements[current - 1];
    }

    bool empty() {
        return current == 0;
    }

    ~stack() {
        delete[] elements;
    }
};

bool is_opening_bracket(char& c) {
    return c == '[' || c == '(' || c == '{';
}

bool is_closing_bracket(char& c) {
    return c == ']' || c == ')' || c == '}';
}

char return_corresponding_opening_bracket(char& c) {
    if (c == ']')
        return '[';
    if (c == ')')
        return '(';
    if (c == '}')
        return '{';
    return 0;
}

bool is_valid(string s) {
    stack<int> st;
    
    for (char c : s) {
        if (is_closing_bracket(c)) {
            if (st.empty()) {
                return false;
            }

            char opening_bracket = return_corresponding_opening_bracket(c);

            if (st.top() != opening_bracket) {
                return false;
            }

            st.pop();
        }
        else if (is_opening_bracket(c)) {
            st.push(c);
        }
        else {
            return false;
        }
    }

    return st.empty();
}

int main() {
    // string s1 = "()";
    // string s2 = "()[]{}";
    // string s3 = "((()[]{()}))";
    // string s4 = "(({)}))";
    // string s5 = "{(])";

    // cout << is_valid(s1) << endl;
    // cout << is_valid(s2) << endl;
    // cout << is_valid(s3) << endl;
    // cout << is_valid(s4) << endl;
    // cout << is_valid(s5) << endl;

    stack<double> stack_doubles;
    stack_doubles.push(2.34);
    stack_doubles.push(3.6);
    stack_doubles.push(5.1);

    stack<double> copied_doubles(stack_doubles);
    for (int i = 0; i < 3; i++) {
        cout << copied_doubles.top() << endl;
        if (!copied_doubles.empty()) {
            copied_doubles.pop();
        }
    }

    copied_doubles = stack_doubles;
    for (int i = 0; i < 3; i++) {
        cout << copied_doubles.top() << endl;
        if (!copied_doubles.empty()) {
            copied_doubles.pop();
        }
    }

    return 0;
}