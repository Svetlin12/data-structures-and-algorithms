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
    bool isValidBST_rec(TreeNode* root, TreeNode* min, TreeNode* max)
    {
        if (root == nullptr)
            return 1;
        
        if (min && root->val <= min->val)
            return 0;
        
        if (max && root->val >= max->val)
            return 0;
        
        return isValidBST_rec(root->left, min, root) &&
            isValidBST_rec(root->right, root, max);
    }
    
    bool isValidBST(TreeNode* root) {
        return isValidBST_rec(root, nullptr, nullptr);
    }
};
