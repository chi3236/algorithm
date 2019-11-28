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
    bool traversal(TreeNode* left, TreeNode* right)
    {
        if(!left && !right)
        {
            return true;
        }
        if(!left || !right)
        {
            return false;
        }
        return (left -> val == right -> val) && traversal(left -> left, right -> right) && traversal(left -> right, right -> left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root)
        {
            return true;
        }
        return traversal(root -> left, root -> right);
    }
};
