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
    
    ListNode* merge2Lists(ListNode* a, ListNode* b){
        ListNode dummy(0);
        ListNode* node= &dummy;
        
        while(a && b){
            if(a->val <= b->val){
                node->next =a;
                a= a->next;
            }
            else{
                node->next =b;
                b= b->next;
            }
            node= node->next;
        }
        if(a)
            node->next = a;
        else
            node->next = b;
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size()==0) return nullptr;
        int rem =lists.size();
        
        while(rem>1){
            for(int i=0;i<rem/2;i++){
                lists[i]= merge2Lists(lists[i], lists[rem-1-i]);
            }
            rem= (rem+1)/2;
        }
            
        return lists.front();
    }
};
