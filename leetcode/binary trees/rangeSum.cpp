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
    void rangeSumBST_rec(TreeNode* root, int L, int R, int& sum)
    {
        if (root)
        {
            if (root->val >= L && root->val <= R)
                sum += root->val;
            rangeSumBST_rec(root->left, L, R, sum);
            rangeSumBST_rec(root->right, L, R, sum);
        }
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) 
    {
        int sum = 0;
        
        rangeSumBST_rec(root, L, R, sum);
        return sum;
    }
};
