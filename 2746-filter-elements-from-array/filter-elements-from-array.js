/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    
    let filteredAr = []

    for(let i=0;i<arr.length;i++){
        if(fn(arr[i],i)){
            filteredAr.push(arr[i])
        }
    }
    return filteredAr
};