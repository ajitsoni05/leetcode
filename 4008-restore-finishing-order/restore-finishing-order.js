/**
 * @param {number[]} order
 * @param {number[]} friends
 * @return {number[]}
 */
var recoverOrder = function(order, friends) {
    let friendsSet = new Set();
    friends.forEach((ele)=>{
        friendsSet.add(ele);
    })

    let friendsOrder = []

    order.forEach((ele) => {
        if(friendsSet.has(ele))friendsOrder.push(ele);
    })
    return friendsOrder;
};