/**
 * @param {number[]} order
 * @param {number[]} friends
 * @return {number[]}
 */
var recoverOrder = function(order, friends) {
    let friendsSet = new Set();
    friends.forEach((ele) => {
        friendsSet.add(ele);
    })

    // replace forEach with for to avoid function call overhead
    for(let i = 0; i < friends.length; i++) {
         friendsSet.add(friends[i]);
    }

    let friendsOrder = []

    for(let i = 0; i < order.length; i++){
        if(friendsSet.has(order[i]))friendsOrder.push(order[i]);
    }
    return friendsOrder;
};