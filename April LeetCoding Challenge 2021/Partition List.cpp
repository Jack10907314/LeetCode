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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;

        vector<ListNode*> large;
        vector<ListNode*> little;
        while(head){
            if(head->val < x){
                if(little.size() > 0){
                    little.back()->next = head;
                }
                little.push_back(head);
            }
            else{
                if(large.size() > 0){
                    large.back()->next = head;
                }
                large.push_back(head);
            }
            
            head = head->next;
        }
        
        if(large.size() > 0){
            large.back()->next = NULL;
        }
        if(little.size() > 0 && large.size() == 0){
            little.back()->next = NULL;
        }
        if(little.size() > 0 && large.size() > 0){
            little.back()->next = large[0];
        }
        
        return little.size()>0 ? little[0] : large[0];
    }
};