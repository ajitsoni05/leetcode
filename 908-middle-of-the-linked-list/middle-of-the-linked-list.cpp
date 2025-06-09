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
    ListNode* middleNode(ListNode* head) {
        // slow and fast
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next and slow){
            slow = slow ->next;
            fast = fast ->next;
            if(fast and fast->next)fast = fast->next;
        }

        return slow;
    }
};