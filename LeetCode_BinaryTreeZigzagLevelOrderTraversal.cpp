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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        queue<TreeNode*> q;
        stack<TreeNode*> s;
        bool left = true;
        if(root)
        {
            q.push(root);
        }
        while(!q.empty())
        {
            vector<int> currLev;
            for(int i = q.size(); i > 0; i--)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(left)
                {
                    currLev.push_back(curr -> val);
                }
                else
                {
                    currLev.insert(currLev.begin(), curr -> val);
                }
                if(curr -> left)
                {
                    q.push(curr -> left);
                }
                if(curr -> right)
                {
                    q.push(curr -> right);
                }
            }
            if(!currLev.empty())
            {
                answer.push_back(currLev);
            }
            if(left)
            {
                left = false;
            }
            else
            {
                left = true;
            }
        }
        return answer;
    }
};