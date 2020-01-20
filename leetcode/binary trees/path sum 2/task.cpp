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
    
    vector<vector<int>> paths;
    vector<int> currentPath;
    
public:
    void traversal(TreeNode* root, int sum)
    {
        if (root)
        {
            if (!root->left && !root->right && sum == root->val)
            {
                currentPath.push_back(root->val);
                paths.push_back(currentPath);
                currentPath.pop_back();
                return;
            }
            
            currentPath.push_back(root->val);
            traversal(root->left, sum - root->val);
            traversal(root->right, sum - root->val);
            currentPath.pop_back();
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root)
            traversal(root, sum);
        return paths;
    }
};
