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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<ListNode*> map;
        ListNode* root = head;
        while(root)
        {
            map.push_back(root);
            root = root-> next;
        }
        int n = map.size();
        if(n == 1)
            return head;
        if(n%2 == 1 && k-1 == n/2)
            return head;
        
        ListNode* tmp = map[n-k];
        map[n-k] = map[k-1];
        map[k-1] = tmp;
        map[n-k]->next = NULL;
        map[k-1]->next = NULL;
        
        if(k-2 != -1)
            map[k-2]->next = map[k-1];
        if(k != n)
            map[k-1]->next = map[k];
        if(n-k-1 != -1)
            map[n-k-1]->next = map[n-k];
        if(n-k+1 != n)
            map[n-k]->next = map[n-k+1];
        
        return map[0];

    }
};