#define Node ListNode
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        bool flagA= false, flagB=0;
        Node *a = headA, *b= headB;
        
        while(a && b){
            if(a==b) return a;
            
            a= a->next;
            b= b->next;
            
            if(a==nullptr && !flagA){ a= headB; flagA= true;}
            if(b==nullptr && !flagB){ b= headA; flagB=true;}
            
        }
        return nullptr;
    }
};