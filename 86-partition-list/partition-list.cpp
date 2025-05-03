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
    ListNode* partition(ListNode* head, int x) {
        vector<ListNode*>less ;
        vector<ListNode*>big ;

        ListNode* temp = head;
        while(temp){
            if(temp->val < x)less.push_back(temp);
            else{
                big.push_back(temp);
            }
            temp=temp->next;
        }

        ListNode* ans = new ListNode();
        ListNode* temp2  = ans;
        int iter = 0;
        while(iter < less.size()){
            ListNode* t = less[iter];
            t->next = NULL;
            temp2->next = t;
            temp2 = temp2 -> next;
            iter++;
        }
        iter = 0;
         while(iter < big.size()){
            ListNode* t = big[iter];
            t->next = NULL;
            temp2->next = t;
            temp2 = temp2 -> next;
            iter++;

        }

        return ans->next;

    
    }
};