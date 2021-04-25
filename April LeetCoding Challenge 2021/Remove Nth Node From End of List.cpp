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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto ans = head;
        int size = 0;
        deque<ListNode*> q;
        while(head){
            ++size;
            if(q.size() < n+1){
                q.push_back(head);
            }
            else{
                q.push_back(head);
                q.pop_front();
            }
            head = head->next;
        }
        
        if(size == 1)
            return NULL;
        else if(size == n){
            ans = ans->next;
        }
        else if(n==1){
            auto it = q[q.size()-2];
            it->next = NULL;
        }
        else{
            q[q.size()-n-1]->next = q[q.size()-n+1];
        }
        return ans;
    }
};