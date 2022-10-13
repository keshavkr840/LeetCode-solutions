/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define Node ListNode
class Solution {
public:
    void deleteNode(ListNode* node) {
        Node* nxt = node->next;
        node->val = nxt->val;
        node->next = nxt->next;
        delete(nxt);
    }
};