class Solution {
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie)
    {
        if(ps > pe)
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[ps]);
        int rootPos = find(inorder.begin() + is, inorder.begin() + ie, preorder[ps]) - inorder.begin();
        //we have (rootPos - is) elements in left tree, and (ie-rootPos) elements in right tree
        root -> left = build(preorder, inorder, ps + 1, ps + (rootPos - is), is, rootPos - 1);
        root -> right = build(preorder, inorder, ps + (rootPos - is) + 1, pe, rootPos + 1, ie);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};