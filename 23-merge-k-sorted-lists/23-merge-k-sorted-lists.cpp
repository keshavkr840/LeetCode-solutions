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
class Solution {
public:
     struct comp
    {
        bool operator()(ListNode* a, ListNode *b)
        {
            return a->val > b->val;   // min heap  
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        
        // bool comp= [&](ListNode* a, ListNode *b){
        //     return a->val > b->val;
        // };
        priority_queue< ListNode*, vector<ListNode*>, comp> pq;
        
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=nullptr)
                pq.push(lists[i]);
        }
        
        ListNode dummy (0);
        ListNode * node = &dummy;
        
        while(!pq.empty()){
            ListNode* curr= pq.top();
            pq.pop();
            
            // ListNode* t = new ListNode(curr->val);
            node->next = curr;
            node= node->next;
            
            if(curr->next) pq.push(curr->next);
        }
        
        return dummy.next;
    }
};