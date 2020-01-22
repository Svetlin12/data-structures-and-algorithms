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
    int prev = -1;
    
    void minDiffInBST_rec(TreeNode* root, int& ans)
    {
        if (root)
        {
            minDiffInBST_rec(root->left, ans);
            if (prev != -1)
                ans = min(ans, abs(root->val - prev));
            prev = root->val;
            minDiffInBST_rec(root->right, ans);
        }
    }
    
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        minDiffInBST_rec(root, ans);
        return ans;
    }
};
