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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||k==0)return head;
        int len=0;
        ListNode*temp=head;
        ListNode*tail=NULL;
        while(temp){
            if(temp->next==NULL)tail=temp;
            temp=temp->next;
            len++;
        }
        k=k%len;
        int leftlen=len-k;
        temp=head;
        while(leftlen>1){
            temp=temp->next;
            leftlen--;
        }
          tail->next=head;
    head=temp->next;
    temp->next=NULL;
    return head;
    }
  
};