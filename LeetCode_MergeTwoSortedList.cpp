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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
     
        if(l1 == NULL && l2 != NULL)
        {
            return l2;
        }
        if(l1 != NULL && l2 == NULL)
        {
            return l1;
        }
        if(l1 == NULL && l2 == NULL)
        {
            ListNode* none;
            return none;
        }
        int first;
        if(l1->val >= l2->val)
        {
            first = l2->val;
            l2 = l2->next;
        }
        else
        {
            first = l1->val;
            l1 = l1->next;
        }
        ListNode* answer = new ListNode(first);
        ListNode* curr = answer;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val >= l2->val)
            {
                ListNode* next = new ListNode(l2->val);
                curr->next = next;
                curr = curr->next;
                l2 = l2->next;
            }
            else
            {
                ListNode* next = new ListNode(l1->val);
                curr->next = next;
                curr = curr->next;
                l1 = l1->next;
            }
        }
        while(l1 != NULL)
        {
            ListNode* next = new ListNode(l1->val);
            curr->next = next;
            curr = curr->next;
            l1 = l1->next;
        }
        while(l2 != NULL)
        {
            ListNode* next = new ListNode(l2->val);
            curr->next = next;
            curr = curr->next;
            l2 = l2->next;
        }
        return answer;
    }
};