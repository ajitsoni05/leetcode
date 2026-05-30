/**
 * @param {string} s
 * @return {number[]}
 */
var goodIndices = function(s) {
    
    let ans = []
    for(let i = 0; i < s.length; i++){
        let num = i;
        let it = i;
        let enteredLoop = false;
        while(Number(s[it--]) === num%10){
            num = Math.trunc(num/10)
            enteredLoop = true
        }
        if(num === 0 && enteredLoop) ans.push(i); 
    }
    return ans;


};