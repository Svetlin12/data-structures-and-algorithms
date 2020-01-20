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
private:
    
    vector<int> view;
    int maxHeight = INT_MIN;
    
public:
    
    void inorderTraversal(TreeNode* root, int height)
    {
        if (root)
        {
            if (height > maxHeight)
            {
                maxHeight = height;
                view.push_back(root->val);
            }
            inorderTraversal(root->right, height + 1);
            inorderTraversal(root->left, height + 1);
        }
    }
    
    vector<int> rightSideView(TreeNode* root) {
        inorderTraversal(root, 0);
        return view;
    }
};
