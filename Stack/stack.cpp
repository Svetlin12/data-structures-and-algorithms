// stack using vector
class Stack
{
private:

	vi vec;

public:

	void push(int x)
	{
		vec.push_back(x);
	}

	void pop()
	{
		if (!vec.empty())
		{
			vec.pop_back();
		}
	}

	bool empty()
	{
		return vec.empty();
	}

	int top()
	{
		if (vec.empty())
			return -1;
		else
			return vec[(int)vec.size() - 1];
	}

	int size()
	{
		return (int)vec.size();
	}
};
