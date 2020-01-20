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
    
    vector<int> tree1, tree2;
    
public:
    void convertTreeToVec(TreeNode* root, vector<int>& to)
    {
        if (root)
        {
            convertTreeToVec(root->left, to);
            to.push_back(root->val);
            convertTreeToVec(root->right, to);
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        convertTreeToVec(root1, tree1);
        convertTreeToVec(root2, tree2);
        int size1 = (int)tree1.size();
        int size2 = (int)tree2.size();
        vector<int> ans(size1 + size2);
        
        int i = 0, j = 0, k = 0;
        while (i < size1 && j < size2)
        {
            if (tree1[i] < tree2[j])
                ans[k++] = tree1[i++];
            else
                ans[k++] = tree2[j++];
        }
        
        while (i < size1)
            ans[k++] = tree1[i++];
        
        while (j < size2)
            ans[k++] = tree2[j++];
        
        return ans;
    }
};
