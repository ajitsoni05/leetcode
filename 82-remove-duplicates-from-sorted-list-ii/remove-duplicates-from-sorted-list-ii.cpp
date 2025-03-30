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
    ListNode* deleteDuplicates(ListNode* head) {
        vector<ListNode*> array; map<int, int> mp;
        while (head) {
            mp[head->val]++;
            head = head->next;
        }

        ListNode*temp = new ListNode(-1);
        ListNode*temp2 = temp;
        for(auto it:mp){

            if(it.second == 1){
                ListNode*temp3 = new ListNode(it.first);
                temp2->next = temp3;
                temp2=temp2->next;
            }
        }
        return temp->next;
    }
};