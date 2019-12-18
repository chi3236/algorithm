/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
        {
            Node* nullPtr = nullptr;
            return nullPtr;
        }
        Node* headCopy = head;
        while(headCopy)
        {
            Node* copyNode = new Node();
            copyNode -> val = headCopy -> val;
            copyNode -> next = headCopy -> next;
            copyNode -> random = nullptr;
            headCopy -> next = copyNode;
            headCopy = copyNode -> next;
        }
        headCopy = head;  
        while(headCopy)
        {
            if(headCopy -> random)
            {
                headCopy -> next -> random = headCopy -> random -> next;
            }
            headCopy = headCopy -> next -> next;
        }
        headCopy = head;
        Node* answer = head -> next;
        Node* copy = answer;
        while(headCopy)
        {
            headCopy -> next = headCopy -> next -> next;
            if(headCopy -> next)
            {
                copy -> next = headCopy -> next -> next;
            }
            headCopy = headCopy -> next;
            copy = copy -> next;
        }
        return answer;
    }
};