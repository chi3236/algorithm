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
    int maxDepth(TreeNode* root) {
        int answer = 0;
        queue<TreeNode*> q;
        if(root)
        {
            q.push(root);
        }
        while(!q.empty())
        {
            for(int i = q.size(); i > 0; i--)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr -> left)
                {
                    q.push(curr -> left);
                }
                if(curr -> right)
                {
                    q.push(curr -> right);
                }
            }
            answer++;
        }
        return answer;
    }
};