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
    int nextGreater(ListNode* head){
        if(!head)return 0;
        int val = head->val;
        ListNode* temp = head;

        while(temp and temp->val <= val)temp = temp->next;

        if(temp)return temp->val;

        return 0;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        
        vector<int>nextGreaterEle;

        ListNode* temp = head;
        
        while(temp) {
            int nex = nextGreater(temp);
            nextGreaterEle.push_back(nex);
            temp = temp->next;
       
        }

        return nextGreaterEle;

    }
};