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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        Node dummy(0);
        dummy.next = head;
        Node *slow= &dummy, *fast= head;
        int i=1;
        
        while(fast->next){
            if(i<n) i++;
            else slow= slow->next;
            
            fast= fast->next;
        }
        slow->next= slow->next->next;
        
        return dummy.next;
        
    }
};