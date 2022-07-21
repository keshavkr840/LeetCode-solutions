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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left== right) return head;
        Node *curr= head, *stop= nullptr, *nxt, *prev=nullptr;
        
        int i=1;
        while(left>i){
            stop = curr;
            curr= curr->next;
            i++;
        }
        while(right>=i){
            nxt = curr->next;
            curr->next = prev;
            prev=curr;
            curr= nxt;
            i++;
        }
        
        if(left==1){
            head->next = curr;
            head = prev;
        }
        else{
            Node *stop2= stop->next;
            stop2->next = curr;
            stop->next = prev;
        }
        
        
        
        return head;
    }
};