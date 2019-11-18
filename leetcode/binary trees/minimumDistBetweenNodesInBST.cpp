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
    void minDiffInBST_rec(TreeNode* root, TreeNode*& predecessor, int& ans)
    {
        if (root)
        {
            minDiffInBST_rec(root->left, predecessor, ans);
            if (predecessor != nullptr)
                ans = min(abs(root->val - predecessor->val), ans);
            predecessor = root;
            minDiffInBST_rec(root->right, predecessor, ans);
        }
    }
    
    int minDiffInBST(TreeNode* root) {
        TreeNode* predecessor = nullptr;
        int ans = 101;
        minDiffInBST_rec(root, predecessor, ans);
        return ans;
    }
};
