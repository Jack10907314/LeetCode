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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode*> tmp;
        while(headA)
        {
            tmp.push_back(headA);
            headA = headA->next;
        }
        
        while(headB)
        {
            if(find(tmp.begin(), tmp.end(), headB) != tmp.end())
                return headB;
            headB = headB -> next;
        }
        return NULL;
    }
};