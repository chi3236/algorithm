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
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        stack<TreeNode*> s;
        while(root || !s.empty())
        {
            while(root)
            {
                s.push(root);
                root = root -> left;
            }
            root = s.top();
            s.pop();
            if(prev && prev -> val >= root -> val)
            {
                return false;
            }
            else
            {
                prev = root;
            }
            root = root -> right;
        }
        return true;
    }
};
