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
    void convertToVec(TreeNode* root, vector<int>& v)
    {
        if (root)
        {
            convertToVec(root->left, v);
            v.push_back(root->val);
            convertToVec(root->right, v);
        }
    }
    
    bool findTarget(TreeNode* root, int k) 
    {
        vector<int> v;
        v.reserve(1000);
        convertToVec(root, v);
        
        unsigned int start = 0;
        unsigned int end = (unsigned int)v.size() - 1;
        while (start < end)
        {
            if (v[start] + v[end] == k)
                return true;
            else if (v[start] + v[end] > k)
                end--;
            else
                start++;
        }
        
        return false;
    }
};
