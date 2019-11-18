/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int size(ListNode* head)
    {
        int size = 0;
        ListNode* tmp = head;
        while (tmp != nullptr)
        {
            tmp = tmp->next;
            size++;
        }
        return size;
    }
    
    TreeNode* attach(vector<int>& vec, int from, int to)
    {
       if (from > to || from < 0 || to >= (int)vec.size())
           return nullptr;
        
        int middle = (from + to) / 2;
        int left = middle - 1;
        int right = middle + 1;
        
        TreeNode* node = new TreeNode(vec[middle]);
        node->left = attach(vec, from, left);
        node->right = attach(vec, right, to);
        
        return node;
    }
    
    vector<int> convertToVector(ListNode* head, int size)
    {
        vector<int> vec(size);
        int i = 0;
        ListNode* tmp = head;
        while (tmp != nullptr)
        {
            vec[i++] = tmp->val;
            tmp = tmp->next;
        }
        return vec;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        int n = size(head);
        if (n == 0)
            return nullptr;
        vector<int> vec = convertToVector(head, n);
        int middle = n / 2;
        int left = middle - 1;
        int right = middle + 1;
        
        TreeNode* root = new TreeNode(vec[middle]);
        root->left = attach(vec, 0, left);
        root->right = attach(vec, right, n - 1);
        
        return root;
    }
};
