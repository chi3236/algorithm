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
    vector<int> answer;
public:
    void traversal(TreeNode* root)
    {
        if(root -> left != NULL)
        {
            traversal(root -> left);
        }
        answer.push_back(root -> val);
        if(root -> right != NULL)
        {
            traversal(root -> right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL)
        {
            return answer;
        }
        traversal(root);
        return answer;
    }
};
