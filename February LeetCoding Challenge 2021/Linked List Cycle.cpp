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
        vector<ListNode*> list;
        while(head != NULL)
        {
            if(find(list.begin(), list.end(), head) != list.end())
                return true;
            list.push_back(head);
            head = head->next;
        }
        return false;
    }
};