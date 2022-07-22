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
#define Node ListNode
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        Node node(0);
        node.next = head;
        
        Node * curr=head, * prev = &node, *hold= &node, *nxt;
        bool flag = false, shuffle= false;
        
        while(curr){
            nxt = curr->next;
            
            if(curr->val>=x) flag = true;
            
            if(flag && curr->val<x){
                prev->next = curr->next;
                curr->next= hold->next;
                hold->next = curr;
                hold= hold->next;
                shuffle = true;
            }
            
            if(!flag) hold= hold->next;
            if(!shuffle) prev= curr;
            curr= nxt;
            shuffle = false;
        }
        return node.next;
    }
};