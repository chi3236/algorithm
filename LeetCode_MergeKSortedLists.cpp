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
            ListNode* min = minHeap.top();
            minHeap.pop();
            ListNode* nextNode = new ListNode(min->val);
            answerCurr->next = nextNode;
            answerCurr = answerCurr -> next;
            if(min -> next != NULL)
            {
                minHeap.push(min->next);
            }
        }
        return answer->next;
    }
};