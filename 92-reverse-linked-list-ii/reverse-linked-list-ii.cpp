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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<ListNode*>temp;

        while(head){
            ListNode*t= head;
            head=head->next;
            t->next = NULL;

            temp.push_back(t);
        }
        reverse(temp.begin()+left-1,temp.begin()+right);
        head = temp[0];
        ListNode*t = head;

        for(int i=1;i<temp.size();i++){
            ListNode*t2 = temp[i];
            t->next = t2;
            t=t->next;
        }
        return head;
    }
};