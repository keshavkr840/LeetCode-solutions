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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        Node dummy(0);
        
        Node *curr= head, *prev= &dummy;
        int data;
        
        while(curr){
            
            if(curr->next && curr->next->val== curr->val){
                data= curr->val;
                while(curr && (curr->val== data))
                    curr= curr->next;
            }
            else{
                prev->next = new Node(curr->val);
                prev= prev->next;
                curr= curr->next;
            }
        }
        return dummy.next;
    }
};