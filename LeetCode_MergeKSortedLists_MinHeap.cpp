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
    struct compare
    {
        bool operator()(ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* answer = new ListNode(0);
        ListNode* answerCurr = answer;
        if(lists.size() == 0)
        {
            return nullptr;
        }
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        for(int i = 0; i < lists.size(); i++)
        {
            if(lists[i] != NULL)
            {
                minHeap.push(lists[i]);
            }
        }
        while(!minHeap.empty())
        {
            answerCurr->next = new ListNode(minHeap.top()->val);
            answerCurr = answerCurr -> next;
            if(minHeap.top() -> next != NULL)
            {
                minHeap.push(minHeap.top() -> next);
            }
            minHeap.pop();
        }
        return answer->next;
    }
};