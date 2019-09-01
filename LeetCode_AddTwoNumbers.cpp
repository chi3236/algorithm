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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode *answer = new ListNode(0);
        struct ListNode *currPointer = answer;
        int curr = 0;
        int carry = 0;
        while(l1 != NULL && l2 != NULL)
        {
            curr = 0;
            curr = l1->val + l2->val + carry;
            if(curr >= 10)
            {
                carry = 1;
                curr %= 10; 
            }
            else
            {
                carry = 0;
            }
            currPointer -> val = curr;
            if(l1 -> next != NULL || l2 -> next != NULL)
            {
                currPointer -> next = new struct ListNode(0);
                currPointer = currPointer -> next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        struct ListNode *currl = NULL;
        if(l1 != NULL)
        {
            currl = l1;
        }
        if(l2 != NULL)
        {
            currl = l2;
        }
        while(currl != NULL)
        {
            curr = 0;
            curr = currl->val + carry;
            if(curr >= 10)
            {
                carry = 1;
                curr %= 10; 
            }
            else
            {
                carry = 0;
            }
            currPointer -> val = curr;
            if(currl -> next != NULL)
            {
                currPointer -> next = new struct ListNode(0);
                currPointer = currPointer -> next;
            }
            currl = currl->next;
        }
        if(carry > 0)
        {
            currPointer -> next = new struct ListNode(1);
        }
        return answer;
    }
};