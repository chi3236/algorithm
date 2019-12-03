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
    TreeNode* build(vector<int>& nums, int s, int e)
    {
        if(s > e)
        {
            return nullptr;
        }
        int rootIdx = (s+e+1)/2;
        TreeNode* root = new TreeNode(nums[rootIdx]);
        root -> left = build(nums, s, rootIdx - 1);
        root -> right = build(nums, rootIdx + 1, e);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size()-1);
    }
};