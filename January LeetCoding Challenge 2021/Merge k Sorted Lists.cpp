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
    static bool compare(ListNode* a, ListNode* b)
    {
        if(a->val < b-> val)
            return true;
        else 
            return false;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        
        vector<ListNode*> reorder;
        for(int i = 0 ; i < lists.size(); ++i)
        {
            ListNode* root = lists[i];
            while(root != NULL)
            {
                reorder.push_back(root);
                root = root->next;
            }
        }
        if(reorder.size() == 0)
            return NULL;
        sort(reorder.begin(), reorder.end(), compare);
        for(int i = 0 ; i < reorder.size() ; ++i)
            reorder[i]->next = NULL;
        for(int i = 0 ; i < reorder.size()-1  ; ++i)
        {
            reorder[i]->next = reorder[i+1];
        }
        return reorder[0];
    }
};