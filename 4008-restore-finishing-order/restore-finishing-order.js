/**
 * @param {number[]} order
 * @param {number[]} friends
 * @return {number[]}
 */
var recoverOrder = function(order, friends) {
    let friendsMap = new Map();
    friends.forEach((ele)=>{
        friendsMap.set(ele,1)
    })

    let friendsOrder = []

    order.forEach((ele) => {
        if(friendsMap.has(ele))friendsOrder.push(ele);
    })
    return friendsOrder;
};