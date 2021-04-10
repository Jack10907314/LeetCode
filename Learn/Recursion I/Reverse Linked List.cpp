/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* recursive(ListNode* head)
    {
        if(!head || !head->next)
            return head;
        ListNode* reverse = recursive(head->next);
        reverse->next = head;
        head->next = NULL;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        //literatively
        /*ListNode* reverse = NULL;
        while(head)
        {
            ListNode* next = head->next;
            head->next = reverse;
            reverse = head;
            head = next;
        }
        return reverse;*/
        
        //recursively
        ListNode* lastNode = head;
        while(lastNode && lastNode->next)
            lastNode = lastNode->next;
        recursive(head);
        return lastNode;
        
    }
};