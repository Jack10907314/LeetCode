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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        vector<ListNode*> map;
        ListNode* tmp = head;
        while(tmp){
            map.push_back(tmp);
            tmp = tmp->next;
        }

        reverse(map.begin()+left-1, map.begin()+right);

        for(int i = 0; i < map.size()-1; ++i){
            map[i]->next = map[i+1];
        }
        map.back()->next = NULL;
        return map[0];
    }
};