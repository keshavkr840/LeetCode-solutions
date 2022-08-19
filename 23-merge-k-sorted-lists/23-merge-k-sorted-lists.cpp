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
    Node* merge2Lists(Node* a, Node* b){
        if(a==nullptr) return b;
        else if(b==nullptr) return a;
        
        else if(a->val <= b->val){
            a->next = merge2Lists(a->next, b);
            return a;
        }
        else{
            b->next = merge2Lists(a, b->next);
            return b;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0 ) return nullptr;
        int rem =n;
        while(rem>1){
            for(int i=0;i<rem/2;i++){
                lists[i]= merge2Lists(lists[i], lists[rem-1-i]);
            }
            rem= (rem+1)/2;
        }
            
        return lists.front();
    }
};
// class Solution {
// public:
//     ListNode *mergeTwoLists(ListNode* l1, ListNode* l2) {
//         if (NULL == l1) return l2;
//         else if (NULL == l2) return l1;
//         if (l1->val <= l2->val) {
//             l1->next = mergeTwoLists(l1->next, l2);
//             return l1;
//         }
//         else {
//             l2->next = mergeTwoLists(l1, l2->next);
//             return l2;
//         }
//     }
//     ListNode *mergeKLists(vector<ListNode *> &lists) {
//         if (lists.empty()) return NULL;
//         int len = lists.size();
//         while (len > 1) {
//             for (int i = 0; i < len / 2; ++i) {
//                 lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
//             }
//             len = (len + 1) / 2;
//         }
        
//         return lists.front();
//     }
// };