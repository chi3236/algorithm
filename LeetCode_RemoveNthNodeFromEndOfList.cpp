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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* answer;
        vector<ListNode*> memory;
        if(head == NULL)
        {
            return answer;
        }
        answer = head;
        while(head != NULL)
        {
            memory.push_back(head);
            head = head->next;
        }
        if(n < memory.size())
        {
            memory[memory.size() - n - 1] -> next = memory[memory.size() - n] -> next;
        }
        else
        {
            answer = answer -> next;
        }
        return answer;
    }
};