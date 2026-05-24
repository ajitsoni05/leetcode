/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */

var _gcd = function(a,b){
    if(b === 0) return a;
    return _gcd(b,a%b);
}
var insertGreatestCommonDivisors = function(head) {
    let iterator = head;
    while(iterator.next) {
        let gcd = _gcd(iterator.val,iterator.next.val);
        let insertedNode = new ListNode(gcd);
        let temp = iterator.next;
        iterator.next = insertedNode;
        insertedNode.next = temp;
        iterator = insertedNode.next;
    }
    return head;
};