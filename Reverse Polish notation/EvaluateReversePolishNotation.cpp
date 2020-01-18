class Solution {
public:
    bool checkIfNumber(string s)
    {
        if (s.size() > 1)
            return true;
        else
        {
            if (s == "+" || s == "-" || s == "/" || s == "*")
                return false;
            else
                return true;
        }
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (checkIfNumber(tokens[i]))
                nums.push(stoi(tokens[i]));
            else
            {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                if (tokens[i] == "+")
                    nums.push(num1 + num2);
                else if (tokens[i] == "-")
                    nums.push(num2 - num1);
                else if (tokens[i] == "*")
                    nums.push(num2 * num1);
                else
                    nums.push(num2 / num1);
            }
        }

        return nums.top();
    }
};
