/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root)
        {
            q.push(root);
        }
        while(!q.empty())
        {
            for(int i = q.size(); i > 0; i--)
            {
                Node* curr = q.front();
                q.pop();
                if(i != 1)
                {
                    curr -> next = q.front();
                }
                else
                {
                    Node* nullNode = nullptr;
                    curr -> next = nullNode;
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
        }
        return root;
    }
};
