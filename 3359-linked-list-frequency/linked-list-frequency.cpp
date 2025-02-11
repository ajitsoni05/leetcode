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
    ListNode* frequenciesOfElements(ListNode* head) {
        // get the frequency map
        // construct the linked list

        unordered_map<int,int>mp;
        while(head){
            mp[head->val]++;
            head=head->next;
        }

        ListNode* ans = new ListNode();
        ListNode* tmp=ans;
        for(auto it:mp){
            ListNode*temp = new ListNode(it.second);
            tmp->next=temp;
            tmp=tmp->next;
        }
        return ans->next;
    }
};