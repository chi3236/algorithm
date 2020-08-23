/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *oneStep = head;
        ListNode *twoStep = head;
        while(twoStep && twoStep -> next)
        {
            oneStep = oneStep -> next;
            twoStep = twoStep -> next -> next;
            if(oneStep == twoStep)
            {
                return true;
            }
        }
        return false;
    }
};