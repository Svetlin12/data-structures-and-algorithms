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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        
        if (!root)
            return ans;
        
        queue<TreeNode*> q;
        TreeNode* tmp = root;
        q.push(tmp);
        
        
        int size = 1;
        while (!q.empty())
        {
            int maxVal = INT_MIN;
            for (int i = 0; i < size; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                maxVal = max(maxVal, curr->val);
                
                if (curr->left)
                    q.push(curr->left);
                
                if (curr->right)
                    q.push(curr->right);
            }
            ans.push_back(maxVal);
            size = q.size();
        }
        
        return ans;
    }
};
