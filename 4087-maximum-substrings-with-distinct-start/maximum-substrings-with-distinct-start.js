/**
 * @param {string} s
 * @return {number}
 */
var maxDistinct = function(s) {
    let charMap = new Map();

    let count = 0;
    [...s].forEach((ele) => {
       if(charMap.get(ele)){
        // do nothing
       }else{ charMap.set(ele,1);
        count++;
       }

    })
    return count;


};