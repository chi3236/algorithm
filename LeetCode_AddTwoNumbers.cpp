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
        int end = 0;
        struct ListNode *answer = new ListNode(0);
        struct ListNode *answerPointer = answer;
        struct ListNode *currl1 = l1;
        struct ListNode *currl2 = l2;
        int carry = 0;
        while(true)
        {
            if(currl1->next == NULL || currl2->next == NULL)
            {
                if(currl1->next == NULL && currl2->next != NULL)
                {
                    end = 1;
                }
                else if(currl1->next != NULL && currl2->next == NULL)
                {
                    end = 2;
                }
                else if(currl1->next == NULL && currl2->next == NULL)
                {
                    end = 3;
                }
                break;
            }
            int curr = 0;
            curr = currl1->val + currl2->val + carry;
            if(curr >= 10)
            {
                carry = 1;
                curr %= 10; 
            }
            else
            {
                carry = 0;
            }
            answerPointer -> val = curr;
            answerPointer -> next = new struct ListNode(0);
            answerPointer = answerPointer -> next;
            currl1 = currl1->next;
            currl2 = currl2->next;
        }
        switch(end)
        {
            case(1):
            {
                int curr = carry + currl1->val + currl2->val;
                if(curr >= 10)
                {
                    carry = 1;
                    curr %= 10;
                }
                else
                {
                    carry = 0;
                }
                answerPointer -> val = curr;
                answerPointer -> next = new struct ListNode(0);
                answerPointer = answerPointer -> next;
                currl2 = currl2->next;
                while(currl2->next != NULL)
                {
                    curr = carry + currl2->val;
                    if(curr >= 10)
                    {
                        carry = 1;
                        curr %= 10;
                    }
                    else
                    {
                        carry = 0;
                    }
                    answerPointer -> val = curr;
                    answerPointer -> next = new struct ListNode(0);
                    answerPointer = answerPointer -> next;
                    currl2 = currl2->next;
                }
                curr = carry + currl2->val;
                if(curr >= 10)
                {
                    carry = 1;
                    curr %= 10;
                }
                else
                {
                    carry = 0;
                }
                answerPointer -> val = curr;
                if(carry == 1)
                {
                    answerPointer -> next = new struct ListNode(1);
                }
                break;
            }
            case(2):
            {
                int curr = carry + currl1->val + currl2->val;
                if(curr >= 10)
                {
                    carry = 1;
                    curr %= 10;
                }
                else
                {
                    carry = 0;
                }
                answerPointer -> val = curr;
                answerPointer -> next = new struct ListNode(0);
                answerPointer = answerPointer -> next;
                currl1 = currl1->next;
                while(currl1->next != NULL)
                {
                    curr = carry + currl1->val;
                    if(curr >= 10)
                    {
                        carry = 1;
                        curr %= 10;
                    }
                    else
                    {
                        carry = 0;
                    }
                    answerPointer -> val = curr;
                    answerPointer -> next = new struct ListNode(0);
                    answerPointer = answerPointer -> next;
                    currl1 = currl1->next;
                }
                curr = carry + currl1->val;
                if(curr >= 10)
                {
                    carry = 1;
                    curr %= 10;
                }
                else
                {
                    carry = 0;
                }
                answerPointer -> val = curr;
                if(carry == 1)
                {
                    answerPointer -> next = new struct ListNode(1);
                }
                break;
            }
            case(3):
            {
                int curr = carry + currl1->val + currl2->val;
                if(curr >= 10)
                {
                    carry = 1;
                    curr %= 10;
                }
                else
                {
                    carry = 0;
                }
                answerPointer -> val = curr;
                if(carry == 1)
                {
                    answerPointer -> next = new struct ListNode(1);
                }
                break;
            }
            default:
                break;
        }
        return answer;
    }
};