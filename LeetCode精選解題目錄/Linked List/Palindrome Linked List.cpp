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
    bool isPalindrome(ListNode* head) {
        int n = 0;
        ListNode* root = head;
        ListNode* last = head;
        while(root != NULL)
        {
            last = root;
            root = root->next;
            ++n;
        }
        
        ListNode* previous = head;
        ListNode* next = head;
        ListNode* now = head;
        for(int i = 0; i < n; ++i)
        {
            next = now->next;
            if(i == n/2 - 1)
                now->next = NULL;
            if(i > n/2)
                now->next = previous;
            previous = now;
            now = next;
        }
        
        for(int i = 0 ; i < n/2 ; ++i)
        {
            if(head->val != last->val)
                return false;
            head = head->next;
            last = last->next;
        }
        
        return true;
    }
};