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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n,-1));
        
        int top=0,left=0,bottom =m-1, right= n-1;
        int dir=1;
        
        while(left<=right && top<= bottom){
            
            if(dir==1){
                for(int j=left;j<=right && head;j++) {
                    ans[top][j]= head->val;
                    head= head->next;
                };
                if(!head) break;
                dir=2;
                top++;
            }
            
            else if(dir==2){
                for(int i=top;i<= bottom && head;i++){
                    ans[i][right]= head->val;
                    head= head->next;
                }
                if(!head) break;
                dir=3;
                right--;
            }
            
            else if(dir==3){
                for(int j = right;j>= left && head;j--){
                    ans[bottom][j]= head->val;
                    head= head->next;
                }
                if(!head) break;
                dir=4;
                bottom--;
            }
            else if(dir==4){
                for(int i= bottom;i>= top && head; i--){
                    ans[i][left]= head->val;
                    head= head->next;
                }
                if(!head) break;
                dir=1;
                left++;
            }
            
        }
        // for(auto &i: ans){
        //     for(auto & j: i)
        //         cout<<j<<" ";
        //     cout<<endl;
        // }
        return ans;
    }
};