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
        unordered_map<Node*, int> map;
        
        Node *a= headA, *b = headB;
        
        while(a ||b){
            if(a){
                if(map[a]) return a;
                else map[a]++;
                a= a->next;
            }
            if(b){
                if(map[b]) return b;
                else map[b]++;
                b = b->next;
            }
        }
        
        return nullptr;
    }
};