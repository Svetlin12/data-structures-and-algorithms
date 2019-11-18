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
    
    bool isMirror(TreeNode* left, TreeNode* right)
    {
        if (!left && !right)
            return true;
        
        if (!left || !right)
            return false;
        
        if (left->val == right->val)
            return isMirror(left->left, right->right) && isMirror(left->right, right->left);
        
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        else
            return isMirror(root->left, root->right);
    }
};
