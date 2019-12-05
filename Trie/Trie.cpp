#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Node
{
    bool isEnd = false;
    map<char, Node*> children;
};

struct Trie
{
private:

    Node* root = new Node;

    void dfs(Node* curr, string& prefix)
    {
        if (curr->isEnd)
            cout << prefix << endl;
        for (pair<char, Node*> kvp : curr->children)
        {
            prefix.push_back(kvp.first);
            dfs(kvp.second, prefix);
            prefix.pop_back();
        }
    }

public:

    void insert(const string& str)
    {
        int n = str.size();
        Node* curr = root;
        for (int i = 0; i < n; i++)
        {
            if (!curr->children.count(str[i]))
                curr->children[str[i]] = new Node;
            curr = curr->children[str[i]];
        }
        curr->isEnd = true;
    }

    void print_words(string prefix)
    {
        Node *curr = root;
        int n = prefix.size();

        for (int i = 0; i < n; i++)
        {
            if (!curr->children.count(prefix[i]))
                return;
            curr = curr->children[prefix[i]];
        }

        dfs(curr, prefix);
    }
};

int main()
{
    Trie t;

    t.insert("beginning");
    t.insert("beg");
    t.insert("bewildered");
    t.insert("alter");
    t.insert("altar");
    t.insert("world");
    t.print_words("be");
    t.print_words("beg");
    t.print_words("alt");
    t.print_words("w");
    t.print_words("m");

   return 0;
}
