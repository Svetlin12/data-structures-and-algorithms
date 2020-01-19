#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct node
{
	int data;
	node* next;

	node(int data, node* next = nullptr) : data(data), next(next){}
};

class list
{
private:

	node *head, *tail;
	int size;

public:

	list() : head(nullptr), tail(nullptr), size(0){}

	void insertHead(int data)
	{
		if (head == nullptr)
			head = tail = new node(data);
		else
		{
			node* tmp = new node(data);
			tmp->next = head;
			head = tmp;
		}
		size++;
	}

	void insertTail(int data)
	{
		if (head == nullptr)
			head = tail = new node(data);
		else
		{
			node* tmp = new node(data);
			tail->next = tmp;
			tail = tmp;
		}
		size++;
	}

	void add(int data, int pos)
	{
		if (pos < 0 || pos > size)
		{
			insertTail(data);
			cout << "add_last";
		}
		else if (pos == 0)
		{
			insertHead(data);
		}
		else if (pos == size)
		{
			insertTail(data);
		}
		else
		{
			node* tmp = head;
			int counter = 0;
			while (counter++ != pos - 1)
				tmp = tmp->next;

			node* newNode = new node(data);
			newNode->next = tmp->next;
			tmp->next = newNode;
			size++;
		}
	}

	void deleteAtHead()
	{
		if (head == nullptr)
			return;
		node* tmp = head->next;
		delete head;
		head = tmp;

		if (head == nullptr)
			tail = nullptr;
		size--;
	}

	void deleteAtTail()
	{
		if (head == nullptr)
			return;
		else if (head == tail)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			node* traverse = head;
			while (traverse->next != tail)
				traverse = traverse->next;
			delete tail;
			traverse->next = nullptr;
			tail = traverse;
			if (tail == nullptr)
				head = nullptr;
		}
		size--;
	}

	void remove(int pos)
	{
		if (pos < 0 || pos >= size)
		{
			cout << "remove_failed";
			return;
		}
		if (pos == 0)
			deleteAtHead();
		else if (pos == size - 1)
			deleteAtTail();
		else
		{
			node* tmp = head;
			int counter = 0;
			while (counter++ != pos - 1)
			{
				tmp = tmp->next;
			}

			node* toDelete = tmp->next;
			tmp->next = toDelete->next;
			delete toDelete;
			size--;
		}
	}

	void reverse()
	{
		node *current = head, *previous = nullptr, *next = nullptr;
		tail = current;
		while (current != nullptr)
		{
			next = current->next;
			current->next = previous;
			previous = current;
			current = next;
		}
		head = previous;
	}

	void is_palindrome()
	{
		int* values = new int[size];
		node* tmp = head;

		for (int i = 0; i < size; i++, tmp = tmp->next)
			values[i] = tmp->data;

		for (int i = 0; i < size / 2; i++)
			if (values[i] != values[size - i - 1])
			{
				cout << "false";
				delete[] values;
				return;
			}

		delete[] values;
		cout << "true";
	}

	void print()
	{
		node* traverse = head;
		while (traverse != nullptr)
		{
			cout << traverse->data << "#";
			traverse = traverse->next;
		}
	}

	void count(int x)
	{
		node* traverse = head;
		int counter = 0;
		while (traverse != nullptr)
		{
			if (traverse->data == x)
				counter++;
			traverse = traverse->next;
		}
		cout << counter;
	}

	void remove_all(int x)
	{
		node* traverse = head;
		int counter = 0;
		while (traverse != nullptr)
		{
			if (traverse->data == x)
			{
				traverse = traverse->next;
				remove(counter);
			}
			else
			{
				traverse = traverse->next;
				counter++;
			}
		}
	}

	void group(int start, int end)
	{
		if (start < 0 || start >= size)
		{
			cout << "fail_grouping";
			return;
		}

		if (end < 0 || end >= size || end < start)
		{
			cout << "fail_grouping";
			return;
		}

		node* traverse = head;
		int counter = 0;
		while (counter++ != start)
		{
			traverse = traverse->next;
		}

		int newData = 0;
		int range = end - start;

		while (range-- >= 0)
		{
			newData += traverse->data;
			traverse = traverse->next;
			remove(start);
		}

		add(newData, start);
	}
};

int main() {
	int cases;
	std::cin >> cases;
	for (int i = 0; i < cases; i++) {
		list ll;
		int ops;
		std::string op;
		std::cin >> ops;
		for (int j = 0; j < ops; j++) {
			std::cin >> op;

			if (op == "count") {
				int arg1;
				std::cin >> arg1;
				ll.count(arg1);
			}

			if (op == "add") {
				int arg1, arg2;
				std::cin >> arg1 >> arg2;
				ll.add(arg1, arg2);
			}

			if (op == "print") {
				ll.print();
			}

			if (op == "remove") {
				int arg1;
				std::cin >> arg1;
				ll.remove(arg1);
			}

			if (op == "reverse") {
				ll.reverse();
			}

			if (op == "remove_all") {
				int arg1;
				std::cin >> arg1;
				ll.remove_all(arg1);
			}

			if (op == "group") {
				int arg1, arg2;
				std::cin >> arg1 >> arg2;
				ll.group(arg1, arg2);
			}

			if (op == "is_palindrom") {
				ll.is_palindrome();
			}
		}

		std::cout << std::endl;

	}
	return 0;
}
