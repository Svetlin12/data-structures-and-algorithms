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
    TreeNode* attach(vector<int>& nums, int from, int to)
    {
        if (from > to || from < 0 || to >= (int)nums.size())
            return nullptr;
        
        int middle = (from + to) / 2;
        int leftPortion = middle - 1;
        int rightPortion = middle + 1;
        TreeNode* node = new TreeNode(nums[middle]);
        node->left = attach(nums, from, leftPortion);
        node->right = attach(nums, rightPortion, to);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = (int)nums.size();
        
        if (size == 0)
            return nullptr;
        
        int middle = size / 2;
        
        TreeNode* root = new TreeNode(nums[middle]);
        int leftPortion = middle - 1;
        int rightPortion = middle + 1;
        
        root->left = attach(nums, 0, leftPortion);
        root->right = attach(nums, rightPortion, size - 1);
        return root;
    }
};
