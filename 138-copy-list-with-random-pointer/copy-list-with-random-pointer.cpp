/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>nm;

        Node*temp=head;

        while(temp){
            Node*cnode=new Node(temp->val);
            nm[temp]=cnode;
            temp=temp->next;
        }

        temp=head;
        while(temp){
            Node*cnode=nm[temp];
            cnode->next=nm[temp->next];
            cnode->random=nm[temp->random];
            temp=temp->next;
        }
        return nm[head];
    }
};