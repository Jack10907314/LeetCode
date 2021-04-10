/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        
        Node* myhead = new Node(head->val);
        Node* tmp_head = head;
        Node* tmp_myhead = myhead;
        unordered_map<Node*, Node*> hash;
        hash[head] = myhead;
        
        while(tmp_head->next != NULL)
        {
            tmp_head = tmp_head->next;
            tmp_myhead->next = new Node(tmp_head->val);
            tmp_myhead = tmp_myhead->next;
            hash[tmp_head] = tmp_myhead;
        }
        
        tmp_head = head;
        tmp_myhead = myhead;
        while(tmp_head != NULL)
        {
            tmp_myhead->random = hash[tmp_head->random];
            tmp_myhead = tmp_myhead->next;
            tmp_head = tmp_head->next;
        }
        return myhead;
    }
};