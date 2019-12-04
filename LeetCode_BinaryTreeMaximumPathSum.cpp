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
    int maxValue = INT_MIN;
    int traverse(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        int left = max(0, traverse(root -> left));
        int right = max(0, traverse(root -> right));
        maxValue = max(maxValue, left + right + root -> val);
        return max(left, right) + root -> val;
    }
    
    int maxPathSum(TreeNode* root) {
        traverse(root);
        return maxValue;
    }
};