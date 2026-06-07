/**
 * @param {number} n
 * @return {number}
 */

var digitFrequencyScore = function(n) {
    let freqMap = new Map()

    while(n){
        let dig = n%10;
        
        let val = freqMap.get(dig);

        if(val){
            freqMap.set(dig,val+1);
        }else{
            freqMap.set(dig,1);
        }
        n = Math.trunc(n/10)
    }

    let total = 0
    for([key,val] of freqMap){
        total += key*val
    }
    return total
};